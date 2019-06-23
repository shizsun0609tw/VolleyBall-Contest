#include "include/Character/Member.h"

/*****moving*****/
// update IA information when ball come
// input : arrive(team arrive), must(must hit ball), hit(ball hit by team times)
//         pos(ball position), velocity(ball velocity)
// output : arrived (already arrive)
bool Member::update(const bool arrive, const bool must, const int hit, const glm::vec3 pos, const Velocity velocity) {
	Animation anim = getAnim();
	// moving
	bool arrived = false;
	glm::vec3 moveVelocity = speedUp(arrive, must, pos, velocity);
	float DX = getPos().x - pos.x;
	float DZ = getPos().z - pos.z;
	if (DX < 0.0) DX = -DX;
	if (DZ < 0.0) DZ = -DZ;
	if ((DX > 0.3 || DZ > 0.3) && !arrive) {
		if (anim == Animation::idle || anim == Animation::run) {
			Character::moveWorld(moveVelocity);
			if (anim == Animation::idle) playAnimation(Animation::run);
		}
	}
	else { // already arrive
		arrived = true;
		playAnimation(Animation::idle);
	}

	Character::update();
	return arrived;
}

// when spike count falling point, using liear paratmeter
// input : pos (ball position), velocity (ball velocity)
// output : vector(character -> probably where to drop)
glm::vec3 Member::spike(const glm::vec3 pos, const Velocity velocity) {
	float t = (0.105 - pos.y) / velocity.y; // paratmeter
	glm::vec3 forward = pos + t * velocity;
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
	const glm::vec3 position = this->getPos(); // character's position
	glm::vec3 B = position - pos;
	glm::vec3 forward = position;
	if (velocity.y > 0) { // ball isn't fall yet
		forward.z = forward.z + velocity.z;
	}
	else { // ball is falling
		float t = glm::sqrt((2 * pos.y - 0.21) / G);
		forward = pos + t * velocity;
		forward = forward - position;
		forward.y = 0.0;
	}
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
		speed = speed / 8.0;
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
	Animation anim = getAnim();
	if (DX > 0.3 || DZ > 0.3) {
		if (anim == Animation::idle || anim == Animation::run) {
			Character::moveWorld(IAVelocity);
			if (anim == Animation::idle) playAnimation(Animation::run);
		}
	}
	else { // already arrive
		playAnimation(Animation::idle);
	}
}

/*****hit ball*****/
// produce velocity to ball
// input : type(which type to hit ball), team(in which team), goal(which team)
// output : velocity(velocity to ball)
glm::vec3 Member::hitBall(int type, int team, int goal) {
	glm::vec3 target;
	glm::vec3 velocity(0.f, -1.f, 0.f);
	srand(time(NULL));
	target.x = rand() % 1000 / 1000.0;
	target.z = rand() % 1000 / 1000.0;
	float speed = rand() % 1000 / 1000.0;
	if (team == goal) { // pass
		if (team == 0) { // blue
			target.x = target.x + 4.0;
			target.z = target.z - 0.5;
		}
		else { //red
			target.x = target.x - 5.0;
			target.z = target.z - 0.5;
		}
	}
	else { // attack
		if (team == 0) { // blue
			target.x = target.x * 9.0;
			target.z = target.z * 6.0 - 3.0;
		}
		else { //red
			target.x = target.x * -9.0;
			target.z = target.z * 6.0 - 3.0;
		}
	}
	target.y = 0.0;
	switch (type) {
	case 1: // attack
		velocity = target - this->getPos();
		velocity = glm::normalize(velocity);
		velocity.y = -(rand() % 1000 / 2000.0);
		speed = (speed / 2 + 0.5) * 20.0;
		velocity = speed * velocity;
		break;
	case 2: // overhand
		velocity = target - this->getPos();
		velocity = glm::normalize(velocity);
		velocity.y = rand() % 1000 / 500.0;
		speed = (speed / 2) * 15.0;
		velocity = speed * velocity;
		break;
	case 3: // underhand
		velocity = target - this->getPos();
		velocity = glm::normalize(velocity);
		velocity.y = rand() % 1000 / 1000.0;
		speed = speed * 15.0;
		velocity = speed * velocity;
		break;
	default:
		break;
	}
	return velocity;
}