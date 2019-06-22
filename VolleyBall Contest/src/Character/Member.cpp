#include "include/Character/Member.h"

// when spike count falling point, using liear paratmeter
// input : pos (ball position), velocity (ball velocity)
// output : vector(character -> probably where to drop)
glm::vec3 Member::spike(const glm::vec3 pos, const Velocity velocity) {
	float t = (0.105 - pos.y) / velocity.y; // paratmeter
	glm::vec3 forward = pos + t * velocity;
	forward = forward - this->getPos();
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
		float g = 9.80665;
		float t = glm::sqrt((2 * pos.y - 0.21) / g);
		forward = pos + t * velocity;
		forward = position - forward;
		forward.y = 0.0;
	}
	return forward;
}