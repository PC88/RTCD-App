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

glm::vec2 operator*(const glm::vec2& v, const long long& m) // overloaded off for the accuracy of the move function/timestep -PC
{
	return glm::vec2(v.x * m, v.y * m);
}

void TrianglePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(velocity * ElapsedDeltaTime.count()  + 0.5f * ElapsedDeltaTime.count() * ElapsedDeltaTime.count() * acceleration);
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime.count() * acceleration;
	velocity = velInBetween + 0.5f * acceleration; // add in boundary checks here TODO -PC
}

glm::vec2 TrianglePhysicsComp::GetPosition() const
{
	return ShapeTransform->getPosition();
}

glm::vec2 TrianglePhysicsComp::GetDirection() const
{
	return ShapeTransform->getUpDir();
}
