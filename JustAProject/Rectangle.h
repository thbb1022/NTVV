#pragma once
#include "lib.h"

class Rectangle
{
public:
	Rectangle();

	~Rectangle();
	
	void Draw();

	glm::mat4 GetTransformation();

	void setposition(glm::vec2 pos);

	void setscale(glm::vec2 scal);

	void setrotation(float rotation);

	
	glm::vec2 getposition();

	glm::vec2 getscale();

	float getrotation();


private:

	glm::vec2 position;
	glm::vec2 scale;
	float rotaionAngle;

	unsigned int VAO; //vertex array object
	unsigned int VBO; // vertex buffer object
	unsigned int CBO; // color buffer object
	unsigned int UVBO; // uv buffer object
};