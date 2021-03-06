#pragma once
#include "PhysicsComp.h"

class CirclePhysicsComp :
	public PhysicsComp
{
public:
	CirclePhysicsComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc);
	virtual ~CirclePhysicsComp();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Move(glm::vec2 translation);

	void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	glm::vec2 GetPosition() const; // position and direction are here just for debugging, 
									  // they should have the same value as shape transform -PC
	glm::vec2 GetDirection() const;

	glm::vec2 ReverseX();

	glm::vec2 ReverseY();
private:

	std::shared_ptr<Transform> ShapeTransform;
	float radius;
	glm::vec2 velocity;
	glm::vec2 acceleration;


};

