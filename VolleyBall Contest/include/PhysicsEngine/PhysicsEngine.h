#pragma once

#include "include/glm/glm.hpp"
#include <vector>
#include <chrono>

typedef glm::vec3 Position;
typedef glm::vec3 Force;
typedef glm::vec3 Velocity;
typedef glm::vec3 Acceleration;
typedef float Mass;
typedef float Volumn;
typedef float Time;

using namespace std;

class PhysicsEngine {
public:
	static Force calNewton2Law(Mass m, Acceleration a) { return m * a; }
	static Acceleration calNewton2Law(Force F, Mass m) { return (m == 0 ? Acceleration(0.f) : F / m); }
	static Velocity calVelocity(Velocity v0, Acceleration a, Time t) { return v0 + a * t; }
	static Position calPosition(Position p0, Velocity v, Time t) { return p0 + v * t; }
	static float calPassTime(chrono::steady_clock::time_point t0, chrono::steady_clock::time_point t1) {
		return chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() / 1000.f;
	}
};