#pragma once
#include "include/Character/Member.h"
#include <vector>

class BlueTeam {
public:
	BlueTeam();
	~BlueTeam() {}
	void update(glm::vec3 pos, Velocity velocity);
	void draw();
	void reset();
	void start();
	int score;
private:
	vector<Member> members;
	int hit;
	bool arrived;
	// team member
};