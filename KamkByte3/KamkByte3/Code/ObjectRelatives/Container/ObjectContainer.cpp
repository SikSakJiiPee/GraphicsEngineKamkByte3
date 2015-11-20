#include "ObjectContainer.h"


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
	float ObjectScale;
	float Location;

	for (std::map<std::string, ObjectMold*>::iterator saveIt = allObjects.begin(); saveIt != allObjects.end(); ++saveIt)
	{
		if (saveIt == allObjects.begin())
	{
	
		//First file
		std::ofstream outputFile(".../../Data/Objects/Test/Objects.dat", std::ios::binary | std::ios::out);
		if (outputFile)
		{
			outputFile.write((char *)&saveIt->first, sizeof(std::string));
			Name = saveIt->second->getName();
			outputFile.write((char *)&Name,sizeof(std::string));
			Directory = saveIt->second->getDirectory();
			outputFile.write((char *)&Directory,sizeof(std::string));
			ObjectScale = saveIt->second->getScale();
			outputFile.write((char *)&ObjectScale, sizeof(float));
			for (int i = 0; i < 14; i++)
			{
				Location = saveIt->second->getLocationPoint(i);
				outputFile.write((char *)&Location,sizeof(float));
			}
			
			
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
			
			outputFile.write((char *)&saveIt->first, sizeof(std::string));
			
			Name = saveIt->second->getName();
			outputFile.write((char *)&Name, sizeof(std::string));
			Directory = saveIt->second->getDirectory();
			outputFile.write((char *)&Directory, sizeof(std::string));
			ObjectScale = saveIt->second->getScale();
			outputFile.write((char *)&ObjectScale, sizeof(float));
			for (int i = 0; i < 14; i++)
			{
				Location = saveIt->second->getLocationPoint(i);
				outputFile.write((char *)&Location,sizeof(float));
			}
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
	std::string Name;
	std::string Directory;
	float ObjectScale;
	float Location[14];
	ObjectMold* objTemp=new ObjectMold;
	std::string nameTemp="temp";
	std::ifstream inputFile(".../../Data/Objects/Test/Objects.dat", std::ios::binary | std::ios::in|std::ios::beg);

	if (inputFile)
	{
		
	
		while (true)
		{
			
				inputFile.read((char *)&nameTemp, sizeof(std::string));

				if (!inputFile.good())break;

				inputFile.read((char *)&Name, sizeof(std::string));
				inputFile.read((char *)&Directory, sizeof(std::string));
				inputFile.read((char *)&ObjectScale, sizeof(float));
				objTemp->setName(Name);
				objTemp->setDirectory(Directory);
				objTemp->setScale(ObjectScale);

				for (int i = 0; i < 14; i++)
				{
					inputFile.read((char *)&Location[i], sizeof(float));
				}

				objTemp->setLocationPoints(Location[0], Location[1], Location[2], Location[3], Location[4], Location[5], Location[6], Location[7], Location[8], Location[9], Location[10], Location[11], Location[12], Location[13]);

				addObject(nameTemp, objTemp);
			
				
				
		
		}
		
		
		
		inputFile.close();
		std::cout << "Object file readed.\n";
		
	}
	
	
	else
	{
		std::cout << "Reading object file failed.\n";
	}


}


void ObjectContainer::containerDraw()
{


}

void ObjectContainer::containerUpdateObjects()
{


}
