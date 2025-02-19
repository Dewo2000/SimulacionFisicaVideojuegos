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

		if (fabs(p->getImass()) < 1e-10)return;
		Vector3 v = p->getVel();
		Vector3 pos = p->getPos();
		Vector3 twistervel = _K*Vector3(-(pos.z - _pos.z) - pos.x - _pos.x, 50 - (pos.y - _pos.y), pos.x - _pos.x - (pos.z - _pos.z));
		Vector3 drag_coef = twistervel - v;
		Vector3 fforce;
		fforce = _k1 * drag_coef + _k2 * drag_coef.magnitude() * drag_coef;
		p->addForce(fforce);
	}

	virtual void updateForce(RigidParticle* p, double t) {
		if (activatedTwister) {
			if (fabs(p->getImass()) < 1e-10)return;
			Vector3 v = p->getVel();
			Vector3 pos = p->getPos();
			Vector3 twistervel = _K * Vector3(-(pos.z - _pos.z) - pos.x - _pos.x, 50 - (pos.y - _pos.y), pos.x - _pos.x - (pos.z - _pos.z));
			Vector3 drag_coef = twistervel - v;
			Vector3 fforce;
			fforce = _k1 * drag_coef + _k2 * drag_coef.magnitude() * drag_coef;
			p->getSolid()->addForce(fforce);
		}
	}
	void activate() { activatedTwister=!activatedTwister; }
protected:
	Vector3 _pos;
	float _K;
	bool activatedTwister=true;
};