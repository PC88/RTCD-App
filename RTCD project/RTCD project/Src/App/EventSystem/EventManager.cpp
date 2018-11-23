#include "EventManager.h"
#include "Shape.h"

EventManager::EventManager(std::vector<Shape*>&)
{
}


EventManager::~EventManager()
{
}

bool EventManager::AABBAABBCollision(const Shape& A, const Shape& B) // for now we just use this - PC
{
	if (abs(A.GetPosition().x - B.GetPosition().x) > (A.GetPosition().x + B.GetPosition().x)) return false;
	if (abs(A.GetPosition().y - B.GetPosition().y) > (A.GetPosition().y + B.GetPosition().y)) return false;
	return true;
}

void EventManager::CheckCollisions()
{
}

bool EventManager::CircleAABBCollision(const Shape& c1, const Shape& b)
{
	glm::vec2 closestPoint;
	ClosestPtPointAABB(c1.GetPosition(), b, closestPoint);
	if (distance(c1.GetPosition(), closestPoint) <= c1.GetDistanceMetric())
		return true;
	return false;
}

void EventManager::ClosestPtPointAABB(glm::vec2 const &  P, const Shape& b, glm::vec2 & q)
{
	glm::vec2 min(b.GetPosition() - b.GetDistanceMetric());
	glm::vec2 max(b.GetPosition() + b.GetDistanceMetric());
	for (int i = 0; i < 2; i++)
	{
		float v = P[i];
		if (v < min[i]) v = min[i];
		if (v > max[i]) v = max[i];
		q[i] = v;
	}
}
