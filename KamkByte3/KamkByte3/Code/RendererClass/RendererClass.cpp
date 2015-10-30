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

void RendererClass::display(SDL_Window* WinMain)
{

	ObjectMold* Access=new ObjectMold;
	

	Access->setLocationPoints(-0.325f, -0.5f, -0.325f, 0.5f, 0.325f, 0.5f, 0.325f, 0.5f, -0.325f, -0.5f, 0.325f, -0.5f, 1.0f, 1.0f);

	SDL_GL_SwapWindow(WinMain);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(Access->getLocationPoint(0), Access->getLocationPoint(1), Access->getLocationPoint(12));
	glVertex3f(Access->getLocationPoint(2), Access->getLocationPoint(3), Access->getLocationPoint(12));
	glVertex3f(Access->getLocationPoint(4), Access->getLocationPoint(5), Access->getLocationPoint(12));

	glVertex3f(Access->getLocationPoint(6), Access->getLocationPoint(7), Access->getLocationPoint(12));
	glVertex3f(Access->getLocationPoint(8), Access->getLocationPoint(9), Access->getLocationPoint(12));
	glVertex3f(Access->getLocationPoint(10), Access->getLocationPoint(11), Access->getLocationPoint(12));

	glEnd();
}
