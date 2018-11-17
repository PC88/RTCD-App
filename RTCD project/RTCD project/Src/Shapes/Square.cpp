#include "Square.h"
#include "Shape.h"
#include "SquareGraphComp.h"
#include "Transform.h"
#include "SquarePhysicsComp.h"



Square::Square()
	: graphicComp(), physicsComp()
{
	ShapeTransform = std::make_shared<Transform>();
	//TODO: set position to random within screen when constructed
	graphicComp = std::make_unique<SquareGraphComp>(ShapeTransform); // set up graphics and physics comps - PC
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
