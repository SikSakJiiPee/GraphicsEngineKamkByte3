#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::Update()
{
	//käydään keyMap läpi "for each" loopilla ja kopioidaan se previousKeyMappiin
	for (auto& it : keyMap)
	{
		previousKeyMap[it.first] = it.second;
		isKeyPressed(it.second);
	}
}

void InputManager::pressKey(unsigned int keyID)
{
	keyMap[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID)
{
	keyMap[keyID] = false;
}

bool InputManager::isKeyDown(unsigned int keyID)
{
	auto it = keyMap.find(keyID);
	if (it != keyMap.end())
	{
		return it->second;
	}
	else
	{
		return false;
	}
}

bool InputManager::isKeyPressed(unsigned int keyID)
{
	bool isPressed;
	if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false)
	{
		return true;
	}
	return false;
}

bool InputManager::wasKeyDown(unsigned int keyID)
{
	auto it = keyMap.find(keyID);
	if (it != keyMap.end())
	{
		return it->second;
	}
	else
	{
		return false;
	}
}

void InputManager::Process(ObjectContainer* Access,DrawMovement* move)
{
	
	if (isKeyDown(SDLK_w))
	{
		move->MoveObject("Player", Access, 'u');
	}
	if (isKeyDown(SDLK_s))
	{
		move->MoveObject("Player", Access, 'd');
	}
	if (isKeyDown(SDLK_d))
	{
		move->MoveObject("Player", Access, 'r');
	}
	if (isKeyDown(SDLK_a))
	{
		move->MoveObject("Player", Access, 'l');
	}
	if (isKeyDown(SDLK_e))
	{
		move->MoveObject("Player", Access, 'e');
	}
	if (isKeyDown(SDLK_q))
	{
		move->MoveObject("Player", Access, 'q');
	}
	if (isKeyDown(SDLK_z))
	{
		move->MoveObject("Player", Access, 'b');
	}

	if (isKeyDown(SDLK_x))
	{
		move->MoveObject("Player", Access, 's');
	}


}