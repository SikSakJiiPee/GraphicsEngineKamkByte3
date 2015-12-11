#include "RendererClass.h"

RendererClass::RendererClass()
{
}

RendererClass::~RendererClass()
{
}

void RendererClass::init(SDL_Window* WinMain)
{
	SDL_GL_SwapWindow(WinMain);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 640.0 / 480.0, 0.0,0.0);
	glMatrixMode(GL_MODELVIEW);

}

void RendererClass::display(SDL_Window* WinMain, ObjectContainer* Access)
{
	Access->containerDraw(WinMain);
	
	


}
