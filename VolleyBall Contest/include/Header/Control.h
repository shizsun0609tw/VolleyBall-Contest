#pragma once
#include <GLFW/glfw3.h>
#include <map>
#include <string>

using namespace std;

typedef int GLFW_KEY;

class Control {
public:
	static map<GLFW_KEY, bool> controlTable;
	static void update(int key, int scancode, int action, int mods);
};
