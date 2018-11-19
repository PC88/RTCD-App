#include "Square.h"
#include "Shape.h"
#include "SquareGraphComp.h"
#include "Transform.h"
#include "SquarePhysicsComp.h"
#include <ctime>



Square::Square(vec2& vel, vec2& acc, float& w, float& h)
	: acceleration(acc), velocity(vel), width(w), height(h) // delete graph and physic comps and change transform VIA TRANSLATE IN MOVE FROM LABS
{
	float initX = std::rand() % (640 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (450 - 0 + 1) + 0;

	Creator = TypeOfCreatedObject::Square; // define meta data -PC

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	ShapeTransform->Translate(position);// set Shape transform to position initially -PC - TODO copy this to the other shape classes -PC
	graphicComp = std::make_unique<SquareGraphComp>(ShapeTransform, velocity, acceleration, width, height); // set up graphics and physics comps -PC
	physicsComp = std::make_unique<SquarePhysicsComp>(ShapeTransform, velocity, acceleration, width, height);

	inUse = false;
}


Square::~Square()
{
}

void Square::Update(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	physicsComp->Update(ElapsedDeltaTime, width, height);
}

void Square::Render(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	graphicComp->Render(ElapsedDeltaTime, width, height);
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
	case TypeOfCreatedObject::Circle:
		typenum = 0;
		return typenum;
		// gl code for color here
		break;
	case TypeOfCreatedObject::Triangle:
		typenum = 1;
		return typenum;
		// gl code for color here
		break;
	case TypeOfCreatedObject::Square:
		typenum = 2;
		return typenum;
		// gl code for color here
		break;
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
