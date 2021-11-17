#include "CApp.h"
#include <iostream>
#include <vector>

CApp::CApp()
{
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
}

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	pWindow = SDL_CreateWindow("L-System Turtle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 600, SDL_WINDOW_SHOWN);

	if (pWindow != NULL) {
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	}
	else
	{
		return false;
	}

  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);

  //std::cout << m_lsystem.GetInstructions() << std::endl;

  m_turtle.SetRenderer(pRenderer);
  
  DrawLSystem();

  SDL_RenderPresent(pRenderer);
  
	return true;
}

void CApp::DrawLSystem(){

  m_turtle.MoveTo(320, 590);
  m_turtle.SetAngle(300.0f);
  m_turtle.PenDown();
  m_turtle.SetLength(1);

  std::vector<float> xStack;
  std::vector<float> yStack;
  std::vector<float> angleStack;

  int maxLevel = 0;

  // TODO: add colour based on stack level?
  int level = 0;
  m_turtle.SetPenColour(reds[level%6], blues[level%6], greens[level%6], 255);

  m_lsystem.ComputeTurtleInstructions();

  for(char c : m_lsystem.GetInstructions()) {

  switch(c) 
    {
      case 'F':
        // draw forwards
        m_turtle.Step();
        break;

      case '+':
        // turn left
        m_turtle.RotateLeft(m_lsystem.GetAngle());
        break;

      case '-':
        // turn right
        m_turtle.RotateRight(m_lsystem.GetAngle());
        break;

      case '[':

        // push orientation
        xStack.push_back(m_turtle.GetX());
        yStack.push_back(m_turtle.GetY());
        angleStack.push_back(m_turtle.GetAngle());

        level++;
        if (level > maxLevel) {
          maxLevel = level;
        }
        m_turtle.SetPenColour(reds[level%6], blues[level%6], greens[level%6], 255);

        break;

      case ']':

        // pop and restore orientation
        // TODO: what if nothing to pop?
        m_turtle.PenUp();

        m_turtle.MoveTo(xStack.back(), yStack.back());
        xStack.pop_back();
        yStack.pop_back();

        m_turtle.SetAngle(angleStack.back());
        angleStack.pop_back();

        m_turtle.PenDown();

        level--;

        break;
    }

  }

  std::cout << maxLevel << std::endl;

}


int CApp::OnExecute()
{
	SDL_Event event;

	if (OnInit() == false) {
		return -1;
	}

	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}

		OnLoop();
		OnRender();
	}

	OnExit();
	return 0;
}


void CApp::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{

}

void CApp::OnExit()
{
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}