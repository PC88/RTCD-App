#include "SquarePhysicsComp.h"
#include "Square.h"



SquarePhysicsComp::SquarePhysicsComp(std::shared_ptr<Transform> ShapeTransform, vec2& vel, vec2& acc, float& hw)
	: ShapeTransform(ShapeTransform), acceleration(acc), velocity(vel), m_halfwidth(hw),
	topLeft(ShapeTransform->getPosition().x - hw, ShapeTransform->getPosition().y - hw),
	topRight(ShapeTransform->getPosition().x + hw, ShapeTransform->getPosition().y - hw),
	bottomLeft(ShapeTransform->getPosition().x - hw, ShapeTransform->getPosition().y + hw), // defined for philosophy not actually implemented in a project of this scale -PC
	bottomRight(ShapeTransform->getPosition().x + hw, ShapeTransform->getPosition().y + hw)
{
}


SquarePhysicsComp::~SquarePhysicsComp()
{
}

void SquarePhysicsComp::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	TCVelocityVerletSolver(ElapsedDeltaTime, width, height); // TODO use width height here -PC
}

void SquarePhysicsComp::Move(glm::vec2 translation)
{
	ShapeTransform->Translate(translation); 
}

glm::vec2 operator*(const glm::vec2& v, const long long& m) // overloaded off for the accuracy of the move function/timestep -PC
{
	return glm::vec2(v.x * m, v.y * m);
}

void SquarePhysicsComp::TCVelocityVerletSolver(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	Move(velocity * ElapsedDeltaTime.count() + 0.5f * ElapsedDeltaTime.count() * ElapsedDeltaTime.count() * acceleration); // above overload used
	vec2 velInBetween = velocity + 0.5f * ElapsedDeltaTime.count() * acceleration; 
	velocity = velInBetween + 0.5f * acceleration; 

	if (ShapeTransform->getPosition().x + this->m_halfwidth >= width) // left bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseX();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().x - this->m_halfwidth <= width) // right bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseX();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().y - this->m_halfwidth <= height) // top bound -PC - assuming flipped axis
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseY();
		ShapeTransform->Translate(reversedPos);
	}
	if (ShapeTransform->getPosition().y + this->m_halfwidth >= height) // bottom bound -PC
	{
		glm::vec2 reversedPos;
		reversedPos = ReverseY();
		ShapeTransform->Translate(reversedPos);
	}
}

glm::vec2 SquarePhysicsComp::GetPosition() const
{
	return ShapeTransform->getPosition(); 
}

glm::vec2 SquarePhysicsComp::GetDirection() const
{
	return ShapeTransform->getUpDir(); 
}

glm::vec2 SquarePhysicsComp::ReverseX()
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

glm::vec2 SquarePhysicsComp::ReverseY()
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
