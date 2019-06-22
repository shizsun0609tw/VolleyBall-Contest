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
}

void Game::draw() {
	scene.draw();
	redTeam.draw();
	blueTeam.draw();
	player.draw();
}