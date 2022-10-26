#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Size, float Opacity, Vector3 ColorRGB , double aliveTime);
	~Particle();
	void integrate(double t);
	bool isAlive() { return remainning_time > 0; };
protected:
	double damping = 0.999;
	Vector3 vel;
	Vector3 acc;
	physx::PxTransform pose;
	RenderItem* renderItem;
	float size;
	Vector4 color;
	float opacity;
	double remainning_time;
	//PxGeometryType typeGeometry;
	//std::make_unique<RenderItem> renderItem;
};

