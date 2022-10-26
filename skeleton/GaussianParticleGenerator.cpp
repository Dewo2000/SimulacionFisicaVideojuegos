#include "GaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator(Vector3 pos, Vector3 vel,Vector3 std_dev_pos, Vector3 std_dev_vel)
{
    _name = "Gaussian";
    _mean_pos = pos;
    _mean_vel = vel;
    generation_probability = 1;
    this->std_dev_pos = std_dev_pos;
    this->std_dev_vel = std_dev_vel;
    _num_particles = 10;
	std:random_device r;
	random_generator = std::mt19937(r());
}

vector<Particle*> GaussianParticleGenerator::generateParticles()
{
    vector<Particle*>vP;
    for (int i = 0; i < _num_particles; i++) {
        auto rp = std::uniform_real_distribution<double>(0, 1);
        if (rp(random_generator) < generation_probability) {
            auto px = std::normal_distribution<float>(_mean_pos.x - std_dev_pos.x / 2, _mean_pos.x + std_dev_pos.x / 2);
            auto py = std::normal_distribution<float>(_mean_pos.y - std_dev_pos.y / 2, _mean_pos.y + std_dev_pos.y / 2);
            auto pz = std::normal_distribution<float>(_mean_pos.z - std_dev_pos.z / 2, _mean_pos.z + std_dev_pos.z / 2);
            auto vx = std::normal_distribution<float>(_mean_vel.x - std_dev_vel.x / 2, _mean_vel.x + std_dev_vel.x / 2);
            auto vy = std::normal_distribution<float>(_mean_vel.y - std_dev_vel.y / 2, _mean_vel.y + std_dev_vel.y / 2);
            auto vz = std::normal_distribution<float>(_mean_vel.z - std_dev_vel.z / 2, _mean_vel.z + std_dev_vel.z / 2);

            Vector3 pos = Vector3(px(random_generator), py(random_generator), pz(random_generator));
            Vector3 vel = Vector3(px(random_generator), py(random_generator), pz(random_generator));

            vP.push_back(new Particle(pos, vel, { 0,-10,0 }, 1, 1, { 0,1,0 },100));
        }
    }
    return vP;
}
