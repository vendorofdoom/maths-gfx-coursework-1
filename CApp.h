#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include <array>
#include "Turtle.h"

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

    std::array<int, 3> m_redList    {51,  255,  255};
    std::array<int, 3> m_greenList  {128, 128,  191};
    std::array<int, 3> m_blueList   {204, 0,    0};
};

#endif
