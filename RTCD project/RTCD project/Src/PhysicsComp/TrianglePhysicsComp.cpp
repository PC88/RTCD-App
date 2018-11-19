#include "TrianglePhysicsComp.h"



TrianglePhysicsComp::TrianglePhysicsComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc)
	:ShapeTransform(ShapeTransform), pointOne(p1), pointTwo(p2), pointThree(p3), velocity(vel), acceleration(acc)
{
}


TrianglePhysicsComp::~TrianglePhysicsComp()
{
}
