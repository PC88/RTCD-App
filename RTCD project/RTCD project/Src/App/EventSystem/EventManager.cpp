#include "EventManager.h"



EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

bool EventManager::AABBAABBCollision(PhysicsComp& A, PhysicsComp& B) // for now we just use this - PC
{
	if (abs(A.getPosition().x - B.getPosition().x) > (A.GetPosition().x + B.GetPosition().x)) return false;
	if (abs(A.getPosition().y - B.getPosition().y) > (A.GetPosition().y + B.GetPosition().y)) return false;
	return true;
}

bool EventManager::CircleAABBCollision(PhysicsComp& c1, PhysicsComp& b)
{
	vec2 closestPoint;
	ClosestPtPointAABB(c1.getPosition(), b, closestPoint);
	if (distance(c1.getPosition(), closestPoint) <= c1.getRadius())
		return true;
	return false;
}
