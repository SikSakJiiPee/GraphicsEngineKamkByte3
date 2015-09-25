#pragma once

#include "..\AllIncludes\AllIncludes.cpp"

class WindowCreation
{
public:
	WindowCreation(){};
	~WindowCreation(void){};
	int makeNewWindow(int argc, char* argv[]);
private:
	bool keepWindowOpen;
};

