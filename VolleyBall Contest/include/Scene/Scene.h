#pragma once
#include "include/Header/_var.h"
#include "include/Scene/Ground.h"
#include "include/Scene/Net.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"

class Scene {
public:
	Scene() {}
	~Scene() {}
	void update(){
		volleyBall.update();
	}
	void draw() {
		ground.draw();
		net.draw();
		volleyBall.draw();
	}
	Ground ground;
	Net net;
	VolleyBall volleyBall = VolleyBall(glm::vec3(0.f, 3.f, 0.f), glm::vec3(0.f), glm::vec3(0.21f));
};