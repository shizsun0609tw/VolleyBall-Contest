#include"include/Header/Control.h"

int Control::key = -1;
int Control::scancode = -1;
int Control::action = -1;
int Control::mods = -1;

void Control::reset() {
	key = -1;
	scancode = -1;
	action = -1;
	mods = -1;
}