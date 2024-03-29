#pragma once

#include "include/Reader/Reader.h"
#include "include/Header/_var.h"
#include "include/GraphicEngine/VAO.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/BasicModel.h"
#include "include/PhysicsEngine/PhysicsEngine.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"
#include <chrono>
#include <iostream>
enum class Animation { jump, attack, jumpAttack, run, overhand, underhand, idle};

class Character {
public:
	Character() {}
	Character(glm::vec3 pos, glm::vec3 angle, glm::vec3 size, glm::vec3 color)
		: pos(pos), angle(angle), size(size), color(color) {
		update();
	}

	~Character() {}
	void update();
	void draw();
	void rotate(glm::vec3 angle) { this->angle += angle * _var::time;}
	void playAnimation(Animation anim);
	void move(Velocity velocity);
	void moveWorld (Velocity velocity);
	void addForce(Force force) { f += force; }
	void setVelocity(Velocity velocity) { v = velocity; }
	Animation getAnim() { return anim; }
	glm::vec3 getPos() { return pos; }
	glm::mat4 getMtx() { cout << rotateMtx[0][0]; return rotateMtx; }
	// decide where ball go
	int BallGo(int hit, int team);
	// hit the ball
	bool batting(Animation anim, int team, int hit, VolleyBall &ball);
	// compute the velocity to hit ball
	glm::vec3 hitBall(int type, int team, int goal);

	void animationTest();
private:
	glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 angle = glm::vec3(0.f);
	glm::vec3 size = glm::vec3(0.21f);
	/* physics attrib */
	Mass m = 65;
	Force f = glm::vec3(0.f);
	Acceleration a = glm::vec3(0.f);
	Velocity v = glm::vec3(0.f);
	/* update */
	void updateAnimation();
	void updateGesture();
	void collisionScene();
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
	glm::vec3 pastBodyAngle = glm::vec3(0.f);
	glm::vec3 moveX = glm::vec3(1.f, 0.f, 0.f);
	glm::vec3 moveY = glm::vec3(0.f, 1.f, 0.f);
	glm::vec3 moveZ = glm::vec3(0.f, 0.f, 1.f);
	/* anim attrib */
	Animation anim = Animation::idle;
	chrono::time_point<chrono::steady_clock> animationStartTime;
	/* color attrib */
	Material material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
	glm::vec3 color;
};