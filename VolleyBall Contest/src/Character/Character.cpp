#include "include/Character/Character.h"

void Character::draw() {
	glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec4(0.1f,0.1f,0.8f,1.f)));
	material.sendData(_var::shader);

	_var::model.push(_var::model.top());

	/* translate and rotate to root */
	_var::model.top() = glm::translate(_var::model.top(), pos);
	_var::model.top() = _var::model.top() * rotateMtx;
	_var::model.top() = glm::translate(_var::model.top(), bodyTranslate);
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
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y/5, size.z/2));
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, 0.015f, 0.04f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	_var::model.top() = _var::model.top() * rightUpHandRotateMtx;
	/* up hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 7, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* down hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 7, 0.f));
	_var::model.top() = _var::model.top() * rightDownHandRotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 7, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, size.y/7, 0.03f));
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();
	_var::model.pop();
	_var::model.pop();


	/* left hand LCS */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(size.x / 2, size.y / 5, -size.z / 2));
	_var::model.push(_var::model.top());
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(180.f), glm::vec3(0.f, 0.f, 1.f));
	_var::model.top() = glm::rotate(_var::model.top(), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, 0.015f, 0.05f)); ///////////////
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(0.15f));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::ball);
	_var::model.pop();

	_var::model.top() = _var::model.top() * leftUpHandRotateMtx;
	/* up hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 7, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* down hand */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.f, size.y / 7, 0.f));
	_var::model.top() = _var::model.top() * leftDownHandRotateMtx;
	_var::model.top() = glm::scale(_var::model.top(), glm::vec3(size.x / 2, size.y / 7, size.x / 2));
	_var::sendData();
	VAOManagement::drawVAO(BasicModel::cube);
	_var::model.pop();
	/* joint */
	_var::model.push(_var::model.top());
	_var::model.top() = glm::translate(_var::model.top(), glm::vec3(0.05f, size.y / 7, 0.05f));
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
	_var::model.top() = _var::model.top() * leftDownLegRotateMtx;
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
	_var::model.top() = _var::model.top() * rightDownLegRotateMtx;
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
	updateAnimation();

}

void Character::updateAnimation() {
	if (chrono::duration_cast<chrono::milliseconds>(_var::now - animationStartTime).count() / 1000.f > 2) {
		clearRotate();
		animationStartTime = _var::now;
		anim = Animation::idle;
	}

	if (anim == Animation::jump) jump();
	else if (anim == Animation::attack) attack();
	else if (anim == Animation::jumpAttack) jumpAttack();
	else if (anim == Animation::run) run();
	else if (anim == Animation::overhand) overhand();
	else if (anim == Animation::underhand) underhand();
	else if (anim == Animation::idle);
}

void Character::run() {
	static int dir = 1;
	const float speed = _var::time * 92.3;

	if (leftUpLegAngle.z > 20.f) dir = -1;
	if (leftUpLegAngle.z < -20.f) dir = 1;
	/*left leg */
	glm::vec3 pastAngle = leftUpLegAngle;
	leftUpLegAngle.z += dir * speed;
	leftUpLegRotateMtx = glm::rotate(leftUpLegRotateMtx, glm::radians(leftUpLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	
	/* right leg */
	pastAngle = rightUpLegAngle;
	rightUpLegAngle.x += dir * speed;
	rightUpLegRotateMtx = glm::rotate(rightUpLegRotateMtx, glm::radians(rightUpLegAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));

	/* left hand */
	pastAngle = leftUpHandAngle;
	leftUpHandAngle.x += dir * speed * 2.0;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));

	/* right hand */
	pastAngle = rightUpHandAngle;
	rightUpHandAngle.z += dir * speed * 2.0;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	if (leftDownHandAngle.x < 90.f) {
		pastAngle = leftDownHandAngle;
		leftDownHandAngle.x += speed * 2;
		leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	}
	else {
		pastAngle = leftDownHandAngle;
		leftDownHandAngle.x += speed * 0.8;
		leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));
	}
	
	if (rightDownHandAngle.z < 90.f) {
		pastAngle = rightDownHandAngle;
		rightDownHandAngle.z += speed * 2;
		rightDownHandRotateMtx = glm::rotate(rightDownHandRotateMtx, glm::radians(rightDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	}
	else {
		pastAngle = rightDownHandAngle;
		rightDownHandAngle.z += speed * 0.8;
		rightDownHandRotateMtx = glm::rotate(rightDownHandRotateMtx, glm::radians(rightDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));
	}
}

void Character::overhand() {
	static int dir = 1;
	const float speed = _var::time * 140;

	glm::vec3 pastAngle = leftUpHandAngle;
	
	if (leftUpHandAngle.x > 120.f) dir = -1;
	if (leftUpHandAngle.x < 0.f) dir = 1;
	/* left hand */
	leftUpHandAngle.x += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftUpHandAngle.z += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	pastAngle = leftDownHandAngle;
	leftDownHandAngle.x += dir * speed * 0.5f;
	leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	
	/* right hand */
	pastAngle = rightUpHandAngle;
	rightUpHandAngle.x += dir * speed;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));
	rightUpHandAngle.z += dir * speed;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	pastAngle = rightDownHandAngle;
	rightDownHandAngle.z += dir * speed * 0.5f;
	rightDownHandRotateMtx = glm::rotate(rightDownHandRotateMtx, glm::radians(rightDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
}

void Character::underhand() {
	static int dir = 1;
	const float speed = _var::time * 35;

	glm::vec3 pastAngle = leftUpHandAngle;

	if (leftUpHandAngle.x > 30.f) dir = -1;
	if (leftUpHandAngle.x < 0.f) dir = 1;

	/* left hand */
	leftUpHandAngle.x += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftUpHandAngle.z += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	/* right hand */
	rightUpHandAngle.x += dir * speed;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	rightUpHandAngle.z += dir * speed;
	rightUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	/* left leg */
	pastAngle = leftUpLegAngle;
	leftUpLegAngle.z += dir * speed * 2;
	leftUpLegRotateMtx = glm::rotate(leftUpLegRotateMtx, glm::radians(leftUpLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	pastAngle = leftDownLegAngle;
	leftDownLegAngle.z += dir * speed;
	leftDownLegRotateMtx = glm::rotate(leftDownLegRotateMtx, glm::radians(leftDownLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	/* right leg */
	pastAngle = rightUpLegAngle;
	rightUpLegAngle.x += dir * speed * 0.5;
	rightUpLegRotateMtx = glm::rotate(rightUpLegRotateMtx, glm::radians(rightUpLegAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));

	pastAngle = rightDownLegAngle;
	rightDownLegAngle.x += dir * speed;
	rightDownLegRotateMtx = glm::rotate(rightDownLegRotateMtx, glm::radians(rightDownLegAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));

	/* body rotate */
	pastAngle = angle;
	angle.z += dir * speed * 0.7;
	rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));
}

void Character::attack() {
	static int dir = 1;
	const float speed = _var::time * 116.5;

	glm::vec3 pastAngle = leftUpHandAngle;

	if (leftUpHandAngle.x > 100.f) dir = -1;
	if (leftUpHandAngle.x < 0.f) dir = 1;
	/* left hand */
	leftUpHandAngle.x += dir * speed;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftUpHandAngle.z += dir * speed * 0.5;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	pastAngle = leftDownHandAngle;
	leftDownHandAngle.x += dir * speed * 0.5f;
	leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftDownHandAngle.z += dir * speed * 0.5f;
	leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	/* right hand */
	pastAngle = rightUpHandAngle;
	rightUpHandAngle.z += dir * speed * 1.75;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

}

void Character::jump() {
	static int dir = 1;
	const float speed = _var::time * 58;

	if (leftUpLegAngle.z > 50.f) {
		dir = -1;
	}
	if (leftUpLegAngle.z < 0.f) {
		dir = 1;
	}

	bodyTranslate += glm::vec3(0.f, speed * -dir * 0.001f, 0.f);

	/*left leg */
	glm::vec3 pastAngle = leftUpLegAngle;
	leftUpLegAngle.z += dir * speed;
	leftUpLegRotateMtx = glm::rotate(leftUpLegRotateMtx, glm::radians(leftUpLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	pastAngle = leftDownLegAngle;
	leftDownLegAngle.z += dir * speed * 2;
	leftDownLegRotateMtx = glm::rotate(leftDownLegRotateMtx, glm::radians(leftDownLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	/* right leg */
	pastAngle = rightUpLegAngle;
	rightUpLegAngle.x += dir * speed;
	rightUpLegRotateMtx = glm::rotate(rightUpLegRotateMtx, glm::radians(rightUpLegAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));

	pastAngle = rightDownLegAngle;
	rightDownLegAngle.x += dir * speed * 2;
	rightDownLegRotateMtx = glm::rotate(rightDownLegRotateMtx, glm::radians(rightDownLegAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));
}

void Character::jumpAttack() {
	static int dir = 1;
	const float speedJ = _var::time * 58;
	/*----------jump----------*/
	if (leftUpLegAngle.z > 50.f) {
		dir = -1;
	}
	if (leftUpLegAngle.z < 0.f) {
		dir = 1;
	}
	
	bodyTranslate += glm::vec3(0.f, speedJ * -dir * 0.001f, 0.f);

	/*left leg */
	glm::vec3 pastAngle = leftUpLegAngle;
	leftUpLegAngle.z += dir * speedJ;
	leftUpLegRotateMtx = glm::rotate(leftUpLegRotateMtx, glm::radians(leftUpLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	pastAngle = leftDownLegAngle;
	leftDownLegAngle.z += dir * speedJ * 2;
	leftDownLegRotateMtx = glm::rotate(leftDownLegRotateMtx, glm::radians(leftDownLegAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	/* right leg */
	pastAngle = rightUpLegAngle;
	rightUpLegAngle.x += dir * speedJ;
	rightUpLegRotateMtx = glm::rotate(rightUpLegRotateMtx, glm::radians(rightUpLegAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));

	pastAngle = rightDownLegAngle;
	rightDownLegAngle.x += dir * speedJ * 2;
	rightDownLegRotateMtx = glm::rotate(rightDownLegRotateMtx, glm::radians(rightDownLegAngle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));

	/*----------attack----------*/
	pastAngle = leftUpHandAngle;

	const float speedA = _var::time * 116.5;
	if (leftUpHandAngle.x > 100.f) dir = -1;
	if (leftUpHandAngle.x < 0.f) dir = 1;
	/* left hand */
	leftUpHandAngle.x += dir * speedA;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftUpHandAngle.z += dir * speedA * 0.5;
	leftUpHandRotateMtx = glm::rotate(leftUpHandRotateMtx, glm::radians(leftUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, -1.f));

	pastAngle = leftDownHandAngle;
	leftDownHandAngle.x += dir * speedA * 0.5f;
	leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.x - pastAngle.x), glm::vec3(-1.f, 0.f, 0.f));
	leftDownHandAngle.z += dir * speedA * 0.5f;
	leftDownHandRotateMtx = glm::rotate(leftDownHandRotateMtx, glm::radians(leftDownHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));

	/* right hand */
	pastAngle = rightUpHandAngle;
	rightUpHandAngle.z += dir * speedA * 1.75;
	rightUpHandRotateMtx = glm::rotate(rightUpHandRotateMtx, glm::radians(rightUpHandAngle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
}

void Character::playAnimation(Animation anim) {
	animationStartTime = _var::now;
	this->anim = anim;
}

void Character::clearRotate() {
	leftUpHandRotateMtx = glm::mat4(1.f);
	rightUpHandRotateMtx = glm::mat4(1.f);
	leftUpLegRotateMtx = glm::mat4(1.f);
	rightUpLegRotateMtx = glm::mat4(1.f);
	leftDownHandRotateMtx = glm::mat4(1.f);
	rightDownHandRotateMtx = glm::mat4(1.f);
	leftDownLegRotateMtx = glm::mat4(1.f);
	rightDownLegRotateMtx = glm::mat4(1.f);

	leftUpHandAngle = glm::vec3(0.f);
	rightUpHandAngle = glm::vec3(0.f);
	leftDownHandAngle = glm::vec3(0.f);
	rightDownHandAngle = glm::vec3(0.f);
	leftUpLegAngle = glm::vec3(0.f);
	rightUpLegAngle = glm::vec3(0.f);
	leftDownLegAngle = glm::vec3(0.f);
	rightDownLegAngle = glm::vec3(0.f);

	bodyTranslate = glm::vec3(0.f);
}

void Character::animationTest() {
	static int test = 1;
	if (test == 1) {
		playAnimation(Animation::run);
		test = 2;
	}
	else if (test == 2 && anim == Animation::idle) {
		playAnimation(Animation::attack);
		test = 3;
	}
	else if (test == 3 && anim == Animation::idle) {
		playAnimation(Animation::jump);
		test = 4;
	}
	else if (test == 4 && anim == Animation::idle) {
		playAnimation(Animation::jumpAttack);
		test = 5;
	}
	else if (test == 5 && anim == Animation::idle) {
		playAnimation(Animation::overhand);
		test = 6;
	}
	else if (test == 6 && anim == Animation::idle) {
		playAnimation(Animation::underhand);
		test = 7;
	}
}