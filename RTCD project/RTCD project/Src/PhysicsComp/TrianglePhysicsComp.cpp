#include "TrianglePhysicsComp.h"



TrianglePhysicsComp::TrianglePhysicsComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc)
	:ShapeTransform(ShapeTransform), pointOne(p1), pointTwo(p2), pointThree(p3), velocity(vel), acceleration(acc)
{
}


TrianglePhysicsComp::~TrianglePhysicsComp()
{
}

void TrianglePhysicsComp::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	TCVelocityVerletSolver(ElapsedDeltaTime, width, height);
}

void TrianglePhysicsComp::Move(glm::vec2 translation)
{
	ShapeTransform->Translate(translation);
}

void TrianglePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(ElapsedDeltaTime * velocity + 0.5f * ElapsedDeltaTime * ElapsedDeltaTime * acceleration);
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime * acceleration; // cast/the types here, std::milli has no converttype ASK -PC
	velocity = velInBetween + 0.5f * acceleration; // add in boundary checks here TODO -PC
}

glm::vec2 TrianglePhysicsComp::GetPosition() const
{
	return ShapeTransform->getPosition();
}

glm::vec2 TrianglePhysicsComp::GetDirection()
{
	return ShapeTransform->getUpDir();
}
