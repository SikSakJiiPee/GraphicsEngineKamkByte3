#include "ObjectContainer.h"
//

void ObjectContainer::addObject( std::string name, ObjectMold* gameObject)
{
	allObjects.insert(std::pair<std::string, ObjectMold*>(name, gameObject));
	std::cout<<"\n" << name <<"\n"<< gameObject << "\nInserted into container.\n";
	gameObject->readObject();

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
	std::cout << "\n\n\nSAVEING CONTAINER!!!\n";
	std::string Name;
	std::string Directory;
	char Native[20];
	
	
	float ObjectScale;
	float Location;
	float Origin;

	for (std::map<std::string, ObjectMold*>::iterator saveIt = allObjects.begin(); saveIt != allObjects.end(); ++saveIt)
	{
		if (saveIt == allObjects.begin())
	{
	
		//First file
		std::ofstream outputFile(".../../Data/Objects/Test/Objects.dat", std::ios::binary | std::ios::out);
		if (outputFile)
		{
			

			//outputFile.write((char *)&saveIt->first, sizeof(std::string));
			for (int i = 0; i<20; ++i)
			{
				
				if (i >= saveIt->first.length())
				{
					Native[i] = '@';
				}
				else
				{
					Native[i] = saveIt->first[i];
				}

			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));
			
			}

			
			Name = saveIt->second->getName();
			
			//outputFile.write((char *)&Name,sizeof(std::string));
			for (int i = 0; i < 20; ++i)
			{
				
				if (i >= Name.length())
				{
					Native[i] = '@';
				}
				else
				{
				Native[i] = Name[i];
				}
			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));
			
			}

			Directory = saveIt->second->getDirectory();
			//outputFile.write((char *)&Directory,sizeof(std::string));
			for (int i = 0; i < 20; ++i)
			{
				if (i >= Directory.length())
				{
					Native[i] = '@';
				}
				else
				{

				Native[i] = Directory[i];
				}
			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));
				
			}
			ObjectScale = saveIt->second->getScale();
			outputFile.write((char *)&ObjectScale, sizeof(float));
			for (int i = 0; i < 14; i++)
			{
				Location = saveIt->second->getLocationPoint(i);
				outputFile.write((char *)&Location,sizeof(float));
			}
			Origin = saveIt->second->getOrigin('x');
			outputFile.write((char *)&Origin, sizeof(float));
			Origin = saveIt->second->getOrigin('y');
			outputFile.write((char *)&Origin, sizeof(float));
			
			
			std::cout << "Clean objectfile started with "<<saveIt->first<<".\n";
			saveIt->second->readObject();
			
		}
	
		
		else
		{
			std::cout << "Failed to make clean object file.\n";
		}
	
	}	
	
		
	else
	{
		
		//Rest of files
		std::ofstream outputFile(".../../Data/Objects/Test/Objects.dat", std::ios::binary | std::ios::out | std::ios_base::app);
		if (outputFile)
		{

			//outputFile.write((char *)&saveIt->first, sizeof(std::string));
			for (int i = 0; i<20; ++i)
			{
				Native[i] = saveIt->first[i];
				if (i >= saveIt->first.length())
				{
					Native[i] = '@';
				}

			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));

			}


			Name = saveIt->second->getName();

			//outputFile.write((char *)&Name,sizeof(std::string));
			for (int i = 0; i < 20; ++i)
			{
				Native[i] = Name[i];
				if (i >= Name.length())
				{
					Native[i] = '@';
				}
			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));

			}

			Directory = saveIt->second->getDirectory();
			//outputFile.write((char *)&Directory,sizeof(std::string));
			for (int i = 0; i < 20; ++i)
			{
				Native[i] = Directory[i];
				if (i >= Directory.length())
				{
					Native[i] = '@';
				}
			}

			for (int i = 0; i < 20; i++)
			{
				outputFile.write((char *)&Native[i], sizeof(char));

			}
			ObjectScale = saveIt->second->getScale();
			outputFile.write((char *)&ObjectScale, sizeof(float));
			for (int i = 0; i < 14; i++)
			{
				Location = saveIt->second->getLocationPoint(i);
				outputFile.write((char *)&Location,sizeof(float));
			}
			
				Origin = saveIt->second->getOrigin('x');
				outputFile.write((char *)&Origin, sizeof(float));
				Origin = saveIt->second->getOrigin('y');
				outputFile.write((char *)&Origin, sizeof(float));
	
			outputFile.close();

			std::cout << "Object writed in file.\n";
			saveIt->second->readObject();
		}
		
		
		else
		{
			std::cout << "Failed to write object into file.\n";
		}
	
	}
	}

}

void ObjectContainer::loadContainerBin()
{
	std::cout << "\n\n\nLOADING CONTAINER!!!\n";
	char input[60];
	char Name[20];
	char Directory[20];
	float ObjectScale=0.0f;
	float Location[14];
	float Origin[2];
	ObjectMold* objTemp=new ObjectMold;
	char nameTemp[20];
	std::ifstream inputFile(".../../Data/Objects/Test/Objects.dat", std::ios::binary | std::ios::in|std::ios::beg);

	if (inputFile)
	{
		
	
		
			inputFile.read(input, sizeof(input));
			for (int i = 0; i < 20; i++)
			{
				if (input[i] == '@')
				{
					nameTemp[i] = NULL;
				}
				else
				{
					nameTemp[i] = input[i];
				}
			}
			for (int i = 20; i < 40; i++)
			
				if (input[i] == '@')
				{
					Name[i - 20] = NULL;
				}
				else
				{
					Name[i-20] = input[i];
				}
			
			for (int i = 40; i < 60; i++)
			{
				if (input[i] == '@')
				{
					Directory[i - 40] = NULL;
				}
				else
				{
					Directory[i-40] = input[i];
				}
			}
		
				inputFile.read((char *)&ObjectScale, sizeof(float));
				objTemp->setName(Name);
				objTemp->setDirectory(Directory);
				objTemp->setScale(ObjectScale);

				for (int i = 0; i < 14; i++)
				{
					inputFile.read((char *)&Location[i], sizeof(float));
				}	
				
				objTemp->setLocationPoints(Location[0], Location[1], Location[2], Location[3], Location[4], Location[5], Location[6], Location[7], Location[8], Location[9], Location[10], Location[11], Location[12], Location[13]);
			
				for (int i = 0; i < 2; i++)
				{
					inputFile.read((char *)&Origin[i], sizeof(float));
				}
				objTemp->setOrigin(Origin[0], Origin[1]);
				
				addObject(nameTemp, objTemp);
				
				
		
		
		
		inputFile.close();
		std::cout << "Object file readed.\n";
		
	}
	
	
	else
	{
		std::cout << "Reading object file failed.\n";
	}


}


void ObjectContainer::containerDraw(SDL_Window* WinMain)
{	
	
			SDL_GL_SwapWindow(WinMain);
			glClear(GL_COLOR_BUFFER_BIT);
			
		
			
	for (std::map<std::string, ObjectMold*>::iterator saveIt = allObjects.begin(); saveIt != allObjects.end(); ++saveIt)
	{
		float x, y;
		x = saveIt->second->getOrigin('x');
		y = saveIt->second->getOrigin('y');
		
		
		

		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 1.0);
			
			
			glVertex3f(saveIt->second->getLocationPoint(0)+x, saveIt->second->getLocationPoint(1)+y, saveIt->second->getLocationPoint(12));
			glVertex3f(saveIt->second->getLocationPoint(2)+x, saveIt->second->getLocationPoint(3)+y, saveIt->second->getLocationPoint(12));
			glVertex3f(saveIt->second->getLocationPoint(4)+x, saveIt->second->getLocationPoint(5)+y, saveIt->second->getLocationPoint(12));

			glVertex3f(saveIt->second->getLocationPoint(6)+x, saveIt->second->getLocationPoint(7)+y, saveIt->second->getLocationPoint(12));
			glVertex3f(saveIt->second->getLocationPoint(8)+x, saveIt->second->getLocationPoint(9)+y, saveIt->second->getLocationPoint(12));
			glVertex3f(saveIt->second->getLocationPoint(10)+x, saveIt->second->getLocationPoint(11)+y, saveIt->second->getLocationPoint(12));

			glEnd();

		

	}
}

void ObjectContainer::containerUpdateObjects(float inx,float iny,char obj,std::string name)
{
			
	std::map<std::string, ObjectMold*>::iterator saveIt;
	if (name != "all")
	{
	saveIt = allObjects.find("Player");
			switch (obj)
			{
			case 'm':
			{
				saveIt->second->setOrigin(saveIt->second->getOrigin('x') + inx, saveIt->second->getOrigin('y') + iny);
				break;
			}
			case 'r':
			{
				
				float oldX;
				float oldY;
				float newLoc[14];
			
					oldX = saveIt->second->getLocationPoint(0);
					oldY = saveIt->second->getLocationPoint(1);
						newLoc[0] =oldX*cos(inx) - oldY*sin(inx);
						newLoc[1] =oldX*sin(inx) + oldY*cos(inx);
					oldX = saveIt->second->getLocationPoint(2);
					oldY = saveIt->second->getLocationPoint(3);
						newLoc[2] = oldX*cos(inx)-oldY*sin(inx);
						newLoc[3] = oldX*sin(inx) +oldY*cos(inx);
					oldX = saveIt->second->getLocationPoint(4);
					oldY = saveIt->second->getLocationPoint(5);
						newLoc[4] = oldX*cos(inx) - oldY*sin(inx);
						newLoc[5] = oldX*sin(inx) + oldY*cos(inx);
					oldX = saveIt->second->getLocationPoint(8);
					oldY = saveIt->second->getLocationPoint(9);
						newLoc[8] =oldX *cos(inx) - oldY*sin(inx);
						newLoc[9] = oldX*sin(inx) + oldY*cos(inx);
			
				newLoc[6] = newLoc[2];
				newLoc[7] = newLoc[3];
				newLoc[10] = newLoc[4];
				newLoc[11] = newLoc[5];
				newLoc[12] = saveIt->second->getLocationPoint(12);
				newLoc[13] = saveIt->second->getLocationPoint(13);
				
				saveIt->second->setLocationPoints(newLoc[0], newLoc[1], newLoc[2], newLoc[3], newLoc[4], newLoc[5], newLoc[6], newLoc[7], newLoc[8], newLoc[9], newLoc[10], newLoc[11], newLoc[12], newLoc[13]);
				
				break;
			}
			default:
				break;
			}
		}
		else if (name == "all")
		{
			for (std::map<std::string, ObjectMold*>::iterator saveIt = allObjects.begin(); saveIt != allObjects.end(); ++saveIt)
			{

			}


		}
	}

