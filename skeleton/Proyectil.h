#pragma once
#include "Particle.h"
class Proyectil : public Particle
{
public:
	Proyectil(Vector3 Pos, Vector3 Vel, Vector3 Acc , physx::PxShape * shape):Particle(Pos,Vel,Acc,1,{0,1,0},100,shape) {};
	~Proyectil(){};
private:
	float mass = 0.008;
};

