#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::Update()
{
	//käydään keyMap läpi "for ecah" loopilla ja kopioidaan se previousKeyMappiin
	for (auto& it : keyMap)
	{
		previousKeyMap[it.first] = it.second;
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