#pragma once

#include "include/GraphicEngine/BasicModel.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/Header/_var.h"
#include "include/glm/glm.hpp"

class Net {
public:
	Net() {}
	~Net() {}
	void draw() {
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.95f, 0.95f, 0.95f)));

		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), -glm::vec3(0.f, 0.f, 5.f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.3f, 2.43f,0.3f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, 0.f, 4.7f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.3f, 2.43f, 0.3f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();
		
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.1f, 1.43f, -4.7f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.1f, 1.f, 9.5f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();
	}
};