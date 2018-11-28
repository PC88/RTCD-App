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
	TrianglePhysicsComp(std::shared_ptr<Transform> ShapeTransform, float& hw, glm::vec2& vel, glm::vec2& acc);
	virtual ~TrianglePhysicsComp();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Move(glm::vec2 translation);

	void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	glm::vec2 GetPosition() const; // position and direction are here just for debugging, 
									  // they should have the same value as shape transform -PC
	glm::vec2 GetDirection() const;

	glm::vec2 ReverseX();

	glm::vec2 ReverseY();
	
private:
	float halfwidth;
	glm::vec2 topPoint;
	glm::vec2 leftPoint;
	glm::vec2 rightPoint;

	glm::vec2 velocity;
	glm::vec2 acceleration;

	std::shared_ptr<Transform> ShapeTransform;

};


