#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include <array>
#include "Turtle.h"
#include "LSystem.h"
#include <iostream>
#include <vector>


class CApp
{
	public:
		CApp();

		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event* event);
		void OnExit();

	private:
		bool isRunning;
		SDL_Window* pWindow;
		SDL_Renderer* pRenderer;

    int windowX;
    int windowY;
    
    Turtle m_turtle;
    LSystem m_lsystem;

    void DrawLSystem();

    std::array<int, 6> reds =   {252, 236,  86,   3,    3,    148};
    std::array<int, 6> greens = {186, 252,  252,  252,  53,   3};
    std::array<int, 6> blues =  {3,   3,    3,    240,  252,  252};

    void DrawForest();

};

#endif
