#pragma once
#include "include/GraphicEngine/BasicModel.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/Header/_var.h"
#include "include/Scene/Ground.h"
#include "include/Scene/Net.h"
#include "include/Scene/VolleyBall.h"
#include "include/glm/glm.hpp"

class Scene {
public:
	Scene() {}
	~Scene() {}
	void draw() {
		ground.draw();
		net.draw();
		volleyBall.draw();
	}
private:
	Ground ground;
	Net net;
	VolleyBall volleyBall = VolleyBall(glm::vec3(0.f, 0.3f, 0.f), glm::vec3(0.f), glm::vec3(0.21f));
};