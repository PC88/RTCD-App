#include "SquarePhysicsComp.h"
#include "Square.h"



SquarePhysicsComp::SquarePhysicsComp(std::shared_ptr<Transform> ShapeTransform, vec2& vel, vec2& acc, float& w, float& h)
	: ShapeTransform(ShapeTransform), acceleration(acc), velocity(vel), m_width(w), m_height(h)
{
}


SquarePhysicsComp::~SquarePhysicsComp()
{
}

void SquarePhysicsComp::Update(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	TCVelocityVerletSolver(ElapsedDeltaTime, width, height); // TODO use width height here -PC
}

void SquarePhysicsComp::Move(glm::vec2 translation)
{
	ShapeTransform->Translate(translation); // TODO transform may not be the same as the squares -PC
}

void SquarePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	Move(ElapsedDeltaTime * velocity + 0.5f * ElapsedDeltaTime * ElapsedDeltaTime * acceleration);
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime * acceleration; // cast/the types here, std::milli has no converttype ASK -PC
	velocity = velInBetween + 0.5f * acceleration; // add in boundary checks here TODO -PC
}

glm::vec2 SquarePhysicsComp::GetPosition()
{
	return ShapeTransform->getPosition(); // TODO fix this transform - PC
}

glm::vec2 SquarePhysicsComp::GetDirection()
{
	return ShapeTransform->getUpDir(); // TODO fix this transform - PC
}
