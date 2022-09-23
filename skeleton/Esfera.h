#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <iostream>
class Esfera
{
public:
	Esfera(Vector3 Pos);
private:
	physx::PxTransform pos;
	RenderItem* renderItem;
};

