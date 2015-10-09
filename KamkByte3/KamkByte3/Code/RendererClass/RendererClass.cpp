#include "RendererClass.h"


RendererClass::RendererClass()
{
}

RendererClass::~RendererClass()
{
}

void RendererClass::init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 640.0 / 480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

}

void RendererClass::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 2.0, -5.0);
	glVertex3f(-2.0, -2.0, -5.0);
	glVertex3f(2.0, 2.0, -5.0);

	glEnd();
}
