#pragma once
#include "DragGenerator.h"
class TwisterWindGenerator :public DragGenerator {
public:
	TwisterWindGenerator(Vector3 pos, Vector3 fv,const float K ,const float k1, const float k2)
	{
		_pos = pos;
		windforce = fv;
		_k1 = k1;
		_k2 = k2;
		_K = K;

	};
	virtual void updateForce(Particle* p, double t) {
		float Aeff = 1;
		float Cd = 0.5;
		float densidad = 1.29;
		float F = Aeff * Cd * densidad;


		if (fabs(p->getImass()) < 1e-10)return;
		Vector3 v = p->getVel();
		Vector3 pos = p->getPos();
		Vector3 twistervel = _K*Vector3(-(pos.z - _pos.z), 50 - (pos.y - _pos.y), pos.x - _pos.x);
		Vector3 drag_coef = twistervel - v;
		Vector3 fforce;
		fforce = _k1 * drag_coef + _k2 * drag_coef.magnitude() * drag_coef;
		p->addForce(fforce);
	}

protected:
	Vector3 _pos;
	float _K;
};