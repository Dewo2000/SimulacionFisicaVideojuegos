#include "Particle.h"
using namespace physx;
Particle::Particle(Vector3 Pos, Vector3 Vel,Vector3 Acc,float Size ,float Opacity ,Vector3 ColorRGB, double aliveTime,bool render=true)
	:vel(Vel),acc(Acc),size(Size),opacity(Opacity), color({ ColorRGB, opacity }),remainning_time(aliveTime){
	pos = Pos;
	pose = PxTransform(Pos);
	if(render)
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(size)), &pose,color);
	else
	renderItem = nullptr;
}

Particle::~Particle()
{
	if(renderItem!=nullptr)
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p += vel * t;
	vel = vel * pow(damping, t) + acc * t;


	remainning_time--;
}
bool Particle::isAlive()
{
	return remainning_time>0;
}

Particle* Particle::clone() const
{
	Particle* p = new Particle(pos, vel, acc, size, opacity, color.getXYZ(), remainning_time,true);
	return p;
}

void Particle::setVel(Vector3 vel)
{
	this->vel = vel;
}

void Particle::setPos(Vector3 pos)
{
	this->pos = pos;
	pose.p = pos;
}
