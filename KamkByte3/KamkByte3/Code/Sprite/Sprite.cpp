#include "Sprite.h"
#include "../Vertex/Vertex.h"

#include <cstddef>


Sprite::Sprite()
{
	_vboID = 0;
}


Sprite::~Sprite()
{
	if (_vboID != 0)
	{
		glDeleteBuffers(1, &_vboID);
	}
}

void Sprite::init(float posX, float posY, float width, float height, std::string texturePath)
{
	_x = posX;
	_y = posY;
	_width = width;
	_height = height;

	if (_vboID == 0)
	{
		glGenBuffers(1, &_vboID);
	}

	Vertex vertexData[6];

	//Ensimmäinen kolmio
	vertexData[0].setPosition(posX + width, posY + height);
	vertexData[0].setUV(1.0f, 1.0f);

	vertexData[1].setPosition(posX, posY + height);
	vertexData[1].setUV(0.0f, 1.0f);

	vertexData[2].setPosition(posX, posY);
	vertexData[2].setUV(0.0f, 0.0f);

	//Toinen kolmio
	vertexData[3].setPosition(posX, posY);
	vertexData[3].setUV(0.0f, 0.0f);

	vertexData[4].setPosition(posX + width, posY);
	vertexData[4].setUV(1.0f, 0.0f);

	vertexData[5].setPosition(posX + width, posY + height);
	vertexData[5].setUV(1.0f, 1.0f);


	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	//Sijainti attribuutin pointteri
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	// attribuutin pointteri
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	//Sijainti attribuutin pointteri
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

