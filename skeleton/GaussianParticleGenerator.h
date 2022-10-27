#pragma once
#include "ParticleGenerator.h"
#include <time.h>
#include <random>
class GaussianParticleGenerator :public ParticleGenerator
{
public:
	GaussianParticleGenerator(Vector3 pos, Vector3 vel,Vector3 std_dev_pos, Vector3 std_dev_vel, double genPro, int numP);
	virtual vector<Particle*> generateParticles();
private:
	Vector3 std_dev_pos, std_dev_vel;
	double std_dev_t;
	std::mt19937 random_generator;
};

