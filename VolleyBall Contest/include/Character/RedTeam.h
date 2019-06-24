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
	int score;
	void reset();
	void start(VolleyBall &ball);
	int hit;
private:
	vector<Member> members;
	bool arrived;
	// team member
};