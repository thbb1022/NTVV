#include "Window.h"

Window::Window(int _w, int _h):w(_w), h(_h)
{
	//init GLFW
	glfwInit();
	//create window
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	windowPtr = glfwCreateWindow(_w, _h, "Game screen", NULL, NULL);

	if (windowPtr == nullptr)
	{
		std::cout << "ERROR::WINDOW.CPP::GLFW_WINDOW_INIT_FAILED\n";
		return;
	}

	glfwMakeContextCurrent(windowPtr);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::WINDOW.CPP::GLEW_INIT_FAILED\n";
		glfwTerminate();
	}
	//
	const char* vs = R"CODE(
			#version 450 core
			layout(location = 0) in vec2 point;
			void main()
			{
				gl_Position = vec4(point.x, point.y, 0.f, 1.f);
			};
)CODE";
	const char* fs = R"CODE(
				#version 450 core
			out vec4 finalcolor;
			void main()
			{
				finalcolor = vec4(1.f, 1.f, 0.f, 1.f);
			};
)CODE";
	shader = new ShaderProgram(vs, fs);
	//
	pointsRenderer = new Points();
	pointsRenderer->Add(glm::vec2(0, 0)); 
	pointsRenderer->Add(glm::vec2(0, 0.5));
}

Window::~Window()
{
	delete pointsRenderer;
	glfwDestroyWindow(windowPtr);
	glfwTerminate();
}

void Window::Input()
{
	if (glfwGetKey(windowPtr, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(windowPtr, GLFW_TRUE);
	}
}

void Window::MainLoop()
{
	while (!glfwWindowShouldClose(windowPtr))
	{
		//UPDATE
		glfwPollEvents();
		Input();
		ResizeCallBack();

		//DRAW---	
		//clear
		glClearColor(0.f, 0.0f, 0.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		//use a program
		shader->Use();
		//draw
		pointsRenderer->Draw();
		//end draw
		glfwSwapBuffers(windowPtr);
	}

}

void Window::ResizeCallBack()
{
	int width, height;
	glfwGetWindowSize(windowPtr, &width, &height);
	if (w != width || h != height)
	{
		w = width;
		h = height;
		glViewport(0, 0, w, h);
	}

}
