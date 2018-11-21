#include "CirclePhysicsComp.h"


CirclePhysicsComp::CirclePhysicsComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc)
	:ShapeTransform(ShapeTransform), radius(r), velocity(vel), acceleration(acc)
{
}


CirclePhysicsComp::~CirclePhysicsComp()
{
}

void CirclePhysicsComp::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	TCVelocityVerletSolver(ElapsedDeltaTime, width, height);
}

void CirclePhysicsComp::Move(glm::vec2 translation)
{
	ShapeTransform->Translate(translation);
}

void CirclePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(ElapsedDeltaTime.count() * velocity + 0.5f * ElapsedDeltaTime * ElapsedDeltaTime * acceleration); // can fix
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime * acceleration; // cast/the types here, std::milli has no converttype ASK -PC
	velocity = velInBetween + 0.5f * acceleration; // add in boundary checks here TODO -PC
}

glm::vec2 CirclePhysicsComp::GetPosition() const
{
	return ShapeTransform->getPosition();
}

glm::vec2 CirclePhysicsComp::GetDirection() const
{
	return ShapeTransform->getUpDir();
}
