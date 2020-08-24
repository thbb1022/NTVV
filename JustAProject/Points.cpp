#include "Points.h"

Points::Points()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glPointSize(5);
}

Points::~Points()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Points::Add(glm::vec2 position)
{
	pointsList.push_back(position);
	UpdateGPUBuffer();
}

void Points::Delete()
{
	pointsList.pop_back();
	UpdateGPUBuffer();
}

void Points::Draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_POINTS, 0, pointsList.size());
}

void Points::UpdateGPUBuffer()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, pointsList.size() * sizeof(glm::vec2), pointsList.data(), GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
