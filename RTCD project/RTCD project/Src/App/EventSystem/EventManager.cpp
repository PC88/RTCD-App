#include "EventManager.h"
#include "Shape.h"

EventManager::EventManager(std::vector<Shape*>&)
{
}


EventManager::~EventManager()
{
}

bool EventManager::AABBAABBCollision(const Shape& A, const Shape& B) 
{
	if (abs(A.GetPosition().x - B.GetPosition().x) > (A.GetPosition().x + B.GetPosition().x)) return false;
	if (abs(A.GetPosition().y - B.GetPosition().y) > (A.GetPosition().y + B.GetPosition().y)) return false;
	return true;
}

bool EventManager::CircleCircleCollision(Shape* S1, Shape * S2)
{
	float diameter = S1->GetDistanceMetric() * 2;
	if (abs(diameter) < (abs(distance(S1->GetPosition(),S2->GetPosition())))) // very cheap -PC
	{
		return true;
		S1->OnCollide(S2->GetType()); // call respective collision reactions -PC
		S2->OnCollide(S1->GetType());
	}
	return false;
}

void EventManager::CheckCollisions(Shape* shape1, Shape* shape2)
{
	if (shape1->GetType() == 0 && shape2->GetType() == 0)// C-C -PC
	{
		CircleCircleCollision(shape1, shape2);
	}
	else if (shape1->GetType() == 0 && shape2->GetType() == 2)// C-S -PC
	{
	}
	else if (shape1->GetType() == 0 && shape2->GetType() == 1)// C-T -PC
	{
	}
	else if (shape1->GetType() == 2 && shape2->GetType() == 2)// S-S -PC
	{
	}
	else if (shape1->GetType() == 1 && shape2->GetType() == 1)// T-T -PC
	{
	}
	else if (shape1->GetType() == 2 && shape2->GetType() == 1)// S-T -PC
	{
	}
}

bool EventManager::CircleAABBCollision(const Shape& c1, const Shape& b) // inefficient for C-C -PC
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
