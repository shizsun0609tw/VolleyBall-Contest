#include "include/Game/Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	static bool init = false;
	if (state == State::start && init == false) {
		update();
		init = true;
		stateStartTime = _var::now;
	}
	else if (state == State::start && Control::controlTable[GLFW_KEY_ENTER] == true) {
		state = State::prepare;
		stateStartTime = _var::now;
		blueTeam.reset();
		redTeam.reset();
	}
	else if (state == State::prepare) {
		update();
		if (PhysicsEngine::calPassTime(stateStartTime, _var::now) > 5.f) {
			state = State::start;
			control == BallControl::blueTeam ? blueTeam.start() : redTeam.start();
			stateStartTime = _var::now;
		}
	}
	else if (state == State::play) {
		update();
		if (volleyballDetection()) {
			state = State::prepare;
			stateStartTime = _var::now;
			blueTeam.reset();
			redTeam.reset();
		}
	}
	else if (state == State::end) {
		state = State::start;
	}

	if (redTeam.score == 11 || blueTeam.score == 11) {
		state = State::end;
		cout << (redTeam.score == 11 ? "Red Team win the Contest !" : "Blue Team win the Contest !") << endl;
	}

	draw();
}

void Game::update() {
	scene.update();
	redTeam.update(scene.volleyBall.getPos(), scene.volleyBall.getVelocity());
	blueTeam.update(scene.volleyBall.getPos(), scene.volleyBall.getVelocity());
	player.update();
	_var::eye.lookPos = player.getPos();
	_var::update();
}

void Game::draw() {
	scene.draw();
	redTeam.draw();
	blueTeam.draw();
	player.draw();
}

bool Game::volleyballDetection() {
	glm::vec3 pos = scene.volleyBall.getPos();
	glm::vec3 size = scene.volleyBall.getSize();

	if (pos.y - size.y < 0.f) {

	}
	if (pos.x > 11.f || pos.x < -11.f || pos.z > 7.5f || pos.z < -7.5f) {

	}
	return false;
}