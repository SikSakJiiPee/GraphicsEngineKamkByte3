#pragma once
#include "../../AllIncludes/ALLIncludes.cpp"
#include "../Container/ObjectContainer.h"
class DrawMovement
{
public:
	DrawMovement(){};
	~DrawMovement(void){};

	void MoveObject(std::string name, ObjectContainer* Access,char Input);
	void MoveCamera(ObjectContainer* Access, char Input);


};

