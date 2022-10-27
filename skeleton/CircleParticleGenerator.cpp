#include "CircleParticleGenerator.h"

CircleParticleGenerator::CircleParticleGenerator(Vector3 pos, Vector3 vel, Vector3 std_dev_pos, Vector3 std_dev_vel, double genPro, int numP, double vel_circle):
    GaussianParticleGenerator(pos,vel,std_dev_pos,std_dev_vel,genPro,numP)
{
    cvel = vel_circle;
}

vector<Particle*> CircleParticleGenerator::generateParticles()
{
    vector<Particle*> aux = GaussianParticleGenerator::generateParticles();
    double ang=0;
    double offset = 2 * 3.1415926 / aux.size();
    for (Particle* p : aux) {
        Vector3 velocity = { std::cosf(ang),std::sinf(ang) ,std::sinf(ang / 2) };
        velocity.x *= cvel;
        velocity.y *= cvel;
        p->setVel(velocity);
        ang += offset;
    }
    return aux;
}
