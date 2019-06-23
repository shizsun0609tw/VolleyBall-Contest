#include "include/Game/Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	static bool init = false;
	static int blueHit = 0, redHit = 0;

	if (state == State::start && init == false) {
		update();
		init = true;
		stateStartTime = _var::now;
	}
	else if (state == State::start && Control::controlTable[GLFW_KEY_ENTER] == true) {
		state = State::prepare;
		stateStartTime = _var::now;
	}
	else if (state == State::prepare) {
		update();
		blueHit = 0; redHit = 0;
		if (PhysicsEngine::calPassTime(stateStartTime, _var::now) > 5.f) {
			state = State::play;
			if (control == BallControl::blueTeam) {
				blueTeam.start(scene.volleyBall);
				redTeam.reset();
			}
			else if (control == BallControl::redTeam) {
				redTeam.start(scene.volleyBall);
				blueTeam.reset();
			}
			stateStartTime = _var::now;
		}
	}
	else if (state == State::play) {
		update();
		if (blueHit != blueTeam.hit) {
			control = BallControl::blueTeam;
			redTeam.hit = 0;
			blueHit = blueTeam.hit;
		}
		else if (redHit != redTeam.hit) {
			control = BallControl::redTeam;
			blueTeam.hit = 0;
			redHit = redTeam.hit;
		}
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
	redTeam.update(scene.volleyBall);
	blueTeam.update(scene.volleyBall);
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

	if (pos.y - size.y < 0.f
		|| pos.x > 11.f || pos.x < -11.f || pos.z > 7.5f || pos.z < -7.5f) {
		if (control == BallControl::blueTeam) {
			redTeam.score++;
			control = BallControl::redTeam;
		}
		else {
			blueTeam.score++;
			control = BallControl::blueTeam;
		}
	}

	return false;
}