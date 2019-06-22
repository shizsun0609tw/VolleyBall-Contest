#include "include/Character/Character.h"

void Character::draw() {
	glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec4(0.1f,0.1f,0.8f,1.f)));
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
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.2f, 0.3f, 0.2f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	/* right hand LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x/4, size.y/6, size.z/2));
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, -0.05f, 0.04f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	_var::model.top() = _var::model.top() * rightUpHandRotateMtx;
	/* up hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* down hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 8, 0.f));
	_var::model.top() = _var::model.top() * rightDownHandRotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, size.y/8, 0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	_var::model.pop();
	_var::model.pop();


	/* left hand LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x / 4, size.y / 6, -size.z / 2));
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, -0.05f, 0.05f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	_var::model.top() = _var::model.top() * leftUpHandRotateMtx;
	/* up hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* down hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 8, 0.f));
	_var::model.top() = _var::model.top() * leftDownHandRotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8 * 3.5 / 4, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, size.y / 8, 0.05f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	_var::model.pop();
	_var::model.pop();

	/* left leg LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x/5, -size.y/8, -size.z/3));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-0.03f, 0.f, 0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	/* up leg */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = _var::model.top() * leftUpLegRotateMtx;
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.03f, size.y / 8 * 3.5 / 2, 0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	/* down leg */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 8 * 3.5 / 2, 0.f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8 * 3.5 / 2, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();

	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y/8*3.5/2, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	_var::model.pop();

	/* right leg LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x / 5, -size.y/8, size.z / 3));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(-0.03f, 0.f, -0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	/* up leg */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	_var::model.top() = _var::model.top() * rightUpLegRotateMtx;
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.03f, size.y / 8 * 3.5 / 2, 0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	/* down leg */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 8 * 3.5 / 2, 0.f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 8 * 3.5 / 2, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();

	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y/8*3.5/2, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	_var::model.pop();
}

void Character::update() {

}

void Character::run() {
	pos += glm::vec3(0.01f, 0.f, 0.f);

	static int dir = 1;
	const float speed = 1.f;

	if (leftUpLegAngle.z > 20.f) dir = -1;
	if (leftUpLegAngle.z < -20.f) dir = 1;

	glm::vec3 pastAngle = leftUpLegAngle;
	leftUpLegAngle.z += dir * speed;
	leftUpLegRotateMtx = glm::rotate(leftUpLegRotateMtx, glm::radians(leftUpLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	
	pastAngle = rightUpLegAngle;
	rightUpLegAngle.x += dir * speed;
	rightUpLegRotateMtx = glm::rotate(rightUpLegRotateMtx, glm::radians(rightUpLegAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));


	pastAngle = leftUpHandAngle;
	leftUpHandAngle.x += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));


	pastAngle = rightUpHandAngle;
	rightUpHandAngle.z += dir * speed;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	if (leftDownHandAngle.x < 90.f) {
		pastAngle = leftDownHandAngle;
		leftDownHandAngle.x += speed * 2;
		leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	}
	
	if (rightDownHandAngle.z < 90.f) {
		pastAngle = rightDownHandAngle;
		rightDownHandAngle.z += speed * 2;
		rightDownHandRotateMtx = glm::rotate(rightDownHandRotateMtx, glm::radians(rightDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	}
	
}