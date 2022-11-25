#include "Particle.h"

using namespace physx;
Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Opacity, Vector3 ColorRGB, 
	double aliveTime, physx::PxShape* shape, float mass, bool render)
	:vel(Vel), acc(Acc), opacity(Opacity), color({ ColorRGB, opacity }), remainning_time(aliveTime){

	this->shape = shape;
	if (mass == 0) {
		inverss_mass = 0;
	}
	else
	{
		inverss_mass = 1 / mass;
	}
	force = { 0,0,0 };
	this->mass = mass;
	pos = Pos;
	pose = PxTransform(Pos);
	
	if (render)
		renderItem = new RenderItem(shape, &pose, color);
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
	//if (inverss_mass <= 0) return;

	//pose.p += vel * t;
	//Vector3 totalAcc = acc;
	//totalAcc += force * inverss_mass;
	//vel += totalAcc * t;
	////pose.p += vel * t;

	//vel *= pow(damping, t);

	//remainning_time -= t;

	//clearForce();
	//--------------------
	if (inverss_mass <= 0) return;

	//pose.p += vel * t;
	Vector3 totalAcc = acc;
	totalAcc += force * inverss_mass;
	vel += totalAcc * t;
	
	vel *= pow(damping, t);
	
	pose.p += vel * t;
	remainning_time -= t;

	clearForce();

}
bool Particle::isAlive()
{
	return remainning_time>0;
}

Particle* Particle::clone() const
{
	Particle* p = new Particle(pos, vel, acc, opacity, color.getXYZ(), remainning_time,shape,true);
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

void Particle::clearForce()
{
	force = { 0,0,0 };
}


void Particle::addForce(const Vector3& f)
{
	force += f;
}
