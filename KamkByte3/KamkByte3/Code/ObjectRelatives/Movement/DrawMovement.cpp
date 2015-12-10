#include "DrawMovement.h"


void DrawMovement::MoveObject(std::string name, ObjectContainer* Access, char Input)
{
	switch (Input)
	{
	case 'l':
	{
		Access->containerUpdateObjects(-0.1f,0.0f,'m',"player");
		break;
	}
	case 'r':
	{
		Access->containerUpdateObjects(0.1f, 0.0f, 'm', "player");
		break;
	}
	case 'u':
	{
		Access->containerUpdateObjects(0.0f, 0.1f, 'm', "player");
		break;
	}
	case 'd':
	{
		Access->containerUpdateObjects(0.0f, -0.1f, 'm', "player");
		break;
	}
	default:
		break;
	}
	
};
void DrawMovement::SpinObject(std::string name, ObjectContainer* Access, char Input)
{
	switch (Input)
	{
	case 'q':
	{
		break;
	}
	case 'e':
	{
		break;
	}
	default:
		break;
	}
};
void DrawMovement::MoveCamera(ObjectContainer* Access, char Input)
{

};