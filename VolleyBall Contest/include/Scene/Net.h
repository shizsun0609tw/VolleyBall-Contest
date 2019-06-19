#pragma once

#include "include/GraphicEngine/BasicModel.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/GraphicEngine/Texture.h"
#include "include/Reader/Reader.h"
#include "include/Header/_var.h"
#include "include/glm/glm.hpp"
#include "direct.h"

class Net {
public:
	Net() {
		texture = TextureManagement::generateTexture(Reader::readBMP(string(_getcwd(NULL, 0)) + "\\Assets\\Net.bmp"));
	}
	~Net() {}
	void draw() {
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec4(0.95f, 0.95f, 0.95f, 1.f)));

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

		glUniform1f(glGetUniformLocation(_var::shader.shaderProgram, "useTexture"), 1.f);
		glBindTexture(GL_TEXTURE_2D, texture.texture);
		
		_var::model.push(_var::model.top());
		_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.1f, 1.43f, -4.7f));
		_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.00001f, 1.f, 9.5f));
		_var::sendData();
		VAOManagement::drawVAO(BasicModel::cube);
		_var::model.pop();

		
		glBindTexture(GL_TEXTURE_2D, 0);
		glUniform1f(glGetUniformLocation(_var::shader.shaderProgram, "useTexture"), 0.f);
	}
private:
	Texture texture;
};