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
	PxRigidDynamic* solid; 
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
}

void RigidParticle::clone(Vector3 Pos, Vector3 Vel)
{
	PxRigidDynamic* solid;
	solid = _gphysic->createRigidDynamic(PxTransform(Pos));
	solid->setLinearVelocity(Vel);
	solid->setAngularVelocity({ 0,0,0 });
	solid->attachShape(*_shape);
	renderItem = new RenderItem(_shape, solid, color);
	solid->setMass(_mass);
	if (_shape->getGeometryType() == PxGeometryType::eBOX) {
		Vector3 size = _shape->getGeometry().box().halfExtents;
		solid->setMassSpaceInertiaTensor({ size.y * size.z,size.x * size.z,size.y * size.x });
	}
	else {
		float size = _shape->getGeometry().sphere().radius;
		float size2 = size * size;
		solid->setMassSpaceInertiaTensor({ size2,size2,size2 });
	}
	_scene->addActor(*solid);
}
