#pragma once
#include "include/GraphicEngine/VAO.h"
#include "include/Reader/Reader.h"
#include "direct.h"
#include <vector>

class BasicModel {
public:
	static vector<VAO> ball;
	static vector<VAO> cube;
	static void init();
};
