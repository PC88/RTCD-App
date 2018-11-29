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

inline glm::vec2 operator*(const glm::vec2& v, const long long& m) // needs to be inline or multiple definitions in translation unit -PC
{
	return glm::vec2(v.x * m, v.y * m);
}

void CirclePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(velocity * ElapsedDeltaTime.count() + 0.5f * ElapsedDeltaTime.count() * ElapsedDeltaTime.count() * acceleration); 
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime.count() * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
	//Boundary checks -PC - these are accurate given our ref systems -PC

	if (ShapeTransform->getPosition().x + this->radius >= width) // left bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseX();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().x - this->radius <= width) // right bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseX();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().y - this->radius <= height) // top bound -PC - assuming flipped axis
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseY();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().y + this->radius >= height) // bottom bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseY();
		ShapeTransform->Translate(reversedPos);
	}
}

glm::vec2 CirclePhysicsComp::GetPosition() const
{
	return ShapeTransform->getPosition();
}

glm::vec2 CirclePhysicsComp::GetDirection() const
{
	return ShapeTransform->getUpDir();
}

glm::vec2 CirclePhysicsComp::ReverseX()
{
	float x;
	float y;
	glm::vec2 reversedXVec;

	x = ShapeTransform->getPosition().x;
	y = ShapeTransform->getPosition().y;
	x = x * -1;

	reversedXVec = glm::vec2(x, y);
	return reversedXVec;
}

glm::vec2 CirclePhysicsComp::ReverseY()
{
	float x;
	float y;
	glm::vec2 reversedYVec;

	x = ShapeTransform->getPosition().x;
	y = ShapeTransform->getPosition().y;
	y = y * -1;

	reversedYVec = glm::vec2(x, y);
	return reversedYVec;
}

