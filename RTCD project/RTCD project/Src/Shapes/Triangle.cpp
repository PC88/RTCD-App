// UMARS contribution, with edits from PC.
// CHANGES -PC: ElapsedGameTime to ElapsedDeltaTime, Destructor added
// Glut include removed this fools the compiler in to using a glut Macro for "Circle" instead of class circle
// forward decelerations Added to save compile time, includes removed for all forward declarations
// gl functions removed should be in graph comps
// using namespace added to .cpp as well as .h for consistency
// graphic and physics comp declarations and respective implementation added
// rand seed added for more "random" randomness, aye.. that one...
#include "Triangle.h"
#include "TriangleGraphComp.h"
#include "TrianglePhysicsComp.h"
#include "Transform.h"
#include <memory>


Triangle::Triangle(float& hw, glm::vec2& vel, glm::vec2& acc)
	: halfwidth(hw), velocity(vel), acceleration(acc),
	topPoint(ShapeTransform->getPosition().x, ShapeTransform->getPosition().y - halfwidth),
	leftPoint(ShapeTransform->getPosition().x - halfwidth, ShapeTransform->getPosition().y + halfwidth), // this is defined because of philosophy of the project, it does ,quite literally, do nothing -PC
	rightPoint(ShapeTransform->getPosition().x + halfwidth, ShapeTransform->getPosition().y - halfwidth)
{
	float initX = std::rand() % (1000 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (1000 - 0 + 1) + 0;

	Creator = TypeOfCreatedObject::triangle; // define meta data -PC

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	ShapeTransform->Translate(position);
	graphicComp = std::make_unique<TriangleGraphComp>(ShapeTransform, halfwidth, velocity, acceleration);
	physicsComp = std::make_unique<TrianglePhysicsComp>(ShapeTransform, halfwidth, velocity, acceleration);
	inUse = true;
}

Triangle::~Triangle()
{
}

void Triangle::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	physicsComp->Update(ElapsedDeltaTime, width, height);
}

void Triangle::OnCollide(int type)
{
	graphicComp->OnCollideGraphics(type); // inform comp for reaction -PC
	glm::vec2 currentPosition = ShapeTransform->getPosition();
	glm::vec2 negativePosition(currentPosition.x, currentPosition.y); // change transform as of reaction -PC
	ShapeTransform->Translate(negativePosition);
}

void Triangle::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	graphicComp->Render(ElapsedDeltaTime, width, height);
}

vec2 Triangle::GetDirection() const
{
	return ShapeTransform->getUpDir();
}

vec2 Triangle::GetPosition() const
{
	return ShapeTransform->getPosition();
}

float Triangle::GetDistanceMetric() const
{
	float CSquared = (halfwidth * halfwidth) + (halfwidth * halfwidth);
	float C = glm::sqrt(CSquared);
	return C;
}


int Triangle::GetType()
{
	switch (Creator) // why is this undefined -PC
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


bool Triangle::InUse()
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

float Triangle::GetHalfwidth()
{
	return halfwidth;
}

glm::vec2 Triangle::GetTopPoint()
{
	return topPoint;
}

glm::vec2 Triangle::GetLeftPoint()
{
	return leftPoint;
}

glm::vec2 Triangle::GetRightPoint()
{
	return rightPoint;
}
