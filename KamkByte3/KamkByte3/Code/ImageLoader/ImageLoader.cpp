#include "ImageLoader.h"
#include "../picoPNG/picoPNG.h"
#include "../IOManager/IOManager.h"
#include "../ErrorManager/ErrorManager.h"


GLTexture ImageLoader::loadPNG(std::string filePath)
{
	//Luodaan GLTexture ja alustetaan kaikki nollaan
	GLTexture texture = {};

	//Syöttödata decodePNG:lle
	std::vector<unsigned char> in;
	//Ulostulo decodePNG:ltä, joka on pikselidata tekstuurille
	std::vector<unsigned char> out;

	unsigned long width, height;

	//Luetaan kuva tiedoston sisältö bufferiin
	if (IOManager::readFileToBuffer(filePath, in) == false)
	{
		fatalError("Failed to load PNG file to buffer!");
	}

	//Dekoodataan .png formaatti pikselitaulukoksi
	int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
	if (errorCode != 0)
	{
		fatalError("decodePNG failed with error: " + std::to_string(errorCode));
	}

	//Generoidaan openGL tekstuuri objekti
	glGenTextures(1, &(texture.id));

	//Bindataan tekstuuri objekti
	glBindTexture(GL_TEXTURE_2D, texture.id);
	//Ladataan pikselit tekstuuriin
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

	//Asetetaan tekstuuri parametrit
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//Generoidaan mipmapit
	glGenerateMipmap(GL_TEXTURE_2D);

	//Unbindataan tekstuuri
	glBindTexture(GL_TEXTURE_2D, 0);

	texture.width = width;
	texture.height = height;

	//Palautetaan kopio tekstuuridatasta
	return texture;
}

