#include "WindowCreation.h"
#define PROGRAM_NAME "KamkByte3"
static const int width = 1024;
static const int height = 768;
//
int WindowCreation::makeNewWindow(int argc, char* argv[])
{

	SDL_Window *window;
	SDL_GLContext _windowsOpenGlContext;

	SDL_Init(SDL_INIT_VIDEO);
	//Alustetaan opengl.
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);



	window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	//SDL_SetWindowSize(window,);
	if (window == NULL) {

		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	//OpenGl liitetään ikkunaan.
	_windowsOpenGlContext = SDL_GL_CreateContext(window);
	//Bufferi synkronoi itsensä monitorin vertical synkin kanssa.
	SDL_GL_SetSwapInterval(1);


	RendererClass* Draw = new RendererClass();
	InputManager* Inputs = new InputManager();
	DrawMovement* Momentum = new DrawMovement();
	ObjectContainer* ObjectAccess = new ObjectContainer;
	ObjectAccess->loadContainerBin();
	//Looppi
	BOOLEAN running = TRUE;
	while (running != FALSE)
	{

	
		SDL_GL_SwapWindow(window);
		//Loopin rakenne.
		SDL_Event _engineRunningLoop;
		//Ikkunan tappo joko x tai esc.
		while (SDL_PollEvent(&_engineRunningLoop))
		{
			if (_engineRunningLoop.type == SDL_QUIT)
				running = false;
		

		switch (_engineRunningLoop.type)
		{
			/* Look for a keypress */
		case SDL_KEYDOWN:
		{
			// Send Key id to input manager.
			Inputs->pressKey(_engineRunningLoop.key.keysym.sym);
				break;
		}
			//SDL_KEYUP event for release

		case SDL_KEYUP:
		{
			Inputs->releaseKey (_engineRunningLoop.key.keysym.sym);
				break;
			}

		default:
			break;
		}
		}
		//Loopin Tehtävät.

		Inputs->Process(ObjectAccess,Momentum);

		Draw->init(window);
		Draw->display(window,ObjectAccess);

	}
	//ObjectAccess->saveContainerBin();

	//Tuhotaan Ikkuna.
	SDL_GL_DeleteContext(_windowsOpenGlContext);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
};

