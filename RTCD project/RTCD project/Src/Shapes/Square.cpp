#include "Square.h"
#include "Shape.h"
#include "SquareGraphComp.h"
#include "Transform.h"
#include "SquarePhysicsComp.h"
#include <ctime>



Square::Square(vec2& vel, vec2& acc, float& w, float& h)
	: graphicComp(), physicsComp(), acceleration(acc), velocity(vel), width(w), height(h) 
{
	float initX = std::rand() % (640 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (450 - 0 + 1) + 0;

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	// set Shape transform to position initially -PC
	graphicComp = std::make_unique<SquareGraphComp>(ShapeTransform, velocity, acceleration, width, height); // set up graphics and physics comps -PC
	physicsComp = std::make_unique<SquarePhysicsComp>(ShapeTransform, velocity, acceleration, width, height);

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
