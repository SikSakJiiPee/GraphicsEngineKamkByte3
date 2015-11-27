#include "ObjectMold.h"

std::string ObjectMold::getName()
{
	return Name;
}

void ObjectMold::setName(std::string name)
{
	Name = name;
}

std::string ObjectMold::getDirectory()
{
	return Directory;
}

void ObjectMold::setDirectory(std::string path)
{
	Directory = path;
}

float ObjectMold::getScale()
{
	return ObjectScale;
}

void ObjectMold::setScale(float scale)
{
	ObjectScale = scale;
}


float ObjectMold::getLocationPoint(int i)
{
	return Location[i];
}

void ObjectMold::setLocationPoints(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float ex, float ey, float fx, float fy, float z, float alpha)
{
	for (int i = 0; i < 14; i++)
	{
		switch (i)
		{
		case 0:
		{
			Location[i] = ax;
			break;
		}
		case 1:
		{
			Location[i] = ay;
			break;
		}
		case 2:
		{
			Location[i] = bx;
			break;
		}
		case 3:
		{
			Location[i] = by;
			break;
		}
		case 4:
		{
			Location[i] = cx;
			break;
		}
		case 5:
		{
			Location[i] = cy;
			break;
		}
		case 6:
		{
			Location[i] = dx;
			break;
		}
		case 7:
		{
			Location[i] = dy;
			break;
		}
		case 8:
		{
			Location[i] = ex;
			break;
		}
		case 9:
		{
			Location[i] = ey;
			break;
		}
		case 10:
		{
			Location[i] = fx;
			break;
		}
		case 11:
		{
			Location[i] = fy;
			break;
		}
		case 12:
		{
			Location[i] = z;
			break;
		}
		case 13:
		{
			Location[i] =alpha;
			break;
		}
		default:
			break;
		}
		 
	}

}

void ObjectMold::readObject()
{
	std::cout << "\nName: " << Name << "\nDirectory: " << Directory << "\nScale: " << ObjectScale << "\nLocation: [";
	for (int i = 0; i < 14; i++)
	{
		std::cout << Location[i] << ", ";
		if (i == 13)
		{
			std::cout << "]\n";
		}
	}
}

