#include "include/Character/Member.h"

using namespace std;

// update IA information when ball come
// input : arrive(team arrive), must(must hit ball), hit(ball hit by team times)
//         ball (ball), team (0 blue 1 red)
// output : arrived (already arrive)
void Member::update(const bool arrive, const bool must, const int hit, VolleyBall &ball, int team) {
	Animation anim = getAnim();
	float distance = glm::distance(this->getPos(), ball.getPos());
	// moving
	glm::vec3 moveVelocity = speedUp(arrive, must, ball.getPos(), ball.getVelocity());
	if (arrive) { // a team arrive
		if (distance > 1.2) {
			if (anim == Animation::idle || anim == Animation::run) {
				playAnimation(Animation::idle);
			}
		}
		else {
			// hit ball
			if (next != Animation::idle) {
				if (anim == Animation::idle || anim == Animation::run) {
					playAnimation(next);
				}
				this->hit = batting(next, team, hit, ball);
				if (this->hit) {
					next = Animation::idle;
					arrived = false;
				}
			}
		}
	}
	else {
		if ( distance > 1.2 && ball.getPos().y > 0.3) {
			if (anim == Animation::idle || anim == Animation::run) {
				Character::moveWorld(moveVelocity);
				if (anim == Animation::idle) playAnimation(Animation::run);
			}
		}
		else { // arrive or fall
			arrived = true;
			int goal = BallGo(hit, team);
			int hitType = 2; // store which type to hit ball
			// decide how to hit ball (I arrived and didn't decide how to hit ball)
			if (distance < 1.2 && (next == Animation::idle || next == Animation::run)) {
				srand(time(NULL));
				float type = rand() % 1001 / 1000; // decide which type to hit ball
				float speed = glm::length(ball.getVelocity()) / 1.0; // ball's velocity(scalar)
				speed = speed / 10.0;
				if (speed > 1.0) speed = 1.0;
				// decide whitch type to hit ball
				if (ball.getPos().y > 3.0) {
					if (type < speed) { // high speed more probability underhand
						hitType = 2;
						next = Animation::overhand;
					}
					else {
						if (goal != team && rand() % 1001 / 1000.0 < 0.1) {
							hitType = 3;
							if (rand() % 4 == 0) {
								next = Animation::jumpAttack;
							}
							else {
								next = Animation::attack;
							}
						}
						else {
							hitType = 1;
							if (rand() % 4 == 0) {
								next = Animation::jump;
							}
							else {
								next = Animation::overhand;
							}
						}
					}
				}
				else if (ball.getPos().y > 1.8) {
					if (type < speed) {
						hitType = 2;
						next = Animation::overhand;
					}
					else {
						if (goal != team && rand() % 1001 / 1000.0 < 0.4) {
							hitType = 3;
							next = Animation::attack;
						}
						else {
							hitType = 1;
							next = Animation::overhand;
						}
					}
				}
				else {
					hitType = 2;
					next = Animation::underhand;
				}
			}
		}
	}
	Character::update();
}

// when spike count falling point, using liear paratmeter
// input : pos (ball position), velocity (ball velocity)
// output : vector(character -> probably where to drop)
glm::vec3 Member::spike(const glm::vec3 pos, const Velocity velocity) {
	float t = (0.105 - pos.y) / velocity.y; // paratmeter
	glm::vec3 forward = pos;
	forward = forward - this->getPos();
	forward.y = 0.0;
	forward = glm::normalize(forward);
	return forward;
}

// when except spike count falling point
// before fall, calculate the approximate direction
// start falling, using free fall equation
// input : pos (ball position), velocity(ball velocity)
// output : vector(character -> probably where to drop)
glm::vec3 Member::serve(const glm::vec3 pos, const Velocity velocity) {
	float t = (0.105 - pos.y) / velocity.y; // paratmeter
	glm::vec3 forward = pos;
	forward = forward - this->getPos();
	forward.y = 0.0;
	forward = glm::normalize(forward);
	return forward;
}

// return character to pos 's distance
// input : pos(ball position)
// output : distance(ball,character's distance)
float Member::getDistance(const glm::vec3 pos) {
	return glm::distance(pos, this->getPos());
}

// compute IA's velocity
// input : arrive(team arrive), must(must hit ball)
//         pos(ball position), velocity(ball velocity)
// output : IAVelocity(IA's velocity)
glm::vec3 Member::speedUp(const bool arrive, const bool must, const glm::vec3 pos, const Velocity velocity) {
	if (arrive) return glm::vec3(0.f);
	else {
		float distance = glm::distance(this->getPos(), pos);
		float height = pos.y;
		glm::vec3 normal;
		if (glm::distance(glm::vec3(0.f), velocity) == 0.0) {
			normal = glm::vec3(0.f);
		}
		else {
			normal = glm::normalize(velocity);
		}
		float speed = velocity.x / normal.x;
		if (normal.x == 0.0) speed = 0.0;
		glm::vec3 IAVelocity;

		// change value to 0~1
		distance = distance / 10.0;
		height = height / 5.0;
		speed = speed / 13.0;
		if (distance > 1.0) distance = 1.0;
		if (height > 1.0) height = 1.0;
		if (speed > 1.0) speed = 1.0;
		if (distance < 0.0) distance = 0.0;
		if (height < 0.0) height = 0.0;
		if (speed < 0.0) speed = 0.0;
		height = -height + 1;
		float moveSpeed = (distance + height + speed) / 3.0; // store final move speed
		if (must) { // need to hit ball
			if (speed > 0.9 && velocity.y < 0.0) { // is spike
				IAVelocity = this->spike(pos, velocity);
				moveSpeed = 0.5 * speed + 0.5;
			}
			else { // else
				IAVelocity = this->serve(pos, velocity);
			}
		}
		else { // dont need to hit ball
			moveSpeed = moveSpeed * 0.5;
			if (speed > 0.9 && velocity.y < 0.0) {
				IAVelocity = this->spike(pos, velocity);
			}
			else {
				IAVelocity = this->serve(pos, velocity);
			}
		}
		moveSpeed *= MAXSPEED;
		return moveSpeed * IAVelocity;
	}
}

// back to initial point
// input : pos (initial point)
void Member::back(glm::vec3 pos) {
	// decide velocity
	glm::vec3 IAVelocity;
	IAVelocity = pos - this->getPos();
	IAVelocity.y = 0;
	IAVelocity = glm::normalize(IAVelocity);
	float distance = this->getDistance(pos);
	distance = distance / 10.0;
	if (distance > 1.0) distance = 1.0;
	if (distance < 0.0) distance = 0.0;
	distance *= MAXSPEED;
	IAVelocity = distance * IAVelocity;
	// change data
	float DX = getPos().x - pos.x;
	float DZ = getPos().z - pos.z;
	if (DX < 0.0) DX = -DX;
	if (DZ < 0.0) DZ = -DZ;
	Animation anim = getAnim();
	if (DX > 0.1 || DZ > 0.1) {
		if (anim == Animation::idle || anim == Animation::run) {
			Character::moveWorld(IAVelocity);
			if (anim == Animation::idle || anim == Animation::run) playAnimation(Animation::run);
		}
	}
	else { // already arrive
			playAnimation(Animation::idle);
	}
	Character::update();
}