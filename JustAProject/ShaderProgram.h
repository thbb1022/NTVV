#pragma once

#include "Libs.h"

class ShaderProgram
{
public:
	ShaderProgram(const char* vertexShader, const char* pragmentShader);
	~ShaderProgram();
	void Use();

private:
	unsigned int ID;
	void CheckError(unsigned int shaderId, std::string type);
};