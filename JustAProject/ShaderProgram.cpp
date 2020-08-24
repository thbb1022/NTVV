#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char * vertexShader, const char * pragmentShader)
{
	//complite shader
	unsigned _vertexShader, _pragmentShader;
	//vertex shader
	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &vertexShader, NULL);
	glCompileShader(_vertexShader);
	CheckError(_vertexShader, "SHADER");
	//pragment shader
	_pragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_pragmentShader, 1, &pragmentShader, NULL);
	glCompileShader(_pragmentShader);
	CheckError(_pragmentShader, "PRAGMENT");
	//shader program
	ID = glCreateProgram();
	glAttachShader(ID, _vertexShader);
	glAttachShader(ID, _pragmentShader);

	glLinkProgram(ID);
	CheckError(ID, "PROGRAM");

	glDeleteShader(_vertexShader);
	glDeleteShader(_pragmentShader);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(ID); 
}

void ShaderProgram::Use()
{
	glUseProgram(ID);
}

void ShaderProgram::CheckError(unsigned int shaderId, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADERPROGRAM.CPP:COULD_NOT_COMPILE_"<<type<<"_SHADER\n";
			std::cout << infoLog << "\n";
		}
	}
	else
	{
		glGetShaderiv(shaderId, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderId, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADERPROGRAM.CPP:COULD_NOT_LINK_" << type << "_SHADER\n";
			std::cout << infoLog << "\n";
		}
	}
}	
