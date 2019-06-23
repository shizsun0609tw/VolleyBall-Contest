#pragma once
#include "include/Character/Member.h"
#include <vector>

class RedTeam {
public:
	RedTeam();
	~RedTeam() {}
	void update(glm::vec3 pos, Velocity velocity);
	void draw();
	int score;
	void reset();
	void start();
private:
	vector<Member> members;
	int hit;
	bool arrived;
	// team member
};