#include "WindowCreation.h"
#define PROGRAM_NAME "KamkByte3"
static const int width = 1024;
static const int height = 768;
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
	SDL_WINDOWPOS_CENTERED,width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS| SDL_WINDOW_RESIZABLE);
	//SDL_SetWindowSize(window,);
	if (window == NULL) {
		
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	//OpenGl liitet‰‰n ikkunaan.
	_windowsOpenGlContext = SDL_GL_CreateContext(window);
	//Bufferi synkronoi itsens‰ monitorin vertical synkin kanssa.
	SDL_GL_SetSwapInterval(1);



	
	
	//Looppi
	BOOLEAN running=TRUE;
	while (running != FALSE)
	{
	//Putsataan ruutu
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
	//Loopin tappo.
	SDL_Event _engineRunningLoop;
		while (SDL_PollEvent(&_engineRunningLoop))
		{
			switch (_engineRunningLoop.type)
			{
			case SDL_KEYDOWN:
				printf("Key press detected\n");
				switch (_engineRunningLoop.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = FALSE;
					break;

				default:
					break;
				}
				break;

			case SDL_KEYUP:
				printf("Key release detected\n");
				break;

			default:
				break;
			}
		}
		//Loopin Teht‰v‰t.

	}
	//Tuhotaan Ikkuna.
	SDL_GL_DeleteContext(_windowsOpenGlContext);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	return 0;
};