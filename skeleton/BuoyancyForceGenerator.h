#pragma once
#include "ForceGenerator.h"
class BuoyancyForceGenerator : public ForceGenerator
{
public:
	BuoyancyForceGenerator(float h,float V,float d) {
		height = h;
		volume = V;
		liquid_density = d;
		//l_particle = new Particle()
	};
	virtual ~BuoyancyForceGenerator() {};
	virtual void updateForce(Particle* p, double t) {
		float h = p->getPos().y;
		//float h0 = l_particle->getPos().y;
		float h0 = -110;
		Vector3 f(0, 0, 0);
		float immersed = 0.0;
		if (h - h0 > height * 0.5) { immersed = 0.0; }
		else if (h0 - h > height * 0.5) { immersed = 1.0; }
		else { immersed = (h0 - h) / height + 0.5; }
		f.y = liquid_density * volume * immersed * 9.8;
		p->addForce(f);
	}
protected:
	float height;
	float volume;
	float liquid_density;
	float gravity = 9.8f;

	Particle* l_particle; 
};

