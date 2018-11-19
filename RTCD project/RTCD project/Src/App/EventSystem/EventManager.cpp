#include "EventManager.h"
#include "glm/vec2.hpp"
#include "Shape.h"

EventManager::EventManager(std::vector<Shape*>&)
{
}


EventManager::~EventManager()
{
}

bool EventManager::AABBAABBCollision(const PhysicsComp& A, const PhysicsComp& B) // for now we just use this - PC
{
	if (abs(A.GetPosition().x - B.GetPosition().x) > (A.GetPosition().x + B.GetPosition().x)) return false;
	if (abs(A.GetPosition().y - B.GetPosition().y) > (A.GetPosition().y + B.GetPosition().y)) return false;
	return true;
}

void EventManager::CheckCollisions()
{
}

bool EventManager::CircleAABBCollision(const PhysicsComp& c1, const PhysicsComp& b)
{
	glm::vec2 closestPoint;
	ClosestPtPointAABB(c1.GetPosition(), b, closestPoint);
	if (distance(c1.GetPosition(), closestPoint))// <= c1.GetDirection()) --- this needs to have a get radius method here -PC
		return true;
	return false;
}

void EventManager::ClosestPtPointAABB(glm::vec2 const &  P, const PhysicsComp & b, glm::vec2 & q)
{
}
