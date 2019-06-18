#pragma once

#include "include/Reader/Reader.h"
#include "include/Header/_var.h"
#include "include/GraphicEngine/VAO.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/BasicModel.h"
#include "include/glm/glm.hpp"
#include <vector>

class Character {
public:
	Character() {}
	Character(glm::vec3 pos, glm::vec3 angle, glm::vec3 size)
		: pos(pos), angle(angle), size(size) {}

	~Character() {}
	void update();
	void draw();
protected:
	glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 angle = glm::vec3(0.f);
	glm::mat4 rotateMtx = glm::mat4(1.f);
	glm::vec3 size = glm::vec3(1.f);

	glm::mat4 leftHandRotateMtx = glm::mat4(1.f);
	glm::mat4 rightHandRotateMtx = glm::mat4(1.f);
	glm::mat4 leftLegRotateMtx = glm::mat4(1.f);
	glm::mat4 rightLegRotateMtx = glm::mat4(1.f);
	glm::vec3 leftHandAngle, rightHandAngle, leftLegAngle, rightLegAngle;

	Material material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
};