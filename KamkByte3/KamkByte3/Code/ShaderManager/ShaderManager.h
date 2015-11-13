#pragma once


#include <map>
#include "..\AllIncludes\AllIncludes.cpp"


#define NUM_SHADER_TYPES 4

class ShaderManager
{
public:
	ShaderManager();
	virtual ~ShaderManager();

	void loadFromText(GLenum type, const std::string& src);
	void loadFromFile(GLenum type, const char* fileName);
	void loadFromPreCompiledText(GLenum type, const std::string& src){}
	void loadFromPreCompiledFile(GLenum type, const char* fileName){}
	void CreateAndLink();
	void RegisterAttribute(const char* attrib);
	void RegisterUniform(const char* uniform);
	GLuint GetProgramID() const;
	///accesses elements : shaders/uniforms;
	GLuint GetAttribLocation(const char* attrib);
	GLuint operator[](const char* attrib);
	GLuint GetUniformLocation(const char* unif);
	GLuint operator()(const char* unif);

	virtual void Bind() const;
	virtual void UnBind() const;
	virtual void Dispose();

private:
	enum ShaderType { VERTEX_SHADER, FRAGMENT_SHADER, GEOMETRY_SHADER, PIXEL_SHADER };
	GLuint _program;
	int _numShaders;
	GLuint _shaders[4]; /// VERTEX, FRAGMENT, GEOMETRY AND PIXEL_SHADERS !
	std::map<std::string, GLuint> _attribList;
	std::map<std::string, GLuint> _unifLocationList;
};