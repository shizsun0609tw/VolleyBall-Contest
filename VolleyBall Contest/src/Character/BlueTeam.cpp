#include "include/Character/BlueTeam.h"

BlueTeam::BlueTeam() {
	glm::vec3 angle(0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(0.f, 0.f, 1.f);
	members.push_back(Member(glm::vec3(-7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-7.3f, 1.f, -2.7f), angle, size, color));
	score = 0;
	hit = 0;
	arrived = false;
}

void BlueTeam::update(VolleyBall ball) {
	int close = 0; // store which member is the most close
	float minDistance = members[0].getDistance(ball.getPos()); // store the min distance(member ball)
	for (int i = 1; i < members.size(); i++) {
		if (members[i].getDistance(ball.getPos()) < minDistance) {
			close = i;
			minDistance = members[i].getDistance(ball.getPos());
		}
	}
	// moving
	if (ball.getPos().x <= 0.0) { // ball in our side
		for (int i = 0; i < members.size(); i++) {
			if (i == close) {
				arrived = members[i].update(arrived, true, hit, ball.getPos(), ball.getVelocity());
			}
			else {
				arrived = members[i].update(arrived, false, hit, ball.getPos(), ball.getVelocity());
			}
		}
	}
	else { // ball in other side
		members[0].back(glm::vec3(-7.3f, 1.f, 2.7f));
		members[1].back(glm::vec3(-3.3f, 1.f, 2.7f));
		members[2].back(glm::vec3(-3.3f, 1.f, 0.f));
		members[3].back(glm::vec3(-3.3f, 1.f, -2.7f));
		members[4].back(glm::vec3(-7.3f, 1.f, -2.7f));
	}
}

void BlueTeam::reset() {
	members.clear();
	glm::vec3 angle(0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(0.f, 0.f, 1.f);
	members.push_back(Member(glm::vec3(-7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-7.3f, 1.f, -2.7f), angle, size, color));
}

void BlueTeam::start(VolleyBall ball) {
	members.clear();
	glm::vec3 angle(0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(0.f, 0.f, 1.f);
	members.push_back(Member(glm::vec3(-7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(-3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(-7.3f, 1.f, -2.7f), angle, size, color));
	// hit ball
	glm::vec3 velocity;
}

void BlueTeam::draw(){
	for (int i = 0; i < members.size(); i++) {
		members[i].draw();
	}
}