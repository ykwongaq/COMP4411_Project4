#include "particle.h"
// SAMPLE_SOLUTION
#include "FL/gl.h"
#include "modelerdraw.h"
#include <GL/glu.h>

void Particle::update(float dt)
{
	for (std::vector<Force*>::iterator it = ForcesTobeApplied.begin(); it != ForcesTobeApplied.end(); ++it) {
		//std::cout<<ForcesTobeApplied.size()<<std::endl;
		//std::cout << (*it)->id << std::endl;
		(*it)->applyOn(this);
	}
	/* Euler's Method */
	// position += velocity * dt;
	// velocity += netF / mass * dt;
	/* Runge¨CKutta's Method */
	Vec3d k1 = velocity;
	//Vec3d k2 = velocity + prod(netF / mass , dt/2*k1);
	Vec3d k2 = velocity + netF / mass * dt / 2;
	Vec3d k3 = velocity + prod(netF / mass, dt / 2 * k2);
	Vec3d k4 = velocity + prod(netF / mass, k3);
	position += dt * k2;
	//position += dt /6 * (k1 + 2*k2 + 2*k3 + k4);
	velocity += netF / mass * dt;
	std::cout << "P: " << position << "v: " << velocity << std::endl;
}

void Particle::draw()
{
	setDiffuseColor(1, 1, 1);
	glPushMatrix();
	glTranslated(position[0], position[1], position[2]);
	drawSphere(0.2);
	glPopMatrix();
}
