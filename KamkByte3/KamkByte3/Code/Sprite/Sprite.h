#pragma once

#include "..\..\Plugins\glew\include\GL\glew.h"

#include <string>


class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float posX, float posY, float width, float height, std::string texturePath);

	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
};

