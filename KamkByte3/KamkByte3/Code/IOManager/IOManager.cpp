#include "IOManager.h"

#include <fstream>



bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer)
{
	std::ifstream file(filePath, std::ios::binary);
	if (file.fail())
	{
		perror(filePath.c_str());
		return false;
	}

	//Selataan loppuun
	file.seekg(0, std::ios::end);

	//Otetaan tiedosto koko
	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
 
	//Pienennetään tiedosto kokoa jokaisesta mahdollisesta header tavusta
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read((char *)&(buffer[0]), fileSize);
	file.close();

	return true;
}
