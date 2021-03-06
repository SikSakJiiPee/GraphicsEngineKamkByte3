#pragma once

#include "..\..\Plugins\GLM\glm\glm.hpp"
#include "../AllIncludes/AllIncludes.cpp"
#include <unordered_map>
#include "../ObjectRelatives/Container/ObjectContainer.h"
#include "../ObjectRelatives/Movement/DrawMovement.h"


class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update();

	void pressKey(unsigned int keyID);
	void releaseKey(unsigned int keyID);

	void setMouseCoords(float x, float y);

	//palauttaa true jos nappi on pohjassa
	bool isKeyDown(unsigned int keyID);

	//palauttaa true jos nappia juuri painettiin
	bool isKeyPressed(unsigned int keyID);

	void Process(ObjectContainer* Access,DrawMovement* move);


	//getterit
	glm::vec2 getMouseCoords() const { return mouseCoords; }

private:
	//palauttaa true jos nappi oli pohjassa viime framella
	bool wasKeyDown(unsigned int keyID);
	
	std::unordered_map<unsigned int, bool> keyMap;
	std::unordered_map<unsigned int, bool> previousKeyMap;
	glm::vec2 mouseCoords;
	

};

