#pragma once
#include "include/Character/BlueTeam.h"
#include "include/Character/RedTeam.h"
#include "include/Character/Player.h"
#include "include/Header/Control.h"
#include "include/Scene/Scene.h"
#include "include/Header/_var.h"
#include "include/PhysicsEngine/PhysicsEngine.h"
#include "include/glm/glm.hpp"
#include <chrono>

enum class State{prepare, play, end};
enum class BallControl {redTeam, blueTeam};

class Game {
public:
	Game();
	~Game();
	void run();
private:
	void update();
	void draw();
	bool volleyballDetection();
	
	State state = State::prepare;

	BallControl control = BallControl::blueTeam;
	BlueTeam blueTeam;
	RedTeam redTeam;
	Player player = Player(glm::vec3(-2.f, 1.f, 0.f), glm::vec3(0.f), glm::vec3(0.15f, 1.7f, 0.35f), glm::vec3(1.f, 0.92f, 0.f));
	Scene scene;
	int blueHit = 0, redHit = 0;
};