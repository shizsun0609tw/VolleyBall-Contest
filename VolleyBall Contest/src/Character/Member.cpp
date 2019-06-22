#include "include/Character/Member.h"

// when spike count falling point, using liear paratmeter
// input : pos (ball position), velocity (ball velocity)
// output : probably where to drop
glm::vec3 Member::spike(glm::vec3 pos, Velocity velocity) {
	float t = (0.27 - pos.y) / velocity.y; // paratmeter
	glm::vec3 fallingPoint = pos + t * velocity;
	return fallingPoint;
}

// when except spike count falling point
// before fall, calculate the approximate direction
// start falling, using free fall equation
// input : pos (ball position), velocity(ball velocity)
// output : probably where to drop;
glm::vec3 Member::serve(glm::vec3 pos, Velocity velocity) {
	return glm::vec3(1.0);
}