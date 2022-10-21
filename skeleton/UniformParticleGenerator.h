#pragma once
#include "ParticleGenerator.h"
#include <time.h>
class UniformParticleGenerator :ParticleGenerator
{
public:
	UniformParticleGenerator(Vector3 pos, Vector3 vel);
	virtual vector<Particle*> generateParticles();
private:
	Vector3 _pos_width, _vel_width;
};

