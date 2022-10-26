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
	for (int i = 0; i < _particles.size(); i++) {
		_particles[i]->integrate(t);
		if (!_particles[i]->isAlive()) {
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		}
	}
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	return nullptr;
}

void ParticleSystem::generateFireworkSystem()
{
	GaussianParticleGenerator* fPG = new GaussianParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 });
	_particle_generators.push_back(fPG);

}
