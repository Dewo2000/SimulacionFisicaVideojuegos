#pragma once
#include <iostream>
#include"Particle.h"
#include"GaussianParticleGenerator.h"
#include"UniformParticleGenerator.h"
using namespace std;
struct PayLoad
{
	unsigned type;
	unsigned count;
	PayLoad(unsigned _type, unsigned _count) {
		type = _type;
		count = _count;
	}
	void set(unsigned _type, unsigned _count) {
		type = _type;
		count = _count;
	}
};
struct FireworRule
{
	unsigned _type;
	float _minAge;
	float _maxAge;
	Vector3 _minVelocity;
	Vector3 _maxVelocity;
	float _damping;
	std::vector<PayLoad>_payloads;
	void set(unsigned type,float minAge,float maxAge,Vector3 minVelocity,Vector3 maxVelocity,float damping,std::vector<PayLoad>payloads) {
		 _type= type;
		 _minAge = minAge;
		 _maxAge = maxAge;
		 _minVelocity = minVelocity;
		_maxVelocity = maxVelocity;
		_damping =damping;
		_payloads=payloads;
	}
};
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
	Vector3 _gravity = {0,-10,0};
};

