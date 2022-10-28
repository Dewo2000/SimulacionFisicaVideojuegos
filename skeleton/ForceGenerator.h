#pragma once
#include "Particle.h"
#include <random>
#include <list>
class ForceGenerator 
{
public:
	virtual void updateForce(Particle* particle, double durantion)=0;
	std::string name;
	double t = -1e10;
};