#include "Particle.h"
#include <iostream>
using namespace std;
class ParticleGenerator
{
public:
	ParticleGenerator(string name,Vector3 pos,Vector3 vel,double generate_probability,int num_particles):
		_name(name),_mean_pos(pos),_mean_vel(vel),generation_probability(generate_probability),_num_particles(num_particles){};
	~ParticleGenerator()=default;
	void setParticle(Particle* model);
	virtual vector<Particle*> generateParticles() = 0;
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double generation_probability;
	int _num_particles;
	Particle* _model=nullptr;
};