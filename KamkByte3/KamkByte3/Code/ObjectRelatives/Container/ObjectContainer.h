#pragma once
#include "../../AllIncludes/AllIncludes.cpp"
#include "../Mold/ObjectMold.h"
//
class ObjectContainer
{
public:
	ObjectContainer(){};
	~ObjectContainer(void){};

	void addObject(std::string name, ObjectMold* gameObject);
	void removeObject(std::string objectName );

	int getObjectCount();
	ObjectMold* getObject(std::string objectName);

	void saveContainerBin();
	void loadContainerBin();

	void containerDraw(SDL_Window* WinMain);
	void containerUpdateObjects(float inx,float iny,char obj,std::string name);

private:
	std::map<std::string, ObjectMold*>allObjects;
};

