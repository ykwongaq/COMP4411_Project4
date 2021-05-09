// SAMPLE_SOLUTION
#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec.h"
#include <vector>

#include "force.h"
class Force;

class Particle {
public:
	Particle(Vec3d pos, double m) : position(pos), mass(m), velocity(Vec3d(0, 0, 0)), netF(Vec3d(0, 0, 0)) {};

	// interface on private attributes
	inline void setP(Vec3d p) { position = p; }
	inline void setV(Vec3d v) { velocity = v; }
	inline void setF(Vec3d f) { netF = f; }
	inline void setm(double m) { mass = m; }
	inline Vec3d getP() const { return position; }
	inline Vec3d getV() const { return velocity; }
	inline Vec3d getF() const { return netF; }
	inline double getM() const { return mass; }

	// manipulation
	void addForce(Force* f) { ForcesTobeApplied.push_back(f); };
	void update(float dt);
	void draw();

private:
	double mass;
	Vec3d position, velocity, netF;
	std::vector<Force*> ForcesTobeApplied;
};

#endif