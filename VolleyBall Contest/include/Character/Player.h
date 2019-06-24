#pragma once
#include "include/Character/Character.h"
#include "include/Scene/VolleyBall.h"
#include "include/Header/Control.h"
#include "include/glm/glm.hpp"
#include <GLFW/glfw3.h>

class Player : public Character{
public:
	Player() : Character() {}
	Player(glm::vec3 pos, glm::vec3 angle, glm::vec3 size, glm::vec3 color) 
		: Character(pos, angle, size, color) {}
	~Player() {}

	void update(VolleyBall &ball);
private:

};