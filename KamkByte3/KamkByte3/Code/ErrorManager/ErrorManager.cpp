#include "ErrorManager.h"

#include <cstdlib>
#include <iostream>

#include "../../Plugins/SDL/include/SDL.h"

//Tulostaa virheviestin ja lopettaa ohjelman
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(99);
}