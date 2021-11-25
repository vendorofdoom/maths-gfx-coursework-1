#include "CApp.h"

CApp::CApp()
{
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
  windowX = 600;
  windowY = 750;
}

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	pWindow = SDL_CreateWindow("L-System Turtle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowX, windowY, SDL_WINDOW_SHOWN);

	if (pWindow != NULL) {
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	}
	else
	{
		return false;
	}

  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);

  m_turtle.SetRenderer(pRenderer);
  
  // Initialise L-system from config file
  //m_lsystem.LoadFromFile("1");
  //m_lsystem.ComputeTurtleInstructions();

  //DrawLSystem();

  SDL_RenderPresent(pRenderer);
  
	return true;
}

void CApp::DrawLSystem()
{
  // stacks for handling '[' and ']'
  std::vector<float> xStack;
  std::vector<float> yStack;
  std::vector<float> angleStack;

  // level for handling colours
  int level = 0;
  m_turtle.SetPenColour(reds[0], blues[0], greens[0], 255);
  m_turtle.AssumeStartPosition(windowX / 2, windowY - 10);
  m_turtle.SetLength(m_lsystem.GetLineLength());

  //std::cout << m_lsystem.GetInstructions() << std::endl;

  // Instruct turtle to draw the L-System 
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
  else if (event->type == SDL_KEYDOWN)
  {

    // Clear screen in preparation for drawing something else
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    switch (event->key.keysym.sym) 
    {

      case SDLK_UP:
      {
        std::cout << "Arrow up" << std::endl;
        // Increase line length
        break;
      }
      case SDLK_DOWN:
      {
        std::cout << "Arrow down" << std::endl;
        // Decrease line length
        break;
      }
      case SDLK_RIGHT:
      {
        std::cout << "Arrow right" << std::endl;
        // Increase numIter
        break;
      }
      case SDLK_LEFT:
      {
        std::cout << "Arrow left" << std::endl;
        // Decrease numIter
        break;
      }
      case SDLK_PERIOD:
      {
        std::cout << "Full stop" << std::endl;
        // Decrease numIter
        break;
      }
      case SDLK_COMMA:
      {
        std::cout << "Comma" << std::endl;
        // Decrease numIter
        break;
      }            
      case SDLK_1 ... SDLK_8:
      {
        // Load L-system from config file
        std::string fileNum (SDL_GetKeyName(event->key.keysym.sym));
        m_lsystem.LoadFromFile(fileNum);
        break;
      }

      // TODO: Add option to shift root of drawing left / right? 

    }

    m_lsystem.ComputeTurtleInstructions();
    DrawLSystem();
    SDL_RenderPresent(pRenderer);

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