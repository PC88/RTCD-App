#pragma once
#include "PhysicsComp.h"
#include <memory>

class CirclePhysicsComp :
	public PhysicsComp
{
public:
	CirclePhysicsComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc);
	virtual ~CirclePhysicsComp();
};

