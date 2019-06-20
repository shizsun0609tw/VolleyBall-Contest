#pragma once

#include "include/Reader/Reader.h"
#include "include/Header/_var.h"
#include "include/GraphicEngine/VAO.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/BasicModel.h"
#include "include/glm/glm.hpp"
#include <chrono>
#include <vector>

enum class Animation { jump, attack, jumpAttack, run, overhand, underhand, idle};

class Character {
public:
	Character() {}
	Character(glm::vec3 pos, glm::vec3 angle, glm::vec3 size)
		: pos(pos), angle(angle), size(size) {}

	~Character() {}
	void update();
	void draw();
	void playAnimation(Animation anim);
	Animation getAnim() { return anim; }

	void animationTest();
protected:
	glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 angle = glm::vec3(0.f);
	glm::vec3 size = glm::vec3(1.f);
private:
	/* update */
	void updateAnimation();

	/* animation */
	void run();
	void overhand();
	void underhand();
	void attack();
	void jump();
	void jumpAttack();
	void clearRotate();

	/* LCS attrib */
	glm::mat4 leftUpHandRotateMtx = glm::mat4(1.f);
	glm::mat4 rightUpHandRotateMtx = glm::mat4(1.f);
	glm::mat4 leftUpLegRotateMtx = glm::mat4(1.f);
	glm::mat4 rightUpLegRotateMtx = glm::mat4(1.f);
	glm::mat4 leftDownHandRotateMtx = glm::mat4(1.f);
	glm::mat4 rightDownHandRotateMtx = glm::mat4(1.f);
	glm::mat4 leftDownLegRotateMtx = glm::mat4(1.f);
	glm::mat4 rightDownLegRotateMtx = glm::mat4(1.f);

	glm::vec3 leftUpHandAngle = glm::vec3(0.f);
	glm::vec3 rightUpHandAngle = glm::vec3(0.f);
	glm::vec3 leftDownHandAngle = glm::vec3(0.f);
	glm::vec3 rightDownHandAngle = glm::vec3(0.f);
	glm::vec3 leftUpLegAngle = glm::vec3(0.f);
	glm::vec3 rightUpLegAngle = glm::vec3(0.f);
	glm::vec3 leftDownLegAngle = glm::vec3(0.f);
	glm::vec3 rightDownLegAngle = glm::vec3(0.f);

	glm::mat4 rotateMtx = glm::mat4(1.f);

	glm::vec3 bodyTranslate = glm::vec3(0.f);

	/* anim attrib */
	Animation anim = Animation::idle;
	chrono::time_point<chrono::steady_clock> animationStartTime;

	/* color attrib */
	Material material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
};