#include "include/Character/RedTeam.h"

RedTeam::RedTeam() {
	glm::vec3 angle(0.f, 180.f, 0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(1.f, 0.f, 0.f);
	members.push_back(Member(glm::vec3(7.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 0.f), angle, size, color));
	score = 0;
	hit = 0;
	arrived = false;
}

void RedTeam::update(VolleyBall &ball) {
	int close = 0; // store which member is the most close
	float minDistance = members[0].getDistance(ball.getPos()); // store the min distance(member ball)
	for (int i = 1; i < members.size(); i++) {
		if (members[i].getDistance(ball.getPos()) < minDistance) {
			close = i;
			minDistance = members[i].getDistance(ball.getPos());
		}
	}

	if (ball.getPos().x >= 0.0) { // ball in our side
		for (int i = 0; i < members.size(); i++) {
			if (i == close) {
				members[i].update(arrived, true, hit, ball, 1);
			}
			else {
				members[i].update(arrived, false, hit, ball, 1);
			}
			if (members[i].arrived) {
				arrived = true;
			}
			if (members[i].hit) {
				hit++;
				members[i].hit = false;
				arrived = false;
			}
		}
	}
	else { // ball in other side
		members[0].back(glm::vec3(7.3f, 1.f, -2.7f));
		members[1].back(glm::vec3(3.3f, 1.f, -2.7f));
		members[2].back(glm::vec3(3.3f, 1.f, 0.f));
		members[3].back(glm::vec3(3.3f, 1.f, 2.7f));
		members[4].back(glm::vec3(7.3f, 1.f, 2.7f));
		members[5].back(glm::vec3(7.3f, 1.f, 0.f));
		arrived = false;
		for (int i = 0; i < members.size(); i++) {
			members[i].arrived = false;
			if (members[i].getAnim() != Animation::idle) {
				members[i].playAnimation(Animation::idle);
			}
		}
	}
}

void RedTeam::reset() {
	members.clear();
	glm::vec3 angle(0.f, 180.f, 0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(1.f, 0.f, 0.f);
	members.push_back(Member(glm::vec3(7.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 0.f), angle, size, color));
}

void RedTeam::start(VolleyBall &ball) {
	members.clear();
	glm::vec3 angle(0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(0.f, 0.f, 1.f);
	members.push_back(Member(glm::vec3(10.f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, 0.f), angle, size, color));
	// hit ball
	srand(time(NULL));
	float speed = (rand() % 10000) / 10000;
	float z = (rand() % 9000) / 1000;
	float y = (rand() % 2601 + 2400) / 1000;
	glm::vec3 velocity(-1.f, y / 9.0, z / 18.0);
	velocity = glm::normalize(velocity);
	velocity = (float)20.0 * speed * velocity;
	ball.setVelocity(velocity);
}

void RedTeam::draw() {
	for (int i = 0; i < members.size(); i++) {
		members[i].draw();
	}
}