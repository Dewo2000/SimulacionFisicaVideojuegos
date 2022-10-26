#pragma once
#include <iostream>
#include"Particle.h"
#include"GaussianParticleGenerator.h"
#include"UniformParticleGenerator.h"
using namespace std;
class ParticleSystem
{
public:
	ParticleSystem();
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
protected:
	vector<Particle*>_particles;
	vector<ParticleGenerator*>_particle_generators;
};

