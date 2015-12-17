#pragma once
#include "../GLTexture/GLTexture.h"

#include <string>

//Ladataan kuvat GLTextureen
class ImageLoader
{
public:
	static GLTexture loadPNG(std::string filePath);
};

