#pragma once
#include "Particle.h"
#include <iostream>
using namespace std;

class ParticleGenerator
{
public:
	void setParticle(Particle* model);
	virtual vector<Particle*> generateParticles() = 0;
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double generation_probability;
	int _num_particles;
	Particle* _model=nullptr;
};