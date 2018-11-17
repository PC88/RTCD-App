#pragma once
#include "PhysicsComp.h"
#include "glm/vec2.hpp"
#include "Transform.h"

class SquarePhysicsComp :
	protected PhysicsComp
{
public:
	SquarePhysicsComp(std::shared_ptr<Transform> ShapeTransform);

	virtual ~SquarePhysicsComp();

	void Update(std::chrono::milliseconds ElapsedDeltaTime) override;

	void Move(glm::vec2 translation) override;

	void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime) override;

	glm::vec2 GetPosition() override; // position and direction are here just for debugging, 
	                                  // they should have the same value as shape transform -PC
	glm::vec2 GetDirection() override;

private:

	std::shared_ptr<Transform> ShapeTransform;
	vec2 velocity;
	vec2 acceleration;
	vec3 colour;
	//Transform transform; TODO
};

