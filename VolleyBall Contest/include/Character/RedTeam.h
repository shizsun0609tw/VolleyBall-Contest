#pragma once
#include "include/Character/Member.h"
#include <vector>

class RedTeam {
public:
	RedTeam();
	~RedTeam() {}
	void update(glm::vec3 pos, Velocity velocity);
	void draw();
private:
	vector<Member> members;
	int score;
	int hit;
	bool arrived;
	// team member
};