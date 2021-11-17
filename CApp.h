#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include <array>
#include "Turtle.h"
#include "snowflakeGenerator.h"
#include "snowflakeInitiator.h"

class CApp
{
	public:
		CApp();

		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event* event);
		void OnLoop();
		void OnRender();
		void OnExit();

	private:
		bool isRunning;
		SDL_Window* pWindow;
		SDL_Renderer* pRenderer;
    
    Turtle m_turtle;
    snowflakeGenerator m_snowflakeGenerator;
    snowflakeInitiator m_snowflakeInitiator;
  
    void DrawEdge(float x1, float y1, float x2, float y2, int level);

    std::array<int, 3> m_redList    {51,  255,  255};
    std::array<int, 3> m_greenList  {128, 128,  191};
    std::array<int, 3> m_blueList   {204, 0,    0};
};

#endif
