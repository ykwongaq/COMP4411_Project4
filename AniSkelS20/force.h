#pragma once
#ifndef FORCE_H
#define FORCE_H

#include "vec.h"
#include "particle.h"
class Particle;

class Force {
public:
	virtual void applyOn(Particle* parti) = 0;
	int id = 13;
};

class Gravity : public Force {
public:
	Gravity(Vec3d g) : gravity(g) {};
	Vec3d gravity;
	virtual void applyOn(Particle* parti);
};
#endif // 