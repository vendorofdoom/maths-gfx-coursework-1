#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include <array>
#include "Turtle.h"
#include "LSystem.h"

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

    void DrawLSystem();

	private:
		bool isRunning;
		SDL_Window* pWindow;
		SDL_Renderer* pRenderer;
    
    Turtle m_turtle;
    LSystem m_lsystem;

};

#endif
