#include "EventManager.h"
#include "Shape.h"
#include "Triangle.h"

EventManager::EventManager(std::vector<Shape*>&)
{
}


EventManager::~EventManager()
{
}

bool EventManager::AABBAABBCollision(Shape* A, Shape* B)
{
	if (abs(A->GetPosition().x - B->GetPosition().x) > (A->GetPosition().x + B->GetPosition().x))
	{
		return false;
	}
	if (abs(A->GetPosition().y - B->GetPosition().y) > (A->GetPosition().y + B->GetPosition().y))
	{
		return false;
	}
	else
	{
		return true;
		A->OnCollide(B->GetType());
		B->OnCollide(A->GetType());
	}
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

bool EventManager::TriangleAABBCollision(glm::vec2 tP, glm::vec2 lP, glm::vec2 rP, Shape * S)
{
	return false; // TODO complete this -PC
}

bool EventManager::CircleTriangleCollision(Shape* C, Shape* T, glm::vec2& p) // section 5.2.7 RTCD, -PC
{
	Triangle* Tri = dynamic_cast<Triangle*>(T); // this will not fail as the type has been checked by Enum -PC
	if (Tri != nullptr) // just in case but should be impossible due to enum governance -PC
	{
		
		p = ClosestPtPointTriangle(C, Tri->GetTopPoint(),Tri->GetLeftPoint(), Tri->GetRightPoint()); 
		// Circle and triangle intersect if the (squared) distance from circle
		// centre to point p is less than the (squared) circle radius
		glm::vec2 v = p - C->GetPosition();
		if (glm::dot(v, v) <= C->GetDistanceMetric() * C->GetDistanceMetric())
		{
			return true;
			C->OnCollide(T->GetType());
			T->OnCollide(C->GetType());
		}
		else
		{
			return false;
		}
	}
}

glm::vec2 EventManager::ClosestPtPointTriangle(Shape* C, glm::vec2 tP, glm::vec2 lP, glm::vec2 rP) // this was a rough one to write, RTCD section 5.1.5 -PC
{
	// Check if P in vertex region outside A
	glm::vec2 tPlP = lP - tP;
	glm::vec2 tPrP = rP - tP;
	glm::vec2 tPcent = C->GetPosition() - tP;

	float d1 = glm::dot(tPlP, tPcent);
	float d2 = glm::dot(tPrP, tPcent);
	if (d1 <= 0.0f && d2 <= 0.0f)
	{
		return tP; // barycentric coordinates (1,0,0)
	}

	// Check if P in vertex region outside B
	glm::vec2 lPcent = C->GetPosition() - lP;
	float d3 = glm::dot(tPlP, lPcent);
	float d4 = glm::dot(tPrP, lPcent);
	if (d3 >= 0.0f && d4 <= d3)
	{
		return lP; // barycentric coordinates (0,1,0)
	}

	// Check if P in edge region of AB, if so return projection of P onto AB
	float vrP = d1 * d4 - d3 * d2;
	if (vrP <= 0.0f && d1 >= 0.0f && d3 <= 0.0f)
	{
		float v = d1 / (d1 - d3);
		return tP + v * tPlP;
	}

	// Check if P in vertex region outside C
	glm::vec2 crP = C->GetPosition() - rP;
	float d5 = glm::dot(tPlP, crP);
	float d6 = glm::dot(tPrP, crP);
	if (d6 >= 0.0f && d5 <= d6)
	{
		return rP; // barycentric coordinates (0,0,1)
	}

	// Check if P in edge region of AC, if so return projection of P onto AC
	float vlP = d5 * d2 - d1 * d6;
	if (vlP <= 0.0f && d2 >= 0.0f && d6 <= 0.0f)
	{
		float w = d2 / (d2 - d6);
		return tP + w * tPrP; // barycentric coordinates (1-w,0,w)
	}

	// Check if P in edge region of BC, if so return projection of P onto BC
	float vtP = d3 * d6 - d5 * d4;
	if (vtP <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f)
	{
		float w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
		return lP + w * (rP - lP); // barycentric coordinates (0,1-w,w)
	}

	// P inside face region. Compute Q through its barycentric coordinates (u,v,w)
	float denom = 1.0f / (vtP + vlP + vrP);
	float v = vlP * denom;
	float w = vrP * denom;
	return tP + tPlP * v + tPrP * w; // = u*tP + v*lP + w*rP, u = vtP * denom = 1.0f - v - w
}

void EventManager::CheckCollisions(Shape* shape1, Shape* shape2)
{
	if (shape1->GetType() == 0 && shape2->GetType() == 0)// C-C -PC
	{
		CircleCircleCollision(shape1, shape2);
	}
	else if (shape1->GetType() == 0 && shape2->GetType() == 2)// C-S -PC
	{
		CircleAABBCollision(shape1, shape2);
	}
	else if (shape1->GetType() == 0 && shape2->GetType() == 1)// C-T -PC
	{
		glm::vec2 closestPoint;
		CircleTriangleCollision(shape1, shape2, closestPoint);
	}
	else if (shape1->GetType() == 2 && shape2->GetType() == 2)// S-S -PC
	{
		AABBAABBCollision(shape1, shape2);
	}
	else if (shape1->GetType() == 1 && shape2->GetType() == 1)// T-T -PC
	{
	}
	else if (shape1->GetType() == 2 && shape2->GetType() == 1)// S-T -PC
	{
	}
}

bool EventManager::CircleAABBCollision(Shape* C, Shape* S) // inefficient for C-C -PC
{
	glm::vec2 closestPoint;
	ClosestPtPointAABB(C->GetPosition(), *S, closestPoint);
	if (distance(C->GetPosition(), closestPoint) <= C->GetDistanceMetric())
	{
		return true;
		C->OnCollide(S->GetType());
		S->OnCollide(C->GetType());
	}
	return false;
}

void EventManager::ClosestPtPointAABB(glm::vec2 const &  P, const Shape& b, glm::vec2 & q) // section 5.1.3 of RTCD
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
