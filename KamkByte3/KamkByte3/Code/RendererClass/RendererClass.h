#pragma once
#include "..\AllIncludes\AllIncludes.cpp"
#include "../ObjectRelatives/Container/ObjectContainer.h"
//
class RendererClass
{
public:
	RendererClass();
	~RendererClass();

	void init(SDL_Window* WinMain);
	void display(SDL_Window* WinMain, ObjectContainer* Access);

};

