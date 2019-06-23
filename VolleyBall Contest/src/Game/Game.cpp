#include "include/Game/Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	stateStartTime = _var::now;

	update();

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