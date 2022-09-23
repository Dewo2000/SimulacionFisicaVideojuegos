#include "Particle.h"
using namespace physx;
Particle::Particle(Vector3 Pos, Vector3 Vel,Vector3 Acc):vel(Vel),acc(Acc) {
	pose = PxTransform(Pos);
	Vector4 const color = { 0,1,0,1 };
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &pose,color);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p += vel * t;
	vel = vel * pow(damping, t) + acc * t;
}
