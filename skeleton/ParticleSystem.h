#pragma once
#include <iostream>
#include<list>
#include"Particle.h"
#include "ParticleGenerator.h"
using namespace std;
class ParticleSystem
{
public:
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
private:
	list<Particle*>_particles;
	list<ParticleGenerator*>_particle_generators;
};

