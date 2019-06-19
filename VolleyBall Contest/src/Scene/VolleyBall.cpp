#include "include/Scene/VolleyBall.h"

void VolleyBall::update() {

}

void VolleyBall::draw() {
	glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec4(0.25f, 0.25f, 0.25f, 1.f)));
	glUniform1f(glGetUniformLocation(_var::shader.shaderProgram, "useTexture"), 1.f);
	material.sendData(_var::shader);
	glBindTexture(GL_TEXTURE_2D, texture.texture);

	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), pos);
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), size);
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	glUniform1f(glGetUniformLocation(_var::shader.shaderProgram, "useTexture"), 0.f);
}