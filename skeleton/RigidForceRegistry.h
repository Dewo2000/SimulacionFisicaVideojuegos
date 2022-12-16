#pragma once
#include <map>
#include "RigidParticle.h"
#include "ForceGenerator.h"
typedef std::pair<ForceGenerator*, RigidParticle*> Fpair;
class RigidForceRegistry :public std::multimap<ForceGenerator*, RigidParticle*> {
public:
	void updateForces(double duration) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, duration);
		}
	}
	void addRegistry(ForceGenerator* fg, RigidParticle* p) {
		this->insert(Fpair(fg, p));

	}
	void deleteParticleRegistry(RigidParticle* p) {
		for (auto it = begin(); it != end(); it++) {
			if (it->second == p) {
				erase(it);
				it--;
			}
		}
	}
	void deleteParticleRegistry(ForceGenerator* fg, RigidParticle* p) {
		for (auto it = begin(); it != end(); it++) {
			if (it->first == fg && it->second == p) {
				erase(it);
				return;
			}
		}
	}
	void deleteAll() {
		for (auto it = begin(); it != end(); it++) {
			erase(it);
		}
	}
};

