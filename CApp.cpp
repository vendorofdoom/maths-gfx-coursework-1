#include "CApp.h"


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

	pWindow = SDL_CreateWindow("Turtle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (pWindow != NULL) {
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	}
	else
	{
		return false;
	}

  Turtle m_turtle;
  m_turtle.MoveTo(320, 240);

  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);

  m_turtle.SetRenderer(pRenderer);
  m_turtle.PenDown();
  m_turtle.SetLength(150);

  std::array<float, 8> xTarget {0, 320, 640, 640, 640, 320, 0, 0};
  std::array<float, 8> yTarget {0, 0, 0, 240, 480, 480, 480, 240};

  for (int i=0; i<xTarget.size(); i++)
  {
    m_turtle.MoveTo(320, 240);
    m_turtle.SetPenColour(m_redList[i%3], m_greenList[i%3], m_blueList[i%3], 255);
    m_turtle.LookAt(xTarget[i], yTarget[i]);
    m_turtle.Step();
  }

  SDL_RenderPresent(pRenderer);

	return true;
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
	//SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	//SDL_RenderClear(pRenderer);

	//SDL_Rect fillRect = { 150, 120, 300, 200 };
	//SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(pRenderer, &fillRect);

	//SDL_RenderPresent(pRenderer);

}

void CApp::OnExit()
{
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}