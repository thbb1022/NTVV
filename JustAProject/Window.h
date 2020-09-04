#pragma once
#include "lib.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include "Sprite.h"
#include "Game.h"

class Window
{
public:
	Window(int width, int height);

	~Window();

	void Input();

	void Resize();

	void Mainloop();


private:

	int _width, _height;
	GLFWwindow *windowPtr;

	ShaderProgram* shader;
	Camera* camera;

	Game* game;
	vector<Action> actions;
	static int keyState;
};