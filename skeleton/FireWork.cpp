#include "FireWork.h"

FireWork::FireWork(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Opacity, Vector3 ColorRGB, double aliveTime,physx::PxShape* shape, vector<shared_ptr<ParticleGenerator>>gens,float mass, bool rende):
	Particle(Pos,Vel,Acc,Opacity,ColorRGB,aliveTime,shape,mass,rende)
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
	FireWork* p = new FireWork(pos, vel, acc, opacity, color.getXYZ(), remainning_time,shape,generators,inverss_mass);
	return p;
}
