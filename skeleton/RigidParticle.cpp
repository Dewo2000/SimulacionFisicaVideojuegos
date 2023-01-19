#include "RigidParticle.h"

RigidParticle::RigidParticle(Vector3 Pos, Vector3 Vel, Vector4 ColorRGBA, PxShape* shape, float mass, PxPhysics* physic, PxScene* scene,PxMaterial* material)
{
	pose = PxTransform(Pos);
	vel = Vel;
	color = ColorRGBA;
	_shape = shape;
	_mass = mass;
	_gphysic = physic;
	_scene = scene;
	_material = material;

	if (material != nullptr)_shape->setMaterials(&material, 1);

	solid = _gphysic->createRigidDynamic(pose);
	solid->setLinearVelocity(vel);
	solid->setAngularVelocity({ 0,0,0 });
	solid->attachShape(*_shape);
	renderItem = new RenderItem(_shape, solid, color);
	solid->setMass(mass);
	if (_shape->getGeometryType() == PxGeometryType::eBOX) {
		Vector3 size = _shape->getGeometry().box().halfExtents;
		solid->setMassSpaceInertiaTensor({ size.y * size.z,size.x * size.z,size.y * size.x });
	}
	else {
		float size = _shape->getGeometry().sphere().radius;
		float size2 = size * size;
		solid->setMassSpaceInertiaTensor({size2,size2,size2});
	}
	_scene->addActor(*solid);

	std:random_device r;
	random_generator = std::mt19937(r());
}

RigidParticle* RigidParticle::clone(Vector3 Pos, Vector3 Vel,Vector4 Color,bool random)
{
	auto siz = std::uniform_real_distribution<float>(1, 2);
	PxShape* shape;
	if (_shape->getGeometryType() == PxGeometryType::eBOX) {		
		if (random) {
			Vector3 size = Vector3(siz(random_generator), siz(random_generator), siz(random_generator));
			shape = CreateShape(PxBoxGeometry(size));
		}
		else
		{
			Vector3 size = _shape->getGeometry().box().halfExtents;
			shape = CreateShape(PxBoxGeometry(size));
		}
	}
	else {
		if (random) {
			float size = siz(random_generator);
			shape = CreateShape(PxSphereGeometry(size));
		}
		else
		{
			float size = _shape->getGeometry().sphere().radius;
			shape = CreateShape(PxSphereGeometry(size));
		}
	}
	if (Color != Vector4(0, 0, 0, 0)) {
		color = Color;
	}
	if(random)
		return new RigidParticle(Pos, Vel, color, shape, _mass, _gphysic, _scene, _material);
	else
		return new RigidParticle(Pos, Vel, color, shape, _mass, _gphysic, _scene, _material);
}

void RigidParticle::addForce(Vector3 force)
{
	solid->addForce(force);
}

void RigidParticle::clearForce()
{
	solid->clearForce();
	solid->setLinearVelocity({ 0,0,0 });
	solid->setAngularVelocity({ 0,0,0 });
}

bool RigidParticle::integrate(double t)
{
	time += t;
	if (time > aliveTime) {
		release();
		return true;
	}
	if (solid->getGlobalPose().p.y < -100) {
		release();
		return true;
	}
	return false;
}

void RigidParticle::release()
{
	renderItem->release();
	solid->release();
}
