#pragma once
#include "include/Character/Member.h"
#include "include/Scene/VolleyBall.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

class BlueTeam {
public:
	BlueTeam();
	~BlueTeam() {}
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