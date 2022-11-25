#pragma once
#include "Particle.h"
#include "ParticleGenerator.h"
using namespace std;
class FireWork : public Particle
{
public:
	FireWork(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Opacity, Vector3 ColorRGB, double aliveTime,physx::PxShape* shape,
		vector<shared_ptr< ParticleGenerator>> gens, float mass,bool rende = true);
	virtual bool isFirework() override { return true; };
	vector<Particle*> explode();
	virtual Particle* clone() const;
private:
	vector <shared_ptr<ParticleGenerator>> generators;
};

