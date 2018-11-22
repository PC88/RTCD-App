#pragma once
#include "PhysicsComp.h"
#include <memory>
#include <chrono>
#include "glm\vec2.hpp"
#include "Transform.h"

class TrianglePhysicsComp :
	public PhysicsComp
{
public:
	TrianglePhysicsComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc);
	virtual ~TrianglePhysicsComp();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Move(glm::vec2 translation);

	void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	glm::vec2 GetPosition() const; // position and direction are here just for debugging, 
									  // they should have the same value as shape transform -PC
	glm::vec2 GetDirection() const;

private:

	glm::vec2 pointOne;
	glm::vec2 pointTwo;
	glm::vec2 pointThree;

	glm::vec2 velocity;
	glm::vec2 acceleration;

	std::shared_ptr<Transform> ShapeTransform;

};


