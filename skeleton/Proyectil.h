#pragma once
#include "Particle.h"
class Proyectil : public Particle
{
public:
	Proyectil(Vector3 Pos, Vector3 Vel, Vector3 Acc):Particle(Pos,Vel,Acc){};
	~Proyectil(){};
private:
	float mass = 0.008;
};

