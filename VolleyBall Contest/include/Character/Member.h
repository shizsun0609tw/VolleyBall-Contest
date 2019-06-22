#pragma once

#include "include/Character/Character.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"

class Member : public Character {
public:
	glm::vec3 spike(glm::vec3 pos, Velocity velocity);
	glm::vec3 serve(glm::vec3 pos, Velocity velocity);
};