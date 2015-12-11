#pragma once
#include "../../AllIncludes/ALLIncludes.cpp"
//
class ObjectMold
{
public:
	ObjectMold(){};
	~ObjectMold(void){};

	std::string getName();
	void setName(std::string name);

	std::string getDirectory();
	void setDirectory(std::string path);

	float getScale();
	void setScale(float scale);
	
	float getLocationPoint(int i);	
	void setLocationPoints(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float ex, float ey, float fx, float fy, float z, float alpha);

	float getOrigin(char i);
	void setOrigin(float x, float y);

	void readObject();

private:

	std::string Name = "Name";
	std::string Directory = "No Dircetory";
	float ObjectScale = 1.0f;
	float Location[14] ;
	float Origin[2];
	


};

