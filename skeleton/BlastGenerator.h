#pragma once
#include "ForceGenerator.h"
#include <cmath>
class BlastGenerator : public ForceGenerator
{
public:
	BlastGenerator():_center((0,0,0)),_force((0,0,0)),_radius(0),explosion_constant(0) {};
	BlastGenerator(Vector3 center, float force ,double explosion_cosnt, double radius) :_center(center), _force(force),explosion_constant(explosion_cosnt),_radius(radius) {};
	virtual void updateForce(Particle* p, double t) {

		Vector3 ppos = p->getPos();
		float x = (ppos.x - _center.x);
		float y = (ppos.y - _center.y);
		float z = (ppos.z - _center.z);
		double r = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
		_radius = ve * time;
		if (r < _radius) {
			Vector3 fforce;
			Vector3 center = Vector3(x, y, z);
			double e = 2.7182818284590452353602874713527;
			fforce = (_force / pow(r, 2)) * center * pow(e, -(time / explosion_constant));
			p->addForce(fforce);
		}
		time += t;

	}
	void setForce(float force) { _force = force; }
	void setCenter(Vector3 center) { _center = center; }
	void setRadius(double radius) { _radius = radius; }
	void setConstant(double constant) { explosion_constant = constant; }
private:
	Vector3 _center;
	float _force;
	double explosion_constant;
	double _radius;
	double ve = 1.235;
	double time = 0;
};

