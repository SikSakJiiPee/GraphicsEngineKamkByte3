#include "ObjectContainer.h"


void ObjectContainer::addObject(std::string type, std::string name, ObjectMold* gameObject)
{

	allObjects.insert(std::pair<std::string, ObjectMold*>(name, gameObject));

}

void ObjectContainer::removeObject( std::string objectName)
{
	std::map<std::string, ObjectMold*>::iterator results = allObjects.find(objectName);
	if (results != allObjects.end())
	{
		delete results->second;
		allObjects.erase(results);
	}

}


int ObjectContainer::getObjectCount() const
{
	return allObjects.size();
}

ObjectMold* ObjectContainer::getObject(std::string objectName)const
{
	std::map<std::string, ObjectMold*>::const_iterator results = allObjects.find(objectName);
	if (results == allObjects.end())
	{
		return NULL;
	}
	return results->second;

}


void ObjectContainer::saveContainerBin()
{


}

void ObjectContainer::loadContainerBin()
{


}


void ObjectContainer::containerDraw()
{


}

void ObjectContainer::containerUpdateObjects()
{


}
