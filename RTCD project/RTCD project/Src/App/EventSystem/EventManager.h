#pragma once
#include <vector>
#include "Shape.h"
#include "glm/vec2.hpp"
#include "glm/glm.hpp"
class Shape;
class EventManager
{
public:

	bool CircleAABBCollision(const Shape& c1, const Shape& b);
	void ClosestPtPointAABB(glm::vec2 const & P, const Shape& b, glm::vec2& q);
	bool AABBAABBCollision(const Shape& A, const Shape& B);
	bool CircleCircleCollision(Shape* S1, Shape* S2);

	void CheckCollisions(Shape* shape1, Shape* shape2);

	EventManager(std::vector<Shape*>&); // this is gonna get wild -PC
	virtual ~EventManager();

private:
	std::vector<Shape*> activePool;
};

