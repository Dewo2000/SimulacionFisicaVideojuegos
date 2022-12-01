#include "Floor.h"
using namespace physx;
Floor::Floor(Vector3 Pos, Vector4 color)
{
	pos = PxTransform(Pos);
	renderItem = new RenderItem(CreateShape(PxBoxGeometry(50,0.2,50)), &pos, color);
}
