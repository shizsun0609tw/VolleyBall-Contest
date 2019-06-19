#pragma once

#include "include/glm/glm.hpp"
#include "include/GraphicEngine/VAO.h"
#include "include/GraphicEngine/BasicModel.h"
#include "include/GraphicEngine/Texture.h"
#include "include/GraphicEngine/Material.h"
#include "include/Header/_var.h"

class VolleyBall {
public:
	VolleyBall() {}
	VolleyBall(glm::vec3 pos, glm::vec3 angle, glm::vec3 size)
		: pos(pos), angle(angle), size(size) {
		texture = TextureManagement::generateTexture(Reader::readBMP(string(_getcwd(NULL, 0)) + "\\Assets\\VolleyBall.bmp"));
	}

	~VolleyBall() {}
	void update();
	void draw();
private:
	glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 angle = glm::vec3(0.f);
	glm::mat4 rotateMtx = glm::mat4(1.f);
	glm::vec3 size = glm::vec3(1.f);

	Material material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
	Texture texture;
};