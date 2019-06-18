#include "include/Character/Character.h"

void Character::draw() {
	glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.25f)));
	material.sendData(_var::shader);

	_var::model.push(_var::model.top());

	/* translate and rotate to root */
	_var::model.top() = glm::translate(_var::model.top(), pos);
	_var::model.top() = _var::model.top() * rotateMtx;
	/* body LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-size.x/2, -size.y/8, -size.z/2));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x, size.y/8*3, size.z));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* head LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y/8*3, 0.f));
	//_var::model.top() = _var::model.top() * headRotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.2f, 0.3f, 0.2f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	/* right hand LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-size.x/3, size.y/6, size.z/2));
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x/2, size.y/8*3.5, size.x/2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* left hand LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-size.x / 3, size.y / 6, -size.z / 2));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y/8*3.5, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* left leg LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x/5, -size.y/8, -size.z/3));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y/8*3.5, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* right leg LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x / 5, -size.y/8, size.z / 3));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y/8*3.5, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();

	_var::model.pop();
}

void Character::update() {

}