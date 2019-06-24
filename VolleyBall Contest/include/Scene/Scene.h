#pragma once
#include "include/Header/_var.h"
#include "include/Scene/Ground.h"
#include "include/Scene/Net.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"
#include <cmath>

class Scene {
public:
	Scene() {}
	~Scene() {}
	void update(){
		netCollision();
		volleyBall.update();
	}
	void draw() {
		ground.draw();
		net.draw();
		volleyBall.draw();
	}
	void netCollision() {
		glm::vec3 pos = volleyBall.getPos();
		glm::vec3 size = volleyBall.getSize();
		glm::vec3 v = volleyBall.getVelocity();
	
		if (glm::distance(glm::vec3(pos.x, 0.f, 0.f), glm::vec3(0.f)) < size.x
			&& glm::distance(glm::vec3(0.f, pos.y, 0.f),glm::vec3(0.f, 1.93f, 0.f)) < size.y + 0.5f
			&& glm::distance(glm::vec3(0.f, 0.f, pos.z), glm::vec3(0.f)) < size.z + 4.75f) {
			if (pos.x > 0) volleyBall.setPos(glm::vec3(pos.x + 0.01f, pos.y, pos.z));
			else volleyBall.setPos(glm::vec3(pos.x - 0.01f, pos.y, pos.z));
			
			volleyBall.setVelocity(glm::vec3(0.f));
		}
	}
	Ground ground;
	Net net;
	VolleyBall volleyBall = VolleyBall(glm::vec3(0.2f, 3.f, 0.f), glm::vec3(0.f), glm::vec3(0.21f));
};