#pragma once
#include "../../AllIncludes/AllIncludes.cpp"
#include "../Mold/ObjectMold.h"

class ObjectContainer
{
public:
	ObjectContainer(){};
	~ObjectContainer(void){};

	void addObject(std::string type, std::string name, ObjectMold* gameObject);
	void removeObject(std::string objectName );

	int getObjectCount() const;
	ObjectMold* getObject(std::string objectName)const;

	void saveContainerBin();
	void loadContainerBin();

	void containerDraw();
	void containerUpdateObjects();

private:
	std::map<std::string, ObjectMold*>allObjects;
	std::map<std::string, ObjectMold*>::iterator id;
};

