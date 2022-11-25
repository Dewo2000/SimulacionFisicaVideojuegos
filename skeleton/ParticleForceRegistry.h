#pragma once
#include <map>
#include "Particle.h"
#include "ForceGenerator.h"
typedef std::pair<ForceGenerator*, Particle*> FRpair;
class ParticleForceRegistry:public std::multimap<ForceGenerator*,Particle*> {
public:
	void updateForces(double duration) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, duration);
		}
	}
	void addRegistry(ForceGenerator* fg, Particle* p) {
		this->insert(FRpair(fg, p));

	}
	void deleteParticleRegistry(Particle *p) {
		for (auto it = begin(); it != end(); it++) {
			if (it->second == p) {
				erase(it);
				it--;
			}
		}
	}
	void deleteParticleRegistry(ForceGenerator* fg,Particle* p) {
		for (auto it = begin(); it != end(); it++) {
			if (it->first==fg && it->second == p) {
				erase(it);
				return;
			}
		}
	}

};