#pragma once
#include "ForceGenerator.h"
class GravityForceGenerator : public ForceGenerator
{
public:
	GravityForceGenerator(const Vector3& g) { _gravity = g; };

	virtual void updateForce(Particle* p, double t) {
		if (fabs(p->getImass()) < 1e-10)return;
		p->addForce(_gravity * p->getmass());
	}
	virtual void updateForce(RigidParticle* p, double t) {
		if (fabs(p->getImass()) < 1e-10)return;
		p->getSolid()->addForce(_gravity * p->getmass());
	}
	inline void setGravity(Vector3 g) { _gravity = g; }
protected:
	Vector3 _gravity;
};