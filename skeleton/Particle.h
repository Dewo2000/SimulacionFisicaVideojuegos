#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc);
	~Particle();
	void integrate(double t);
private:
	double damping = 0.999;
	Vector3 vel;
	Vector3 acc;
	physx::PxTransform pose;
	RenderItem* renderItem;
	//std::make_unique<RenderItem> renderItem;
};

