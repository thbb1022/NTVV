#pragma once
#include "Libs.h"
#include "Points.h"
#include "ShaderProgram.h"

class Window
{
public:
	Window(int w, int h);
	~Window();
	void Input();
	void MainLoop();
	void ResizeCallBack();
private:
	int w, h;
	GLFWwindow * windowPtr;

	ShaderProgram *shader;
	Points *pointsRenderer;
};