#pragma once
#include <vector>
#include "Shape.h"
#include "glm/glm.hpp"
class Shape;
class EventManager
{
public:

	bool CircleAABBCollision(Shape* C, Shape* S);
	void ClosestPtPointAABB(glm::vec2 const & P, const Shape& b, glm::vec2& q);
	bool AABBAABBCollision(Shape* A, Shape* B);
	bool CircleCircleCollision(Shape* S1, Shape* S2);
	bool TriangleAABBCollision(glm::vec2 tP, glm::vec2 lP, glm::vec2 rP, Shape* S);
	// TODO one more to add -PC T-T

	bool CircleTriangleCollision(Shape* C, Shape* T, glm::vec2& p);
	glm::vec2 ClosestPtPointTriangle(Shape* C, glm::vec2 tP, glm::vec2 lP, glm::vec2 rP);

	void CheckCollisions(Shape* shape1, Shape* shape2);

	EventManager(std::vector<Shape*>&); // this is gonna get wild -PC
	virtual ~EventManager();

private:
	std::vector<Shape*> activePool;
};

