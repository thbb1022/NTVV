#include "Window.h"


int Window::keyState = GLFW_RELEASE;

Window::Window(int width, int height)
{
	_width = width;
	_height = height;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_MAXIMIZED,true);

	windowPtr = glfwCreateWindow(width, height, "NTVV",NULL,NULL);
	if(windowPtr ==  nullptr)
	{
		cout << "ERROR::WINDOW.CPP::GLEW_GLFW_WINDOW_FAILED\n";
		return;
	}

	glfwMakeContextCurrent(windowPtr);

	if(glewInit())
	{
		cout << "ERROR::WINDOW.CPP::GLEW_INIT_FAILED\n";
		return;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//set icon
	Texture* ic = new Texture("Images\\devuong.png");
	GLFWimage image;
	image.height = ic->GetHeight();
	image.width = ic->GetWidght();
	image.pixels = ic->getdata();
	glfwSetWindowIcon(windowPtr,1,&image);
	delete ic;

	//vertex shader
	const char* vs = R"CODE(
			#version 450 core
			layout(location = 0) in vec2 point;
			layout(location = 1) in vec4 color;
			layout(location = 2) in vec2 uv;

			uniform mat4 projection;
			uniform mat4 model_matrx;

			out vec4 vertex_color;
			out vec2 vertex_uv;

			void main()
			{
				gl_Position = projection * model_matrx * vec4(point.x, point.y, 0.0, 1.0);
				vertex_color = color;
				vertex_uv = uv;
			};
)CODE";

	//fragment shader
	const char* fs = R"CODE(

			#version 450 core
			out vec4 finalcolor;

			in vec4 vertex_color;
			in vec2 vertex_uv;

			uniform sampler2D sprite;

			void main()
			{
				finalcolor = vertex_color * texture(sprite,vertex_uv);
			};
)CODE";


	camera = new Camera(_width,_height);
	shader = new ShaderProgram(vs,fs);

	game = new Game();
}

Window::~Window()
{
	delete shader;
	delete camera;
	delete game;
	glfwTerminate();
}

void Window::Input()
{
	if(glfwGetKey(windowPtr,GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(windowPtr,true);
	}

	if(glfwGetKey(windowPtr,GLFW_KEY_UP) || glfwGetKey(windowPtr, GLFW_KEY_W))
	{
		Action ac;
		ac._type = MOVE_UP;
		actions.push_back(ac);
	}
	
	if(glfwGetKey(windowPtr,GLFW_KEY_DOWN) || glfwGetKey(windowPtr, GLFW_KEY_S))
	{
		Action ac;
		ac._type = MOVE_DOWN;
		actions.push_back(ac);
	}

	if(glfwGetKey(windowPtr,GLFW_KEY_LEFT) || glfwGetKey(windowPtr, GLFW_KEY_A))
	{
		Action ac;
		ac._type = MOVE_LEFT;
		actions.push_back(ac);
	}

	if(glfwGetKey(windowPtr,GLFW_KEY_RIGHT) || glfwGetKey(windowPtr, GLFW_KEY_D))
	{
		Action ac;
		ac._type = MOVE_RIGHT;
		actions.push_back(ac);
	}

	if (glfwGetMouseButton(windowPtr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(windowPtr, &xpos, &ypos);
		Action ac;

		if (xpos <= 150 && xpos >= 50)
		{
			if (ypos <= 400 && ypos >= 300)
				ac._type = SELECTMENU1;
			else if (ypos <= 550 && ypos >= 450)
				ac._type = SELECTMENU2;
			else if (ypos <= 700 && ypos >= 600)
				ac._type = SELECTMENU3;
		}
		//150->250 300->400
		//300->400 300->400
		//450->550 300->400
		//600->700 300->400
		if(ypos <= 400 && ypos >= 300)
		{
			if (xpos <= 250 && xpos >= 150)
				ac._type = SELECTSPMENU1;
			else if (xpos <= 400 && xpos >= 300)
				ac._type = SELECTSPMENU2;
			else if (xpos <= 550 && xpos >= 450)
				ac._type = SELECTSPMENU3;
			else if (xpos <= 700 && xpos >= 600)
				ac._type = SELECTSPMENU4;
			else if (xpos <= 850 && xpos >= 750)
				ac._type = SELECTSPMENU5;
		}
		else if (ypos <= 550 && ypos >= 450)
		{
			if (xpos <= 250 && xpos >= 150)
				ac._type = SELECTSPMENU6;
			else if (xpos <= 400 && xpos >= 300)
				ac._type = SELECTSPMENU7;
			else if (xpos <= 550 && xpos >= 450)
				ac._type = SELECTSPMENU8;
			else if (xpos <= 700 && xpos >= 600)
				ac._type = SELECTSPMENU9;
			else if (xpos <= 850 && xpos >= 750)
				ac._type = SELECTSPMENU10;
		}
		else if (ypos <= 750 && ypos >= 600)
		{
			if (xpos <= 250 && xpos >= 150)
				ac._type = SELECTSPMENU11;
			else if (xpos <= 400 && xpos >= 300)
				ac._type = QUITSPMENU;
			//else if (xpos <= 550 && xpos >= 450)
			//	ac._type = SELECTSPMENU3;
			//else if (xpos <= 700 && xpos >= 600)
			//	ac._type = SELECTSPMENU4;
			//else if (xpos <= 700 && xpos >= 600)
			//	ac._type = SELECTSPMENU5;
		}
		actions.push_back(ac);
	}
		if (glfwGetMouseButton(windowPtr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(windowPtr, &xpos, &ypos);
		Action ac;

		if(ypos <= 550 && ypos >= 400)
		{
			if (xpos <= 550 && xpos >= 400)
				ac._type = SELECTWAREHOUSE1;
			else if (xpos <= 700 && xpos >= 550)
				ac._type = SELECTWAREHOUSE2;
			else if (xpos <= 850 && xpos >= 700)
				ac._type = SELECTWAREHOUSE3;
			else if (xpos <= 1000 && xpos >= 850)
				ac._type = SELECTWAREHOUSE4;
			else if (xpos <= 1150 && xpos >= 1000)
				ac._type = SELECTWAREHOUSE5;
		}
		else if (ypos <= 700 && ypos >= 550)
		{
			if (xpos <= 550 && xpos >= 400)
				ac._type = SELECTWAREHOUSE6;
			else if (xpos <= 700 && xpos >= 550)
				ac._type = SELECTWAREHOUSE7;
			else if (xpos <= 850 && xpos >= 700)
				ac._type = SELECTWAREHOUSE8;
			else if (xpos <= 1000 && xpos >= 850)
				ac._type = SELECTWAREHOUSE9;
			else if (xpos <= 1150 && xpos >= 1000)
				ac._type = SELECTWAREHOUSE10;
		}
		else if (ypos <= 850 && ypos >= 700)
		{
			if (xpos <= 550 && xpos >= 400)
				ac._type = SELECTWAREHOUSE11;
			else if (xpos <= 700 && xpos >= 550)
				ac._type = QUITWAREHOUSE;
			//else if (xpos <= 550 && xpos >= 450)
			//	ac._type = SELECTSPMENU3;
			//else if (xpos <= 700 && xpos >= 600)
			//	ac._type = SELECTSPMENU4;
			//else if (xpos <= 700 && xpos >= 600)
			//	ac._type = SELECTSPMENU5;
		}
		actions.push_back(ac);
	}
	if (glfwGetKey(windowPtr, GLFW_KEY_SPACE))
	{
		Action ac;
		ac._type = PLANT;
		actions.push_back(ac);
	}
	if (glfwGetKey(windowPtr, GLFW_KEY_SPACE))
	{
		Action ac;
		ac._type = WAREHOUSE;
		actions.push_back(ac);
	}
	if (glfwGetKey(windowPtr, GLFW_KEY_SPACE))
	{
		Action ac;
		ac._type = SELL;
		actions.push_back(ac);
	}
	game->input(actions);
	actions.clear();
}

void Window::Resize()
{
	int width,height;
	glfwGetWindowSize(windowPtr,&width,&height);
	if(width != _width || height != _height)
	{
		_width = width;
		_height = height;
		glViewport(0,0,width,height);
		camera->Update_Viewport(_width,_height);
	}
}


void Window::Mainloop()
{
	while (!glfwWindowShouldClose(windowPtr))
	{
		//UPDATE INPUT---
		glfwPollEvents();
		//UPADTE---
		Resize();
		Input();
		//DRAW---
		//clear
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//use a program
		shader->use();
		shader->Send_Mat4("projection", camera->Get_Projection());
		//draw
		game->Draw(shader);
		//end draw
		glfwSwapBuffers(windowPtr);
		glFlush();
	}
}


