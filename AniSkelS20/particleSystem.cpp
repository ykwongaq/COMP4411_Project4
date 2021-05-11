#pragma warning(disable : 4786)

#include "particleSystem.h"


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

// add
#include <ctime>
#include <FL/gl.h>
#include "modelerdraw.h"


/***************
 * Constructors
 ***************/

ParticleSystem::ParticleSystem()
{
	// TODO
	bake_fps = 30;
	bake_start_time = -1;  // meaningless
	bake_end_time = -1;	   // meaningless
	simulate = false;
	dirty = false;
	srand(time(0));
	force_vec.push_back(new Gravity(Vec3d(0, -9.8, 0)));


}





/*************
 * Destructor
 *************/

ParticleSystem::~ParticleSystem()
{
	// TODO
	for (auto it = force_vec.begin(); it != force_vec.end(); ++it) { delete (*it); }

}


/******************
 * Simulation fxns
 ******************/

 /** Start the simulation */
void ParticleSystem::startSimulation(float t)
{

	// TODO
	clearBaked();
	bake_start_time = t;
	// These values are used by the UI ...
	// -ve bake_end_time indicates that simulation
	// is still progressing, and allows the
	// indicator window above the time slider
	// to correctly show the "baked" region
	// in grey.
	bake_end_time = -1;
	simulate = true;
	dirty = true;

}

/** Stop the simulation */
void ParticleSystem::stopSimulation(float t)
{

	// TODO
	bake_end_time = t;
	// These values are used by the UI
	simulate = false;
	dirty = true;

}

/** Reset the simulation */
void ParticleSystem::resetSimulation(float t)
{

	// TODO
	clearBaked();
	particle_vec.clear();
	bake_start_time = -1;
	bake_end_time = -1;
	// These values are used by the UI
	simulate = false;
	dirty = true;

}

/** Compute forces and update particles **/
void ParticleSystem::computeForcesAndUpdateParticles(float t)
{

	// TODO
	float dt = 1 / bake_fps;
	if (isSimulate()) {
		if (!isBakedAt(t)) {
			printf("collision detection!\n");
			for (auto a = particle_vec.begin(); a != particle_vec.end(); ++a) {
				// detection between particles
				for (auto b = particle_vec.begin(); b != particle_vec.end(); ++b) {
					if (a == b) break;
					double d = (a->getP() - b->getP()).length();
					if (d > 0.4 && d < 0.5) {
						Vec3d temp = a->getV();
						a->setV(0.9 * b->getV());
						b->setV(0.9 * temp);
					}
				}
				// with the rigid ground
				if ((a->getV()) * Vec3d(0, 1, 0) < 0 && (a->getP() - Vec3d(0, -3.5, 0)) * Vec3d(0, 1, 0) < 0.215) {
					Vec3d Va = a->getV();
					Vec3d Vnew = { Va[0], -0.95 * Va[1],Va[2] };
					a->setV(Vnew);
				}
			}
			printf("updateParticles!\n");
			for (auto it = particle_vec.begin(); it != particle_vec.end(); ++it) {
				//std::cout << it->getP() << it->getM() << std::endl;
				//std::cout << it->getV() << it->getF() << std::endl;
				it->update(dt);
			}
			bakeParticles(t);
		}
	}
}


/** Render particles */
void ParticleSystem::drawParticles(float t)
{
	if (isBakedAt(t)) {
		std::vector<Particle> bakedparticle = bake_storage.at(t);
		for (auto it = bakedparticle.begin(); it != bakedparticle.end(); ++it) {
			printf("drawParticles!\n");
			it->draw();
		}
	}
	// TODO
}


void ParticleSystem::spawnParticles(Mat4f CameraM, Mat4f CurrModelM, float currt)
{
	Mat4f WorldM = CameraM.inverse() * CurrModelM;
	Vec4f WorldP4 = WorldM * Vec4f(0, 0, 0, 1);

	if (isSimulate()) {
		printf("spawnParticles!\n");
		//Vec3d WorldP(WorldP4[0], WorldP4[1]+ rand() % 80 / 100.0 - 0.4, WorldP4[2] + rand() % 80 / 100.0 - 0.4);
		if (!isBakedAt(currt + 1.0f / bake_fps)) {
			Vec3d WorldP(WorldP4[0], WorldP4[1], WorldP4[2]);
			//double mass = (rand() % 50) / 5.0 + 0.5;
			double mass = 5;
			Particle newP(WorldP, mass);
			//Vec3d velocity(rand()%3+2.0, rand()%100/100.0*2 - 1, rand() % 100*2 / 100.0);
			Vec3d velocity(5, 0, 0);
			newP.setV(velocity);
			for (std::vector<Force*>::iterator it = force_vec.begin(); it != force_vec.end(); ++it) {
				newP.addForce(*it);
			}
			particle_vec.push_back(newP);
			Vec3d WorldQ(WorldP4[0] + 2.5, WorldP4[1], WorldP4[2]);
			mass = 5;
			Particle newQ(WorldQ, mass);
			//Vec3d velocity(rand()%3+2.0, rand()%100/100.0*2 - 1, rand() % 100*2 / 100.0);
			velocity = { -5, 0, 0 };
			newQ.setV(velocity);
			for (std::vector<Force*>::iterator it = force_vec.begin(); it != force_vec.end(); ++it) {
				newQ.addForce(*it);
			}
			particle_vec.push_back(newQ);
		}
	}
}





/** Adds the current configuration of particles to
  * your data structure for storing baked particles **/
void ParticleSystem::bakeParticles(float t)
{
	bake_storage.insert(std::pair<float, std::vector<Particle> >(t, particle_vec));

	// TODO
}
bool ParticleSystem::isBakedAt(float t)
{
	auto it = bake_storage.find(t);
	return (it != bake_storage.end());
}

/** Clears out your data structure of baked particles */
void ParticleSystem::clearBaked()
{
	bake_storage.clear();
	// TODO
}
