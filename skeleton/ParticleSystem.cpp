#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	forceRegistry = new ParticleForceRegistry();
	std:random_device r;
	random_generator = std::mt19937(r());
}

void ParticleSystem::update(double t)
{
	forceRegistry->updateForces(t);
	for (int i = 0; i < _particles.size(); i++) {

		_particles[i]->integrate(t);
		if (!_particles[i]->isAlive()) {
			onParticleDead(_particles[i]);
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		}
	}
	for (ParticleGenerator* g:_particle_generators)
	{
		vector<Particle*> aux=  g->generateParticles();
		for (Particle* p : aux)
		{
			_particles.push_back(p);
		}
	}
	
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	return nullptr;
}

void ParticleSystem::generateFireworkSystem()
{
	//Particle* p = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 0.3,0.3,1 }, 10,1, false);
	//Particle* p2 = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 1,1,1 }, 10,1, false);
	//Particle* p3 = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 0,0,1 }, 10,1, false);
	//shared_ptr<ParticleGenerator> gen1(new CircleParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 1,1,1 }, { 10,10,1 }, 0.3, 30,30));
	//shared_ptr<ParticleGenerator> gen2(new UniformParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 10,10,1 }, { 10,10,1 }, 0.7, 2));
	//shared_ptr<ParticleGenerator> gen3(new GaussianParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 10,10,1 }, { 10,10,1 }, 1, 4));
	//shared_ptr<ParticleGenerator> gen4(new GaussianParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 10,10,1 }, { 10,10,1 }, 1, 6));
	//shared_ptr<ParticleGenerator> gen5(new CircleParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 1,1,1 }, { 10,10,1 }, 0.3, 30, 30));
	//shared_ptr<ParticleGenerator> gen6(new CircleParticleGenerator({ 0,0,0 }, { 0,0,0 }, { 1,1,1 }, { 10,10,1 }, 0.3, 30, 30));


	//_fireworkpool.push_back(new FireWork({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.2, 1, { 0,0,1 }, 1.5, { gen1,gen5,gen6 },1, false));
	//_fireworkpool.push_back(new FireWork({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.3, 1, { 0.8,0.8,1 }, 1.5, { gen2,gen6 },1, false));
	//_fireworkpool.push_back(new FireWork({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.4, 1, { 0.5,0.5,1 }, 1.5, { gen3,gen5 },1, false));
	//_particles.push_back(new FireWork({ 0,-50,0 }, { 0,40,0 }, { 0,-10,0 }, 0.5, 1, { 1,1,1 }, 2, { gen4,gen3,gen6 },1));

	//gen1.get()->setParticle(p);
	//gen2.get()->setParticle(_fireworkpool[0]);
	//gen3.get()->setParticle(_fireworkpool[1]);
	//gen4.get()->setParticle(_fireworkpool[2]);
	//gen5.get()->setParticle(p2);
	//gen6.get()->setParticle(p3);

	

}
void ParticleSystem::testGenerators()
{
	/*Particle* p = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 0,1,0 }, 1000,false);
	GaussianParticleGenerator* gG = new GaussianParticleGenerator({ 20,-20,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 },1,10);
	gG->setParticle(p);
	_particle_generators.push_back(gG);
	Particle* up = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 0,0,1 }, 1000,false);
	UniformParticleGenerator* uG = new UniformParticleGenerator({ -20,-20,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 },1,10);
	uG->setParticle(up);
	_particle_generators.push_back(uG);
	Particle* cp = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.1, 1, { 1,0,0 }, 1000, false);
	CircleParticleGenerator* cG = new CircleParticleGenerator({ 0,20,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 }, 1, 10,10);
	cG->setParticle(cp);
	_particle_generators.push_back(cG);*/
}

void ParticleSystem::shootFirework(int type)
{
	
	generateFireworkSystem();
}

void ParticleSystem::addParticleForce()
{
	for (ForceGenerator* g : force_generator) {
		if (g->name == "imp") {
			for (Particle* p : _particles)
			{
				forceRegistry->addRegistry(g, p);
			}
			return;
		}
	}
}

void ParticleSystem::deleteParticleForce()
{
	for (ForceGenerator* g : force_generator) {
		if (g->name == "imp") {
			for (Particle* p : _particles)
			{
				forceRegistry->deleteParticleRegistry(g, p);
			}
			return;
		}
	}
}

void ParticleSystem::setK(double d)
{
	for (ForceGenerator* g : force_generator) {
		if (g->name == "stat") {
			SpringForceGenerator* sfg = (SpringForceGenerator*)g;
			sfg->setK(d);
		}
	}
}

void ParticleSystem::onParticleDead(Particle* p)
{
	forceRegistry->deleteParticleRegistry(p);
	if (p->isFirework()) {
		FireWork* f = (FireWork*)p;
		auto newparticles = f->explode();
		for (auto par : newparticles)_particles.push_back(par);
	}
}

void ParticleSystem::testForceGenerators() {
	GravityForceGenerator* gfg = new GravityForceGenerator({ 0,-10,0 });
	//GravityForceGenerator* gfg2 = new GravityForceGenerator({ 0,-8,0 });

	//Particle* p = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, 1, { 1,1,1 }, 1000 , 0.0001);
	//_particles.push_back(p);
	//Particle* p2 = new Particle({ 10,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, 1, { 1,1,0 }, 1000, 0.0001);
	//_particles.push_back(p2);
	//Particle* p3 = new Particle({ -10,0,0 }, { 0,0,0 }, { 0,-10,0 }, 1, 1, { 1,1,0 }, 1000, 0.0001);
	//_particles.push_back(p3);
	//Particle* p4 = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, 1, { 0,1,1 }, 1000, 0.001);
	//_particles.push_back(p4);

	//freg->addRegistry(gfg, p);
	//freg->addRegistry(gfg, p4);
	//freg->addRegistry(gfg2, p2);

	//DragGenerator* dg = new DragGenerator({10,0,0},0.1,0.05);

	//TwisterWindGenerator* twg = new TwisterWindGenerator({ 0,0,0 }, { 0, 0, 0 },1, 0.1, 0.05);
	/*BlastGenerator* bg = new BlastGenerator({ 0,0,0 }, 10000,10, 20);
	auto size = std::uniform_real_distribution<double>(0, 10);
	for (int i = 0; i < 20; i++) {
		float x = size(random_generator) - 5;
		float y = size(random_generator) - 5;
		float z = size(random_generator) - 5;

		Particle* p = new Particle({x,y,z}, { 0,0,0 }, { 0,0,0 },1, 1, { 1,1,1 }, 1000,Pxgeo);
		_particles.push_back(p);
		forceRegistry->addRegistry(bg, p);
	}*/

	/*Particle* p1 = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, 1, { 1,1,1 }, 1000, 0.05);
	_particles.push_back(p1);
	forceRegistry->addRegistry(dg, p1);
	forceRegistry->addRegistry(gfg, p1);

	Particle* p2 = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, 1, { 1,1,1 }, 1000, 1);
	_particles.push_back(p2);
	forceRegistry->addRegistry(dg, p2);
	forceRegistry->addRegistry(gfg, p2);*/
}

void ParticleSystem::testSpringForce()
{
	GravityForceGenerator* gfg = new GravityForceGenerator({ 0,-10,0 });
	gfg->name = "gravity";
	SpringForceGenerator* stat = new SpringForceGenerator(Vector3(0, 0, 0), 1, 10);
	stat->name = "stat";
	force_generator.push_back(stat);
	GravityForceGenerator* imp = new GravityForceGenerator({ 0,5,0 });
	imp->name = "imp";
	force_generator.push_back(imp);

	Particle* p1 = new Particle({ 10,0,0 }, { 0,0,0 }, { 0,0,0 }, 1, { 1,0,0 }, 1000, CreateShape(PxSphereGeometry(1)), 1);
	_particles.push_back(p1);
	forceRegistry->addRegistry(stat, p1);
	forceRegistry->addRegistry(gfg, p1);
}

