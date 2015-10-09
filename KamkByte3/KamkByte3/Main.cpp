#pragma comment (lib,"Plugins/SDL/lib/x86/SDL2")
#pragma comment (lib,"Plugins/SDL/lib/x86/SDL2main")
#pragma comment (lib,"Plugins/SDL/lib/x86/SDL2test")
#pragma comment (lib,"opengl32")
#include "Code\Window\WindowCreation.h"
#include "Code\AllIncludes\AllIncludes.cpp"

#undef main

int main(int argc, char* argv[])
{

	WindowCreation* newWin=new WindowCreation;
	newWin->makeNewWindow(argc,argv);


	return 0;
}

