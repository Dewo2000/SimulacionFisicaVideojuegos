#pragma once
#include <iostream>
#include"Floor.h"
#include"Particle.h"
#include"FireWork.h"
#include"GaussianParticleGenerator.h"
#include"UniformParticleGenerator.h"
#include"CircleParticleGenerator.h"
#include "GravityForceGenerator.h"
#include "ParticleForceRegistry.h"
#include "DragGenerator.h"
#include "TwisterWindGenerator.h"
#include "BlastGenerator.h"
#include "SpringForceGenerator.h"
#include "BuoyancyForceGenerator.h"
#include "core.hpp"
#include "RenderUtils.hpp"

#include "RigidParticle.h"
using namespace physx;
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
	void testSpringForce();
	void testslinky();
	void testbuoyancy(float V, float mass);
	void gasolina(float V, float mass);
	void shootFirework(int type);
	void addParticleForce();
	void deleteParticleForce();
	void setK(double d);
	void cleanScene();
	void solidRigid(PxPhysics* p, PxScene* s);
protected:
	void onParticleDead(Particle* p);
	vector<Particle*>_particles;
	vector<FireWork*>_fireworkpool;
	vector<ParticleGenerator*>_particle_generators;
	vector<ForceGenerator*>force_generator;
	std::mt19937 random_generator;
	Vector3 _gravity = {0,-10,0};
	ParticleForceRegistry* forceRegistry;
	BlastGenerator* bg;
};

