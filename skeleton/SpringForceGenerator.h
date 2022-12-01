#pragma once
#include "ForceGenerator.h"
using namespace physx;
class SpringForceGenerator : public ForceGenerator
{
public:
	SpringForceGenerator(Vector3 r2, double k , double l0,bool elastic=false):_k(k),_l0(l0),_elastic(elastic){
		_other = new Particle(r2, { 0,0,0 }, { 0,0,0 }, 1, { 1,1,1 }, 1000,CreateShape(PxBoxGeometry(1,1,1)));
	};
	SpringForceGenerator(Particle* other,double k,double l0, bool elastic = false):_other(other), _k(k), _l0(l0),_elastic(elastic) {};

	~SpringForceGenerator() {
		delete _other; 
	};

	virtual void updateForce(Particle* p,double t) {

		Vector3 force = p->getPos() - _other->getPos();
		const float l = force.normalize();
		const float dx = l - _l0;
		if (_elastic && dx <= 0.0f) return;
		force *= -dx * _k;
		p->addForce(force);
	}

	inline void setK(double k) { _k = k; }

private:
	//Constante Elastica
	double _k;
	//Longitud del muelle en reposo
	double _l0;
	Particle* _other;
	bool _elastic;
};

