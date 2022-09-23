#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
class Floor
{
public:
	Floor(Vector3 Pos);
private:
	physx::PxTransform pos;
	RenderItem* renderItem;
};

