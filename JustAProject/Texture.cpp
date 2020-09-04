#define STB_IMAGE_IMPLEMENTATION    
#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const char * filepath)
{
	glGenTextures(1,&textureID);

	data = stbi_load(filepath, &width, &height, &numcomponents, STBI_rgb_alpha);

	if(data)
	{
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	else
	{
		cout << "ERROR::TEXTURE.CPP:COULD_NOT_OPEN_IMAGE_FILE:"<< filepath <<"\n";
		cout << "============================================"<<endl;
		stbi_image_free(data);
	}
}

Texture::~Texture()
{
	stbi_image_free(data);
}

void Texture::use()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}

int Texture::GetWidght()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

unsigned char * Texture::getdata()
{
	return data;
}
