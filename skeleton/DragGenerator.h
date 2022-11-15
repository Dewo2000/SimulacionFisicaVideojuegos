#pragma once
#include "ForceGenerator.h"
class DragGenerator :public ForceGenerator
{
public:
	DragGenerator() {};
	DragGenerator(Vector3 fv) : windforce(fv), _k1(0), _k2(0) {};
	DragGenerator(Vector3 fv,const float k1,const float k2):windforce(fv), _k1(k1), _k2(k1) {};
	virtual void updateForce(Particle* p, double t) {
		float Aeff = 1;
		float Cd = 0.5;
		float densidad = 1.29;
		float F = Aeff * Cd * densidad;


		if (fabs(p->getImass()) < 1e-10)return;
		Vector3 v = p->getVel();
		Vector3 drag_coef = windforce-v ;
		Vector3 fforce;
		fforce = _k1 * drag_coef + _k2 * drag_coef.magnitude() * drag_coef;
		p->addForce(fforce);
	}
	inline void setDrag(float k1, float k2) { _k1 = k1; _k2 = k2; }
	inline float getK1() { return _k1; }
	inline float getK2() { return _k2; }
protected:
	Vector3 windforce;
	float _k1, _k2;
};