#include "SquarePhysicsComp.h"
#include "Square.h"



SquarePhysicsComp::SquarePhysicsComp(std::shared_ptr<Transform> ShapeTransform, vec2& vel, vec2& acc, float& w, float& h)
	: ShapeTransform(ShapeTransform), acceleration(acc), velocity(vel), width(w), height(h)
{
}


SquarePhysicsComp::~SquarePhysicsComp()
{
}

void SquarePhysicsComp::Update(std::chrono::milliseconds ElapsedDeltaTime)
{
	TCVelocityVerletSolver(ElapsedDeltaTime);
}

void SquarePhysicsComp::Move(glm::vec2 translation)
{
	ShapeTransform->Translate(translation); // TODO transform may not be the same as the squares;
}

void SquarePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime)
{
	Move(ElapsedDeltaTime * velocity + 0.5f * ElapsedDeltaTime * ElapsedDeltaTime * acceleration);
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime * acceleration; // cast/the types here -PC
	velocity = velInBetween + 0.5f * acceleration;
}

glm::vec2 SquarePhysicsComp::GetPosition()
{
	return ShapeTransform->getPosition(); // TODO fix this transform - PC
}

glm::vec2 SquarePhysicsComp::GetDirection()
{
	return glm::vec2(); // TODO fix this transform - PC
}
