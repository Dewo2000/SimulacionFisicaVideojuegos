#include "UniformParticleGenerator.h"


UniformParticleGenerator::UniformParticleGenerator(Vector3 pos, Vector3 vel, Vector3 posWidth, Vector3 velWidth)
{
    _name = "Uniforme";
    _mean_pos = pos;
    _mean_vel = vel;
    generation_probability = 1;
    _num_particles = 10;
    _pos_width = posWidth;
    _vel_width = velWidth;
    std:random_device r;
    random_generator = std::mt19937(r());
}

vector<Particle*> UniformParticleGenerator::generateParticles()
{
    vector<Particle*>vP;
    for (int i = 0; i < _num_particles; i++) {
        auto rp = std::uniform_real_distribution<double>(0, 1);
        if (rp(random_generator) < generation_probability) {
            auto px = std::uniform_real_distribution<float>(_mean_pos.x - _pos_width.x / 2, _mean_pos.x + _pos_width.x / 2);
            auto py = std::uniform_real_distribution<float>(_mean_pos.y - _pos_width.y / 2, _mean_pos.y + _pos_width.y / 2);
            auto pz = std::uniform_real_distribution<float>(_mean_pos.z - _pos_width.z / 2, _mean_pos.z + _pos_width.z / 2);
            auto vx = std::uniform_real_distribution<float>(_mean_vel.x - _vel_width.x / 2, _mean_vel.x + _vel_width.x / 2);
            auto vy = std::uniform_real_distribution<float>(_mean_vel.y - _vel_width.y / 2, _mean_vel.y + _vel_width.y / 2);
            auto vz = std::uniform_real_distribution<float>(_mean_vel.z - _vel_width.z / 2, _mean_vel.z + _vel_width.z / 2);

            Vector3 pos = Vector3(px(random_generator), py(random_generator), pz(random_generator));
            Vector3 vel = Vector3(vx(random_generator), vy(random_generator), vz(random_generator));

            vP.push_back(_model->clone());
        }
    }
    return vP;
}
