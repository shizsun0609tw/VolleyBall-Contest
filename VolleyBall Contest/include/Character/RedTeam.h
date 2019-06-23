#pragma once
#include "include/Character/Member.h"
#include "include/Scene/VolleyBall.h"
#include <vector>

class RedTeam {
public:
	RedTeam();
	~RedTeam() {}
	void update(VolleyBall ball);
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