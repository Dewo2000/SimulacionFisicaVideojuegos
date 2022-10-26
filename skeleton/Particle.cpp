#include "Particle.h"
using namespace physx;
Particle::Particle(Vector3 Pos, Vector3 Vel,Vector3 Acc,float Size ,float Opacity ,Vector3 ColorRGB, double aliveTime)
	:vel(Vel),acc(Acc),size(Size),opacity(Opacity), color({ ColorRGB, opacity }),remainning_time(aliveTime){
	
	pose = PxTransform(Pos);
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(size)), &pose,color);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p += vel * t;
	vel = vel * pow(damping, t) + acc * t;


	remainning_time--;
}
