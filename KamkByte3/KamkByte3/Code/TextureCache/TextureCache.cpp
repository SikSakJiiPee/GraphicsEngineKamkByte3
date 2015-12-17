#include "TextureCache.h"
#include "../ImageLoader/ImageLoader.h"
#include <iostream>



TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}


GLTexture TextureCache::getTexture(std::string texturePath)
{
	//Katsotaan tektuuri ja onko se mapissa
	auto mit = _textureMap.find(texturePath);

	//Katsotaan jos se ei ole mapissa
	if (mit == _textureMap.end())
	{
		//Ladataan tekstuuri
		GLTexture newTexture = ImageLoader::loadPNG(texturePath);

		//Pannaan se mappiin
		_textureMap.insert(make_pair(texturePath, newTexture));

		std::cout << "Loaded Texture!\n";
		return newTexture;
	}
	std::cout << "Used Cached Texture!\n";
	return mit->second;
}
