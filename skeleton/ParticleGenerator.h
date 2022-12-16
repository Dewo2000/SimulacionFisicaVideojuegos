#pragma once
#include "Particle.h"
#include "RigidParticle.h"
#include <iostream>
using namespace std;
using namespace physx;
class ParticleGenerator
{
public:
	void setParticle(Particle* model) { _model = model; }
	virtual vector<Particle*> generateParticles() = 0;
	virtual void generatePxParticles() {};
	void setPxParticle(RigidParticle* model) { pxmodel = model; };
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double generation_probability;
	int _num_particles , actualParticles=0;
	Particle* _model=nullptr;
	RigidParticle* pxmodel;
	const int MAXPARTICLES = 10000;
	bool solidRigid = false;
};