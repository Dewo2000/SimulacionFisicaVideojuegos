#pragma once
#include "Particle.h"
#include "RigidParticle.h"
#include <random>
#include <list>
class ForceGenerator 
{
public:
	virtual void updateForce(Particle* particle, double durantion)=0;
	virtual void updateForce(RigidParticle* particle, double durantion) {};
	std::string name;
	double t = -1e10;
};