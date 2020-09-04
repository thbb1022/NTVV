#pragma once
#include "lib.h"
class Texture
{
public:
	Texture(const char* filepath);

	~Texture();

	void use();

	int GetWidght();

	int GetHeight();


	unsigned char* getdata();

private:
	int width, height, numcomponents;
	unsigned char* data;
	unsigned int textureID;
};