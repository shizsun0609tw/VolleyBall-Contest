#include "include/Character/Player.h"

void Player::update() {
	Animation anim = getAnim();
	if (Control::controlTable[GLFW_KEY_W] && (anim == Animation::idle || anim == Animation::run)) {
		Character::move(glm::vec3(4.5f, 0.f, 0.f));
		if (anim == Animation::idle) playAnimation(Animation::run);
	}
	else if (Control::controlTable[GLFW_KEY_S] && (anim == Animation::idle || anim == Animation::run)) {
		Character::move(glm::vec3(-3.f, 0.f, 0.f));
		if (anim == Animation::idle) playAnimation(Animation::run);
	}
	else if (!Control::controlTable[GLFW_KEY_S] && !Control::controlTable[GLFW_KEY_W] && anim == Animation::run) {
		Character::playAnimation(Animation::idle);
	}

	if (Control::controlTable[GLFW_KEY_A] && (anim == Animation::idle || anim == Animation::run)) {
		Character::rotate(glm::vec3(0.f, 100.f, 0.f));
	}
	else if (Control::controlTable[GLFW_KEY_D] && (anim == Animation::idle || anim == Animation::run)) {
		Character::rotate(glm::vec3(0.f, -100.f, 0.f));
	}
	
	if (Control::controlTable[GLFW_KEY_KP_4] && (anim == Animation::idle || anim == Animation::run)) {
		Character::playAnimation(Animation::attack);
	}
	if (Control::controlTable[GLFW_KEY_KP_5] && (anim == Animation::idle || anim == Animation::run)) {
		Character::playAnimation(Animation::jump);
	}
	if (Control::controlTable[GLFW_KEY_KP_6] && (anim == Animation::idle || anim == Animation::run)) {
		Character::playAnimation(Animation::underhand);
	}
	if (Control::controlTable[GLFW_KEY_KP_7] && (anim == Animation::idle || anim == Animation::run)) {
		Character::playAnimation(Animation::overhand);
	}
	if (Control::controlTable[GLFW_KEY_KP_8] && (anim == Animation::idle || anim == Animation::run)) {
		Character::playAnimation(Animation::jumpAttack);
	}



	Character::update();
}