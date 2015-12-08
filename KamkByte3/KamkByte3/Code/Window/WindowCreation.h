#pragma once

#include "..\AllIncludes\AllIncludes.cpp"
#include "..\RendererClass\RendererClass.h"
#include "..\ObjectRelatives\Container\ObjectContainer.h"

class WindowCreation
{
public:
	WindowCreation(){};
	~WindowCreation(void){};
	int makeNewWindow(int argc, char* argv[]);
private:
	bool keepWindowOpen;
};

