#pragma once

#include "include/Character/Character.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"
#define MAXSPEED 8.0
#define G 9.80665

class Member : public Character {
public:
	Member() : Character() {}
	Member(glm::vec3 pos, glm::vec3 angle, glm::vec3 size, glm::vec3 color)
		: Character(pos, angle, size, color) {}
	~Member() {}

	bool update(bool arrive, bool must, int hit, glm::vec3 pos, Velocity velocity);
	// compute forward direction when ball come(after normalize)
	glm::vec3 spike(glm::vec3 pos, Velocity velocity);
	glm::vec3 serve(glm::vec3 pos, Velocity velocity);
	// get this character and ball's distance
	float getDistance(glm::vec3 pos);
	// decide moving volocity
	glm::vec3 speedUp(bool arrive, bool must, int hit, glm::vec3 pos, Velocity velocity);
};