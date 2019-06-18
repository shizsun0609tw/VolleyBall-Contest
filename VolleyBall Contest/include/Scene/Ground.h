#pragma once

#include "include/GraphicEngine/BasicModel.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/Header/_var.h"
#include "include/glm/glm.hpp"

class Ground {
public:
	Ground() {}
	~Ground() {}
	void draw() {
		/* yellow ground */
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.95f, 0.61f, 0.31f)));
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), -glm::vec3(size.x / 2, size.y / 2, size.z / 2));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(18.f, 0.1f, 9.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		/* green ground */
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.38f, 0.59f, 0.38f)));
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), -glm::vec3(size.x / 2 + 2, size.y / 2, size.z / 2 + 2));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(22.f, 0.099f, 13.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		/* line */
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.95f, 0.95f, 0.95f)));
		/* middle line */
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.1f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 0.001f, 8.9f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		/* 3m line */
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(3.f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 0.001f, 9.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();
		
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-2.9f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 0.001f, 9.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		/* edge line */
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(8.9f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 0.001f, 9.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-9.f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 0.001f, 9.f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();
		
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-9.f, 0.05f, -4.5f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(18.f, 0.001f, 0.1f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-9.f, 0.05f, 4.4f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(18.f, 0.001f, 0.1f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();
	}
private:
	glm::vec3 size = glm::vec3(18.f, 0.1f, 9.f);
};