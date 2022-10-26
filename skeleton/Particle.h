#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
enum ParticleType {
	NONE,FIREWORK
};
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Size, float Opacity, Vector3 ColorRGB , double aliveTime);
	~Particle();
	void integrate(double t);
	bool isAlive();
	virtual Particle* clone() const;
protected:
	double damping = 0.999;
	Vector3 vel;
	Vector3 pos;
	Vector3 acc;
	physx::PxTransform pose;
	RenderItem* renderItem;
	float size;
	Vector4 color;
	float opacity;
	double remainning_time;
	ParticleType _type;
	//PxGeometryType typeGeometry;
	//std::make_unique<RenderItem> renderItem;
};

