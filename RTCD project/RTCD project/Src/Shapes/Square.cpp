#include "Square.h"
#include "Shape.h"
#include "SquareGraphComp.h"
#include "Transform.h"
#include "SquarePhysicsComp.h"



Square::Square()
	: graphicComp(), physicsComp()
{
	ShapeTransform = std::make_shared<Transform>();
	this->SetPositon(glm::vec2(2, 2));
	this->SetDirection(glm::vec2(2, 2)); // this will be changed to transform Matrix stuff - PC
	graphicComp = std::make_unique<SquareGraphComp>(ShapeTransform); // ASK ABOUT THIS potentially right for passing transform to components -PC
	physicsComp = std::make_unique<SquarePhysicsComp>(ShapeTransform);

	inUse = false;
}


Square::~Square()
{
}

void Square::Update(std::chrono::milliseconds ElapsedDeltaTime)
{
	physicsComp->Update(ElapsedDeltaTime);
}

void Square::Render(std::chrono::milliseconds ElapsedDeltaTime)
{
	graphicComp->Render(ElapsedDeltaTime);
}


bool Square::InUse()
{
	if (!inUse)
	{
		return false;
	}
	else
	{ 
		return true;
	}
}

glm::vec2 Square::GetDirection()
{
	return ShapeTransform->getLeftDir();// not correct I believe - PC
}

glm::vec2 Square::GetPoistion()
{
	return ShapeTransform->getPosition();
}

glm::vec2 Square::SetPositon(glm::vec2 NewPosition)
{
	return NewPosition;
}

glm::vec2 Square::SetDirection(glm::vec2 NewDirection)
{
	return NewDirection;
}
;
