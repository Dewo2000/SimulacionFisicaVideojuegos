#include "Esfera.h"
using namespace physx;
Esfera::Esfera(Vector3 Pos)
{
	pos = PxTransform(Pos);
	Vector4 const color = { 1,0,0,1 };
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(10)), &pos, color);
}
