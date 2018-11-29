#include "Square.h"
#include "Shape.h"
#include "SquareGraphComp.h"
#include "Transform.h"
#include "SquarePhysicsComp.h"
#include <ctime>



Square::Square(vec2& vel, vec2& acc, float& hw)
	: acceleration(acc), velocity(vel), halfwidth(hw) // delete graph and physic comps and change transform VIA TRANSLATE IN MOVE FROM LABS
{
	float initX = std::rand() % (1000 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (1000 - 0 + 1) + 0;

	Creator = TypeOfCreatedObject::square; // define meta data -PC

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	ShapeTransform->Translate(position);// set Shape transform to position initially -PC - TODO copy this to the other shape classes -PC
	graphicComp = std::make_unique<SquareGraphComp>(ShapeTransform, velocity, acceleration, halfwidth); // set up graphics and physics comps -PC
	physicsComp = std::make_unique<SquarePhysicsComp>(ShapeTransform, velocity, acceleration, halfwidth);

	inUse = true;
}


Square::~Square()
{
}

void Square::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	physicsComp->Update(ElapsedDeltaTime, width, height);
}

void Square::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	graphicComp->Render(ElapsedDeltaTime, width, height);
}

void Square::OnCollide(int type)
{
	graphicComp->OnCollideGraphics(type); // inform comp for reaction -PC
	glm::vec2 currentPosition = ShapeTransform->getPosition();
	glm::vec2 negativePosition(currentPosition.x, currentPosition.y); // change transform as of reaction -PC
	ShapeTransform->Translate(negativePosition);
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


int Square::GetType()
{
	switch (Creator)
	{
		int typenum;
	case TypeOfCreatedObject::circle:
		typenum = 0;
		return typenum;
		// gl code for color here
		break;
	case TypeOfCreatedObject::triangle:
		typenum = 1;
		return typenum;
		// gl code for color here
		break;
	case TypeOfCreatedObject::square:
		typenum = 2;
		return typenum;
		// gl code for color here
		break;
	}
}

float Square::GetDistanceMetric() const
{
	float CSquared = (halfwidth * halfwidth) + (halfwidth * halfwidth);
	float C = glm::sqrt(CSquared);
	return C;
}

float Square::GetHalfwidth()
{
	return halfwidth;
}

glm::vec2 Square::GetDirection() const
{
	return ShapeTransform->getLeftDir();// not correct I believe - PC
}

glm::vec2 Square::GetPosition() const
{
	return ShapeTransform->getPosition();
}
