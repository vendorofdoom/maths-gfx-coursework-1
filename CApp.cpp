#include "CApp.h"

CApp::CApp()
{
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
  windowX = 600;
  windowY = 500;
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
  
  // Initialise L-system from first config file
  m_lsystem.LoadFromFile("9");
  m_lsystem.ComputeTurtleInstructions();
  m_lsystem.ChangeRoot(windowX, windowY);
  DrawLSystem();

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
  m_turtle.AssumeStartPosition(m_lsystem.GetRootX(), m_lsystem.GetRootY());
  m_turtle.SetLength(m_lsystem.GetLineLength());

  //std::cout << m_lsystem.GetInstructions() << std::endl;

  // Instruct turtle to draw the L-System 
  for(char c : m_lsystem.GetInstructions()) {

  switch(c) 
    {
      case 'F': case 'G':
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
        m_turtle.SetPenColour(reds[level%reds.size()], blues[level%blues.size()], greens[level%greens.size()], 255);

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
        // Increase line length
        m_lsystem.IncrementLineLength();
        std::cout << "Line length: " << std::to_string(m_lsystem.GetLineLength()) << std::endl;
        break;
      }
      case SDLK_DOWN:
      {
        // Decrease line length
        m_lsystem.DecrementLineLength();
        std::cout << "Line length: " << std::to_string(m_lsystem.GetLineLength()) << std::endl;
        break;
      }
      case SDLK_RIGHT:
      {
        // Increase numIter
        m_lsystem.IncrementIterations();
        std::cout << "Num Iters: " << std::to_string(m_lsystem.GetNumIterations()) << std::endl;
        break;
      }
      case SDLK_LEFT:
      {
        // Decrease numIter
        m_lsystem.DecrementIterations();
        std::cout << "Num Iters: " << std::to_string(m_lsystem.GetNumIterations()) << std::endl;
        break;
      }
      case SDLK_RIGHTBRACKET:
      {
        // Increase angle
        m_lsystem.IncrementAngle();
        std::cout << "Angle: " << std::to_string(m_lsystem.GetAngle()) << std::endl;
        break;
      }
      case SDLK_LEFTBRACKET:
      {
        // Decrease angle
        m_lsystem.DecrementAngle();
        std::cout << "Angle: " << std::to_string(m_lsystem.GetAngle()) << std::endl;
        break;
      }            
      case SDLK_1 ... SDLK_9:
      {
        // Load L-system from config file
        std::string fileNum (SDL_GetKeyName(event->key.keysym.sym));
        m_lsystem.LoadFromFile(fileNum);
        break;
      }
      case SDLK_LSHIFT: case SDLK_RSHIFT:
      {
        // Toggle root location
        m_lsystem.ChangeRoot(windowX, windowY);
        std::cout << "Toggle root location" << std::endl;
      }
      case SDLK_PERIOD:
      {
        // Increase rand seed
        m_lsystem.IncrementRandSeed();
        std::cout << "Rand seed: " << std::to_string(m_lsystem.GetRandSeed()) << std::endl;
        break;
      }
      case SDLK_COMMA:
      {
        // Decrease rand seed
        m_lsystem.DecrementRandSeed();
        std::cout << "Rand seed: " << std::to_string(m_lsystem.GetRandSeed()) << std::endl;
        break;
      } 
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