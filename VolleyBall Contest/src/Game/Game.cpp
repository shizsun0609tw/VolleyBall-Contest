#include "include/Game/Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	if (state == State::prepare) {
		update();
		volleyballDetection();
		if (Control::controlTable[GLFW_KEY_ENTER] == true) {
			blueHit = 0; redHit = 0;
			state = State::play;
			if (control == BallControl::blueTeam) {
				blueTeam.start(scene.volleyBall);
				redTeam.reset();
			}
			else if (control == BallControl::redTeam) {
				redTeam.start(scene.volleyBall);
				blueTeam.reset();
			}
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
			glm::vec3 pos = scene.volleyBall.getPos();
			if (control == BallControl::blueTeam) {
				if (pos.x < 0 || (pos.x > 9.f || pos.z > 4.5f || pos.z < -4.5f)) {
					redTeam.score++;
					control = BallControl::redTeam;
				}
				else {
					blueTeam.score++;
					control = BallControl::blueTeam;
				}
			}
			else if (control == BallControl::redTeam) {
				if (pos.x > 0 || (pos.x <  -9.f || pos.z > 4.5f || pos.z < -4.5f)) {
					blueTeam.score++;
					control = BallControl::blueTeam;
				}
				else {
					redTeam.score++;
					control = BallControl::redTeam;
				}
			}
			state = State::prepare;
			cout << "=========================================" << endl;
			cout << "Red Team Score: " << redTeam.score << endl;
			cout << "Blue Team Score: " << blueTeam.score << endl;
		}
	}
	else if (state == State::end) {
		cout << "=========================================" << endl;
		cout << (redTeam.score == 11 ? "Red Team win the Contest !" : "Blue Team win the Contest !") << endl;
		redTeam.score = 0; blueTeam.score = 0;
	}

	if (redTeam.score == 11 || blueTeam.score == 11) {
		state = State::end;
	}

	_var::update();

	draw();
}

void Game::update() {
	scene.update();
	redTeam.update(scene.volleyBall);
	blueTeam.update(scene.volleyBall);
	player.update(scene.volleyBall);
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
	glm::vec3 v = scene.volleyBall.getVelocity();

	if (pos.y - size.y < 0.f
		|| pos.x > 11.f || pos.x < -11.f || pos.z > 7.5f || pos.z < -7.5f) {
		scene.volleyBall.setPos(glm::vec3(pos.x, pos.y + 0.01f, pos.z));
		scene.volleyBall.setVelocity(glm::vec3(v.x, -v.y, v.z));
		return true;
	}
	return false;
}