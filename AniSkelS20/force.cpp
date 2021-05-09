#pragma once
#include "force.h"
#include "particle.h"

void Gravity::applyOn(Particle* parti)
{
	//std::cout << "getF:" << parti->getF() << "G:" << gravity * parti->getM() << std::endl;
	parti->setF(parti->getF() + gravity * parti->getM());
}
