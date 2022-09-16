#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel);
	~Particle();
	void integrate(double t);
private:
	Vector3 vel;
	Vector3 acc;
	physx::PxTransform pose;
	RenderItem* renderItem;
	//std::make_unique<RenderItem> renderItem;
};

