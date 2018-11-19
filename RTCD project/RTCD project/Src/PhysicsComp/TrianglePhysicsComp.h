#pragma once
#include "PhysicsComp.h"
#include <memory>
class TrianglePhysicsComp :
	public PhysicsComp
{
public:
	TrianglePhysicsComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc);
	virtual ~TrianglePhysicsComp();


private:

	glm::vec2 pointOne;
	glm::vec2 pointTwo;
	glm::vec2 pointThree;

	glm::vec2 velocity;
	glm::vec2 acceleration;

	std::shared_ptr<Transform> ShapeTransform;

};


