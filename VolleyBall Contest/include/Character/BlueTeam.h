#pragma once
#include "include/Character/Member.h"
#include "include/Scene/VolleyBall.h"
#include <vector>

class BlueTeam {
public:
	BlueTeam();
	~BlueTeam() {}
	void update(VolleyBall ball);
	void draw();
	void reset();
	void start(VolleyBall ball);
	int score;
private:
	vector<Member> members;
	int hit;
	bool arrived;
	// team member
};