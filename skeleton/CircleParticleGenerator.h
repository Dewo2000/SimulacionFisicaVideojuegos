#pragma once
#include "GaussianParticleGenerator.h"
#include <iostream>
class CircleParticleGenerator : public GaussianParticleGenerator
{
	double cvel;
public:
	CircleParticleGenerator(Vector3 pos, Vector3 vel, Vector3 std_dev_pos, Vector3 std_dev_vel, double genPro, int numP , double vel_circle);
	virtual vector<Particle*> generateParticles();
};

