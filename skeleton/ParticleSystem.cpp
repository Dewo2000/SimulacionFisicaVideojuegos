#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* g:_particle_generators)
	{
		vector<Particle*> aux=  g->generateParticles();
		for (Particle* p : aux)
		{
			_particles.push_back(p);
		}
	}
	for (Particle* p : _particles) {
		p->integrate(t);
		if (!p->isAlive())
			delete p;
			
	}
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	return nullptr;
}

void ParticleSystem::generateFireworkSystem()
{
	UniformParticleGenerator* fPG = new UniformParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 });
	_particle_generators.push_back(fPG);

}
