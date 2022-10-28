#pragma once
#include <iostream>
#include"Particle.h"
#include"FireWork.h"
#include"GaussianParticleGenerator.h"
#include"UniformParticleGenerator.h"
#include"CircleParticleGenerator.h"
#include "GravityForceGenerator.h"
#include "ParticleForceRegistry.h"
using namespace std;

class ParticleSystem
{
public:
	ParticleSystem();
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
	void testGenerators();
	void testForceGenerators();
	void shootFirework(int type);
protected:
	void onParticleDead(Particle* p);
	vector<Particle*>_particles;
	vector<FireWork*>_fireworkpool;
	vector<ParticleGenerator*>_particle_generators;
	vector<ForceGenerator*>force_generator;
	Vector3 _gravity = {0,-10,0};
	ParticleForceRegistry* freg;
};

