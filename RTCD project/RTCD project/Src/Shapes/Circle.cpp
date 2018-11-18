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
	: graphicComp(), physicsComp(), velocity(vel), acceleration(acc)
{
	float initX = std::rand() % (640 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (450 - 0 + 1) + 0;

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	// set Shape transform to position initially -PC

	graphicComp = std::make_unique<CircleGraphComp>(ShapeTransform, radius, velocity, acceleration);
	physicsComp = std::make_unique<CirclePhysicsComp>(ShapeTransform,  radius, velocity, acceleration);
	inUse = false;
}

Circle::~Circle()
{
}

void Circle::Update(std::chrono::milliseconds ElapsedDeltaTime)
{
	physicsComp->Update(ElapsedDeltaTime);
}


void Circle::Render(std::chrono::milliseconds ElapsedDeltaTime)
{
	graphicComp->Render(ElapsedDeltaTime);

	/*glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 30; i++)
	{
		float TWOPI = 3.1415926f * 2;

		float cx = r * cosf(TWOPI);
		float cy = r * sinf(TWOPI);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();*/

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
vec2 Circle::GetDirection()
{
	return ShapeTransform->getLeftDir();
}

vec2 Circle::GetPoistion()
{
	return ShapeTransform->getPosition();
}
