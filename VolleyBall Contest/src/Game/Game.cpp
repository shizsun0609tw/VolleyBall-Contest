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
	redTeam.update();
	blueTeam.update();
	player.update();
	player1.update();
	player2.update();
	_var::eye.lookPos = player.getPos();
	_var::update();
}

void Game::draw() {
	scene.draw();
	redTeam.draw();
	blueTeam.draw();
	player.draw();
	player1.draw();
	player2.draw();
}