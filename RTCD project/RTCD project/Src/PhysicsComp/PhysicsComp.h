#pragma once
#include <chrono>
class Transform;

class PhysicsComp
{
public:
	PhysicsComp(Transform ShapeTransform);
	virtual ~PhysicsComp();

	virtual void Update(std::chrono::milliseconds ElapsedDeltaTime) = 0;

	virtual void Move(glm::vec2 translation) = 0;

	virtual void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime) = 0;

	virtual glm::vec2 GetPosition() = 0; // position and direction are here just for debugging, they should have 
	                                     // the same value as shape transform -PC
	virtual glm::vec2 GetDirection() = 0; 
};

