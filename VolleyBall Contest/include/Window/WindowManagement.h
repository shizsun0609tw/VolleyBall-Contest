#pragma once

#include "include/Game/Game.h"
#include "include/Header/_var.h"
#include "include/Header/Control.h"
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace std;

class WindowManagement
{
public:
	WindowManagement();
	~WindowManagement();

	bool init(int w, int h);
	void mainLoop();
	void display();
private:
	Game game;

	GLFWwindow *window;
	void setCallbackFunction();
	static void error_callback(int error, const char * description);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};