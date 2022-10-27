#include "FireWork.h"

FireWork::FireWork(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Size, float Opacity, Vector3 ColorRGB, double aliveTime, vector<shared_ptr<ParticleGenerator>>gens, bool rende):
	Particle(Pos,Vel,Acc,Size,Opacity,ColorRGB,aliveTime,rende)
{
	for (auto g : gens)generators.push_back(g);
}

vector<Particle*> FireWork::explode()
{
	vector<Particle*> aux;
	for (std::shared_ptr<ParticleGenerator> g : generators) {
		auto particulas = g.get()->generateParticles();
		for (Particle* p : particulas) {
			p->setVel(p->getVel() + vel);
			p->setPos(pose.p);
			aux.push_back(p);
		}
	}
	return aux;
}

Particle* FireWork::clone() const
{
	FireWork* p = new FireWork(pos, vel, acc, size, opacity, color.getXYZ(), remainning_time,generators);
	return p;
}
