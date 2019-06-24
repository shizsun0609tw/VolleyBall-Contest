#pragma once
#include "include/Character/Member.h"
#include "include/Scene/VolleyBall.h"
#include <vector>

class RedTeam {
public:
	RedTeam();
	~RedTeam() {}
	void update(VolleyBall &ball);
	void draw();
	void reset();
	void start(VolleyBall &ball);
	int score;
	int hit;
private:
	vector<Member> members;
	bool arrived;
	// team member
};