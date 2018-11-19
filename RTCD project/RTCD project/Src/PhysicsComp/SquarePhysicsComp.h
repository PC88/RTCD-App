#pragma once
#include "PhysicsComp.h"
#include "glm/vec2.hpp"
#include "Transform.h"
#include <memory>
#include "glut/include/glut.h" // ASK this is getting to be a big issue -PC

class SquarePhysicsComp :
	protected PhysicsComp
{
public:
	SquarePhysicsComp(std::shared_ptr<Transform> ShapeTransform, vec2& vel, vec2& acc, float& w, float& h);

	virtual ~SquarePhysicsComp();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) ;

	void Move(glm::vec2 translation);

	void TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	glm::vec2 GetPosition() const; // position and direction are here just for debugging, 
	                                  // they should have the same value as shape transform -PC
	glm::vec2 GetDirection();

private:

	std::shared_ptr<Transform> ShapeTransform;
	vec2 velocity;
	vec2 acceleration;
	float m_width;
	float m_height;
};

