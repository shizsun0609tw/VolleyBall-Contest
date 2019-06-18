#pragma once

#include "include/Reader/Reader.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/PhysicsEngine/PhysicsEngine.h"

class Test {
public:
	Test() {
		vao = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\ball.obj");
		material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
	}
	~Test() {}

	void update() {
		updateAttrib();
		updateGesture();
	}

	void draw() {
		_var::model.push(_var::model.top());
		
		_var::model.top() = glm::translate(_var::model.top(), pos);
		_var::model.top() = _var::model.top() * rotateMtx;

		material.sendData(_var::shader);
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.25f)));
		_var::sendData();

		VAOManagement::drawVAO(vao);

		_var::model.pop();
	}
private:
	vector<VAO> vao;
	Material material;

	glm::vec3 pos;
	glm::vec3 angle;

	glm::mat4 rotateMtx = glm::mat4(1.f);

	void updateAttrib() {}
	void updateGesture() {
		// TODO use force to update pos
		//pos = PhysicsEngine::calPosition(pos, glm::vec3(0.01f, 0.f, 0.f), _var::time);

		glm::vec3 pastAngle = angle;
		// TODO use torque to update angle
		// angle.y += 0.05f;

		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));
		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.y - pastAngle.y), glm::vec3(0.f, 1.f, 0.f));
		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	}
};