#include "GLSLProgram.h"
#include "../ErrorManager/ErrorManager.h"

#include <vector>

#include <fstream>


GLSLProgram::GLSLProgram() : _numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{
}


GLSLProgram::~GLSLProgram()
{
}

//K‰‰nt‰‰ shaderit GPU:n ymm‰rt‰m‰‰n muotoon
void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	//Vertex ja Fragment shaderien k‰‰ntˆ on onnistunut 
	//Linkataan ne yhdeksi ohjelmaksi ja saadaan ohjelma objekti.
	_programID = glCreateProgram();

	//Luodaan vertex shader objekti ja otetaan ID talteen
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0)
	{
		fatalError("Vertex shader failed to be created!");
	}

	//Luodaan fragment shader objekti ja otetaan ID talteen
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0)
	{
		fatalError("Fragment shader failed to be created!");
	}

	//K‰‰nnet‰‰n kumpikin shader
	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);
}

void GLSLProgram::linkShaders()
{
	//Liitet‰‰n shaderit ohjelmaan
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//Linkitet‰‰n ohjelma
	glLinkProgram(_programID);

	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		//Ohjelmaa ei en‰‰ tarvita
		glDeleteProgram(_programID);
		//Poistetaan myˆs shaderit
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		//Infologi
		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shaders failed to link");
	}

	//Erotetaan shaderit onnistuneen linkkauksen j‰lkeen
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

GLint GLSLProgram::getUniformLocation(const std::string& uniformName)
{
	GLint location = glGetUniformLocation(_programID, uniformName.c_str());
	if (location == GL_INVALID_INDEX)
	{
		fatalError("Uniform" + uniformName + " not found in shader!");
	}
	return location;
}

void GLSLProgram::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str()); //++ lopussa lis‰‰ _numAttributes arvoa yhdell‰ koodirivin j‰lkeen
	
}

void GLSLProgram::use()
{
	glUseProgram(_programID);
	for (int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

void GLSLProgram::compileShader(const std::string& filePath, GLuint id)
{
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail())
	{
		perror(filePath.c_str());
		fatalError("Failed to open " + filePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line))
	{
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);
	glCompileShader(id);


	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		//Poistetaan shader
		glDeleteShader(id);

		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shader " + filePath + " failed to compile");
	}
}