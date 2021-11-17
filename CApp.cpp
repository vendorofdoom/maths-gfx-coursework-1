#include "CApp.h"
#include <array>
#include <math.h>
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

  m_snowflakeInitiator.AddVertex(120, 340);
  m_snowflakeInitiator.AddVertex(320, 40);
  m_snowflakeInitiator.AddVertex(520, 340);

  m_snowflakeGenerator.AddNode(60.0f);
  m_snowflakeGenerator.AddNode(-120.0f);

  SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
  float x1, y1, x2, y2;
  for (int i=0; i<m_snowflakeInitiator.NumEdges(); ++i)
  {
    if (m_snowflakeInitiator.GetEdge(&x1, &y1, &x2, &y2, i))
    {
      DrawEdge(x1, y1, x2, y2, 4);
    }
  }

  SDL_RenderPresent(pRenderer);

	return true;
}


void CApp::DrawEdge(float x1, float y1, float x2, float y2, int level)
{
  level--;
  
  std::vector<float> edgeX1;
  std::vector<float> edgeY1;
  std::vector<float> edgeX2;
  std::vector<float> edgeY2;

  float gx1, gy1, gx2, gy2;

  m_snowflakeGenerator.SetStartPoint(x1, y1);
  m_snowflakeGenerator.SetEndPoint(x2, y2);
  m_snowflakeGenerator.Compute();

  for (int j=0; j<m_snowflakeGenerator.NumEdges(); ++j)
  {
    if (m_snowflakeGenerator.GetEdge(&gx1, &gy1, &gx2, &gy2, j))
    {
      edgeX1.push_back(gx1);
      edgeY1.push_back(gy1);
      edgeX2.push_back(gx2);
      edgeY2.push_back(gy2);
    }

  }

  for (int j=0; j<m_snowflakeGenerator.NumEdges(); ++j)
  {
    if (level == 0)
    {
      SDL_RenderDrawLine(pRenderer,
        static_cast<int>(round(edgeX1[j])), static_cast<int>(round(edgeY1[j])),
        static_cast<int>(round(edgeX2[j])), static_cast<int>(round(edgeY2[j])));
    }
    else
    {
      DrawEdge(edgeX1[j], edgeY1[j], edgeX2[j], edgeY2[j], level);
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