#pragma once
#include <iostream>
#include"Particle.h"
#include"ParticleGenerator.h"
using namespace std;
class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
protected:
	vector<Particle*>_particles;
	vector<ParticleGenerator*>_particle_generators;
};

