#include"include/Header/Control.h"


map<GLFW_KEY, bool> Control::controlTable;


void Control::update(int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		controlTable[key] = true;
	}else if (action == GLFW_RELEASE) {
		controlTable[key] = false;
	}
}