#pragma once
#include <GLFW/glfw3.h>

class Control {
public:
	static int key;
	static int scancode;
	static int action;
	static int mods;
	static void reset();
};
