#pragma once

#include "Plugins\glew\include\GL\glew.h"


class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(int posX, int posY, int width, int height);

	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
};

