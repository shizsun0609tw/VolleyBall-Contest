#pragma once

#include "include/Character/Character.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"
#include <stdlib.h>
#include <time.h>
#define MAXSPEED 8.0
#define G 9.80665

class Member : public Character {
public:
	Member() : Character() {}
	Member(glm::vec3 pos, glm::vec3 angle, glm::vec3 size, glm::vec3 color)
		: Character(pos, angle, size, color) {
		next = Animation::idle;
		arrived = false;
		hit = false;
	}
	~Member() {}
	/*****moving*****/
	void update(bool arrive, bool must, int hit,VolleyBall &ball, int team);
	// compute forward direction when ball come(after normalize)
	glm::vec3 spike(glm::vec3 pos, Velocity velocity);
	glm::vec3 serve(glm::vec3 pos, Velocity velocity);
	// get this character and ball's distance
	float getDistance(glm::vec3 pos);
	// decide moving volocity
	glm::vec3 speedUp(bool arrive, bool must, glm::vec3 pos, Velocity velocity);
	// back to initial 
	void back(glm::vec3 pos);
	bool arrived;
	bool hit;
private:
	Animation next; // store next opration
};