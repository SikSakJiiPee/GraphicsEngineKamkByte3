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
	case 'q':
	{
		Access->containerUpdateObjects(0.1f, 0.0f, 'r', "player");
		break;
	}
	case 'e':
	{
		Access->containerUpdateObjects(-0.1f, 0.0f, 'r', "player");
		break;
	}
	case 'b':
	{
		Access->containerUpdateObjects(0.01f, 0.0f, 's', "player");
		break;
	}
	case 's':
	{
		Access->containerUpdateObjects(-0.01f, 0.0f, 's', "player");
		break;
	}
	default:
		break;
	}
	
};

void DrawMovement::MoveCamera(ObjectContainer* Access, char Input)
{
	switch (Input)
	{
	case 'l':
	{
		Access->containerUpdateObjects(-0.1f, 0.0f, 'm', "all");
		break;
	}
	case 'r':
	{
		Access->containerUpdateObjects(0.1f, 0.0f, 'm', "all");
		break;
	}
	case 'u':
	{
		Access->containerUpdateObjects(0.0f, 0.1f, 'm', "all");
		break;
	}
	case 'd':
	{
		Access->containerUpdateObjects(0.0f, -0.1f, 'm', "all");
		break;
	}
	case 'q':
	{
		Access->containerUpdateObjects(0.1f, 0.0f, 'r', "all");
		break;
	}
	case 'e':
	{
		Access->containerUpdateObjects(-0.1f, 0.0f, 'r', "all");
		break;
	}
	case 'b':
	{
		Access->containerUpdateObjects(0.01f, 0.0f, 's', "all");
		break;
	}
	case 's':
	{
		Access->containerUpdateObjects(-0.01f, 0.0f, 's', "all");
		break;
	}
	default:
		break;
	}
};