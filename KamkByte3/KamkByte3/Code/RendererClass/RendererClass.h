#pragma once
#include "..\AllIncludes\AllIncludes.cpp"
class RendererClass
{
public:
	RendererClass();
	~RendererClass();
	void render();
	void init(SDL_Window* WinMain);
	void display(SDL_Window* WinMain);
};

