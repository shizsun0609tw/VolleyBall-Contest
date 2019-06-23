#include "include/Character/RedTeam.h"

RedTeam::RedTeam() {
	glm::vec3 angle(0.f, 180.f, 0.f);
	glm::vec3 size(0.15f, 1.7f, 0.35f);
	glm::vec3 color(1.f, 0.f, 0.f);
	members.push_back(Member(glm::vec3(7.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, 0.f), angle, size, color));
	members.push_back(Member(glm::vec3(3.3f, 1.f, -2.7f), angle, size, color));
	members.push_back(Member(glm::vec3(7.3f, 1.f, -2.7f), angle, size, color));
	score = 0;
	hit = 0;
	arrived = false;
}

void RedTeam::update(glm::vec3 pos, Velocity velocity){
	int close = 0; // store which member is the most close
	float minDistance = members[0].getDistance(pos); // store the min distance(member ball)
	for (int i = 1; i < members.size(); i++) {
		if (members[i].getDistance(pos) < minDistance) {
			close = i;
			minDistance = members[i].getDistance(pos);
		}
	}
	for (int i = 0; i < members.size(); i++) {
		if (i == close) {
			arrived = members[i].update(arrived, true, hit, pos, velocity);
		}
		else {
			arrived = members[i].update(arrived, false, hit, pos, velocity);
		}
	}
}

void RedTeam::draw(){
	for (int i = 0; i < members.size(); i++) {
		members[i].draw();
	}
}