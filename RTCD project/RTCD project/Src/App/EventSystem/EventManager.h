#pragma once
#include <vector>
#include "PhysicsComp.h"
#include "glm/vec2.hpp"

class Shape;
class EventManager
{
public:

	bool CircleAABBCollision(const PhysicsComp& c1, const PhysicsComp& b);
	void ClosestPtPointAABB(glm::vec2 const & P, const PhysicsComp& b, glm::vec2& q);
	bool AABBAABBCollision(const PhysicsComp& A, const PhysicsComp& B);

	void CheckCollisions();

	EventManager(std::vector<Shape*>&); // this is gonna get wild -PC
	virtual ~EventManager();

private:
	std::vector<Shape*> activePool;
};

