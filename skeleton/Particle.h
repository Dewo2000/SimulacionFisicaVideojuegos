#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
#include <time.h>
class Particle
{
public:
	Particle():opacity(1),remainning_time(0), renderItem(nullptr),size(1) {};
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc,float Opacity, Vector3 ColorRGB , double aliveTime,physx::PxShape * shape, float mass=0, bool render=true);
	~Particle();
	void integrate(double t);
	bool isAlive();
	virtual Particle* clone() const;
	void setVel(Vector3 vel);
	Vector3 getVel() { return vel; };
	void setPos(Vector3 pos);
	Vector3 getPos() { return pose.p; };
	virtual bool isFirework() { return false; };
	float getImass() { return inverss_mass; };
	float getmass() { return mass; };
	void addForce(const Vector3& f);
protected:
	double damping = 0.999;
	Vector3 vel;
	Vector3 pos;
	Vector3 acc;
	Vector3 force;
	float inverss_mass,mass;
	physx::PxTransform pose;
	RenderItem* renderItem;
	float size;
	Vector4 color;
	float opacity;
	double remainning_time;
	void clearForce();
	physx::PxShape* shape;
};




