#include "ParticleSystem.h"

void ParticleSystem::update(double t)
{
	for (Particle* p : _particles) {
		p->integrate(t);
	}
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	return nullptr;
}

void ParticleSystem::generateFireworkSystem()
{
}
