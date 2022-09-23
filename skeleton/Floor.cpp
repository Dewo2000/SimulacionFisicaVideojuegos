#include "Floor.h"
using namespace physx;
Floor::Floor(Vector3 Pos)
{
	pos = PxTransform(Pos);
	Vector4 const color = { 0,1,0,1 };
	renderItem = new RenderItem(CreateShape(PxBoxGeometry(100,1,100)), &pos, color);
}
