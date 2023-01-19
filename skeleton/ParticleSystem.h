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
#include "RigidForceRegistry.h"
using namespace physx;
using namespace std;

class ParticleSystem
{
public:
	ParticleSystem(PxPhysics* p, PxScene* s);
	void update(double t);
	void generateFireworkSystem();
	//void testGenerators();
	//void testForceGenerators();
	//void testSpringForce();
	//void testslinky();
	//void testbuoyancy(float V, float mass);
	//void gasolina(float V, float mass);
	//void shootFirework(int type);
	//void addParticleForce();
	//void deleteParticleForce();
	//void setK(double d);

	//void solidRigid(PxPhysics* p, PxScene* s);

	//void activateTwister();
	void cleanScene();
	void game();
	void goLeft();
	void goRight();
	void clearForce();
	void explode();
	void wind();
	bool isFinish() {
		return finish;
	};
	bool isWin() {
		return win;
	};
	int getTime() {
		return gameTime;
	}
	void forcedWin();
protected:
	void onParticleDead(Particle* p);
	vector<Particle*>_particles;
	vector<RigidParticle*>_rgparticles;
	vector<FireWork*>_fireworkpool;
	vector<ParticleGenerator*>_particle_generators;
	vector<ForceGenerator*>force_generator;
	std::mt19937 random_generator;
	Vector3 _gravity = {0,-10,0};
	ParticleForceRegistry* forceRegistry;
	RigidForceRegistry* rigidForceRegistry;


	double acumulatedtime = 0;
	double generateTime = 0;
	GravityForceGenerator* gfg;
	DragGenerator* dg;
	BlastGenerator* bg;
	RigidParticle* player;
	bool exploted=false;
	bool winded = false;
	PxPhysics* p;
	PxScene* s;
	void obstaculo();

	bool finish=false;
	bool win = false;
	bool obstac = false;
	double gameTime;
	vector<PxRigidStatic*>_staticRigid;
	vector<PxShape*>_staticRigidShape;
	vector<RenderItem*>_staticRigidRender;
};

