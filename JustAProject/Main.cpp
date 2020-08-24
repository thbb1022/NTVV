#include "Window.h"


int main()
{
	Window *window = new Window(1000, 700);
	window->MainLoop();
	return 0;
}