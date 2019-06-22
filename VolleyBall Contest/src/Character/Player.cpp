#include "include/Character/Player.h"

void Player::update() {
	if (Control::action != GLFW_RELEASE) {
		if (Control::key == GLFW_KEY_W) {
			Character::move(glm::vec3(5.f, 0.f, 0.f));
		}
		else if (Control::key == GLFW_KEY_S) {

		}
		else if (Control::key == GLFW_KEY_A) {

		}
		else if (Control::key == GLFW_KEY_D) {

		}
	}
	
	Character::update();
}