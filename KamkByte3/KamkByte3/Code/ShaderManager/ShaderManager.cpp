
#include "ShaderManager.h"

#include "fstream"



	ShaderManager::ShaderManager() : _program(0), _numShaders(0)
	{
		_shaders[VERTEX_SHADER] = 0;
		_shaders[FRAGMENT_SHADER] = 0;
		_shaders[GEOMETRY_SHADER] = 0;
		_shaders[PIXEL_SHADER] = 0;
		_attribList.clear();
		_unifLocationList.clear();
	}

	ShaderManager::~ShaderManager()
	{
		_attribList.clear();
		_unifLocationList.clear();
	}

	void ShaderManager::loadFromText(GLenum type, const std::string& text)
	{
		GLuint shader = glCreateShader(type);
		const char* cstr = text.c_str();
		glShaderSource(shader, 1, &cstr, nullptr);

		///compile + check shader load status
		GLint status;
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint infoLogSize;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogSize);
			GLchar *infoLog = new GLchar[infoLogSize];
			glGetShaderInfoLog(shader, infoLogSize, nullptr, infoLog);
			LOG_ERROR("Shader", infoLog);
			delete[] infoLog;
		}
		_shaders[_numShaders++] = shader;
	}

	void ShaderManager::CreateAndLink(){
		_program = glCreateProgram();
		if (_shaders[VERTEX_SHADER] != 0)
			glAttachShader(_program, _shaders[VERTEX_SHADER]);
		if (_shaders[FRAGMENT_SHADER] != 0)
			glAttachShader(_program, _shaders[FRAGMENT_SHADER]);
		if (_shaders[GEOMETRY_SHADER] != 0)
			glAttachShader(_program, _shaders[GEOMETRY_SHADER]);
		if (_shaders[PIXEL_SHADER] != 0)
			glAttachShader(_program, _shaders[PIXEL_SHADER]);

		///link + check
		GLint status;
		glLinkProgram(_program);
		glGetProgramiv(_program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE){
			GLint infoLogSize;
			glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &infoLogSize);
			GLchar *infoLog = new GLchar[infoLogSize];
			glGetProgramInfoLog(_program, infoLogSize, nullptr, infoLog);
			delete[] infoLog;
		}

		glDetachShader(_program, _shaders[VERTEX_SHADER]);
		glDetachShader(_program, _shaders[FRAGMENT_SHADER]);
		glDetachShader(_program, _shaders[GEOMETRY_SHADER]);
		glDetachShader(_program, _shaders[PIXEL_SHADER]);

		glDeleteShader(_shaders[VERTEX_SHADER]);
		glDeleteShader(_shaders[FRAGMENT_SHADER]);
		glDeleteShader(_shaders[GEOMETRY_SHADER]);
		glDeleteShader(_shaders[PIXEL_SHADER]);
	}

	void ShaderManager::Bind() const
	{
		glUseProgram(_program);
	}

	void ShaderManager::UnBind() const
	{
		glUseProgram(0);
	}

	void ShaderManager::RegisterAttribute(const char* attrib)
	{
		_attribList[attrib] = glGetAttribLocation(_program, attrib);
	}

	void ShaderManager::RegisterUniform(const char* unif)
	{
		_unifLocationList[unif] = glGetUniformLocation(_program, unif);
	}

	GLuint ShaderManager::GetAttribLocation(const char* attrib)
	{
		return _attribList[attrib];
	}
	GLuint ShaderManager::operator[](const char* attrib)
	{
		return _attribList[attrib];
	}

	GLuint ShaderManager::GetUniformLocation(const char* unif)
	{
		return _unifLocationList[unif];
	}
	GLuint ShaderManager::operator()(const char* unif)
	{
		return _unifLocationList[unif];
	}

	GLuint ShaderManager::GetProgramID() const{ return _program; }

	void ShaderManager::loadFromFile(GLenum which, const char* fileName)
	{
		std::ifstream fparser;
		fparser.open(fileName, std::ios_base::in);
		if (fparser)
		{
			///read + load
			std::string buffer(std::istreambuf_iterator<char>(fparser), (std::istreambuf_iterator<char>()));
			loadFromText(which, buffer);
		}
		else
		{
			LOG_ERROR_INFO("Shader", "Invalid fileName path", fileName);
		}
	}

	void ShaderManager::Dispose()
	{
		glDeleteProgram(_program);
		_program = -1;
	}