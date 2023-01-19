#include "Floor.h"
using namespace physx;
Floor::Floor(Vector3 Pos, Vector4 color)
{
	pos = PxTransform(Pos);
	renderItem = new RenderItem(CreateShape(PxBoxGeometry(150,0.2,150)), &pos, color);
}
