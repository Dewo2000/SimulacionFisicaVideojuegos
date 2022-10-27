#pragma once
#include "ParticleGenerator.h"
#include <time.h>
#include <random>
class UniformParticleGenerator :public ParticleGenerator
{
public:
	UniformParticleGenerator(Vector3 pos, Vector3 vel,Vector3 posWidth,Vector3 velWidth, double genPro, int numP);
	virtual vector<Particle*> generateParticles();
private:
	Vector3 _pos_width, _vel_width;
	std::mt19937 random_generator;
};

