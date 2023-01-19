#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
#include <time.h>
#include <random>
using namespace physx;
using namespace std;
class RigidParticle
{
public:
	RigidParticle(Vector3 Pos, Vector3 Vel, Vector4 ColorRGBA, PxShape* shape, float mass, PxPhysics* physic, PxScene* scene,PxMaterial* material=nullptr);
	RigidParticle* clone(Vector3 Pos, Vector3 Vel,Vector4 Color = {0,0,0,0},bool random=false);
	PxRigidDynamic* getSolid() { return solid; };
	float getImass() { 
		if (_mass == 0) {
			return 0;
		}
		else
		{
			return  1 / _mass;
		}
	};
	float getmass() { return _mass; };
	Vector3 getVel() { return solid->getLinearVelocity(); };
	Vector3 getPos() { return solid->getGlobalPose().p; };
	void addForce(Vector3 force);
	void clearForce();
	bool integrate(double t);
	void release();
protected:
	PxRigidDynamic* solid;
	PxPhysics* _gphysic;
	PxScene* _scene;

	Vector3 vel;
	float  _mass;
	PxTransform pose;
	RenderItem* renderItem;
	float size;
	Vector4 color;
	float opacity;
	physx::PxShape* _shape;
	PxMaterial* _material;
	double aliveTime = 10;
	double time=0;

	std::mt19937 random_generator;
};

