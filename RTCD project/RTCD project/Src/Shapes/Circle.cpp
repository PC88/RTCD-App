// UMARS contribution, with edits from PC.
// CHANGES -PC: ElapsedGameTime to ElapsedDeltaTime, Destructor added
// Glut include removed this fools the compiler in to using a glut Macro for "Circle" instead of class circle
// forward decelerations Added to save compile time, includes removed for all forward declarations
// gl functions removed should be in graph comps, linked with Graphic and Physics comps respectively
// using namespace added to .cpp as well as .h for consistency, as well as removed some C# usage of . operators.
// params added to Render signature to take in to account the ElapsedDeltaTime
// rand seed added for more "random" randomness, aye.. that one...
// constructor changes to incorporate pos, vel, acc, and types changed to vec2`s
// #includes added in .cpp as with the forward declarations
#include "Circle.h"
#include <glm\glm.hpp>
#include <chrono>
#include "Transform.h"
#include "CircleGraphComp.h"
#include "CirclePhysicsComp.h"
#include <iostream>

using namespace glm;

Circle::Circle(float& r, vec2& vel, vec2& acc)
	: velocity(vel), acceleration(acc)
{
	float initX = std::rand() % (640 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (450 - 0 + 1) + 0;

	Creator = TypeOfCreatedObject::circle; // define meta data -PC

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	ShapeTransform->Translate(position);

	graphicComp = std::make_unique<CircleGraphComp>(ShapeTransform, radius, velocity, acceleration);
	physicsComp = std::make_unique<CirclePhysicsComp>(ShapeTransform,  radius, velocity, acceleration);
	inUse = false;
}

Circle::~Circle()
{
}

void Circle::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	physicsComp->Update(ElapsedDeltaTime, width, height);
}


void Circle::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	graphicComp->Render(ElapsedDeltaTime,  width, height);

}
void Circle::OnCollide(int type)
{
	graphicComp->OnCollideGraphics(type); // inform comp for reaction -PC
	glm::vec2 currentPosition = ShapeTransform->getPosition();
	glm::vec2 negativePosition(currentPosition.x, currentPosition.y); // change transform as of reaction -PC
	ShapeTransform->Translate(negativePosition);
}

bool Circle::InUse()

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
int Circle::GetType()
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

vec2 Circle::GetDirection()
{
	return ShapeTransform->getLeftDir();
}

vec2 Circle::GetPosition()
{
	return ShapeTransform->getPosition();
}
