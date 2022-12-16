#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
#include <time.h>
using namespace physx;
using namespace std;
class RigidParticle
{
public:
	RigidParticle(Vector3 Pos, Vector3 Vel, Vector4 ColorRGBA, PxShape* shape, float mass, PxPhysics* physic, PxScene* scene,PxMaterial* material=nullptr);
	void clone(Vector3 Pos, Vector3 Vel);
protected:
	
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
};

