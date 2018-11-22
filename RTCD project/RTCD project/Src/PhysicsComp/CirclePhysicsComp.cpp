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

glm::vec2 operator*(const glm::vec2& v, const long long& m) // overloaded off for the accuracy of the move function/timestep
{
	return glm::vec2(v.x * m, v.y * m);
}

void CirclePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(velocity * ElapsedDeltaTime.count() + 0.5f * ElapsedDeltaTime.count() * ElapsedDeltaTime.count() * acceleration); // can fix by overloading operators
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime.count() * acceleration; 
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

