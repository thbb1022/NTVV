#pragma once

#include "Libs.h"

class Points
{
public:
	Points();
	~Points();
	void Add(glm::vec2 position);
	void Delete();
	void Draw();

private:
	std::vector<glm::vec2> pointsList;
	unsigned int VAO; //vector array object
	unsigned int VBO; //vertex buffer object

	void UpdateGPUBuffer();
};