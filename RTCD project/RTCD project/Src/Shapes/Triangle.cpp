// UMARS contribution, with edits from PC.
// CHANGES -PC: ElapsedGameTime to ElapsedDeltaTime, Destructor added
// Glut include removed this fools the compiler in to using a glut Macro for "Circle" instead of class circle
// forward decelerations Added to save compile time, includes removed for all forward declarations
// gl functions removed should be in graph comps
// using namespace added to .cpp as well as .h for consistency
// graphic and physics comp declarations and respective implementation added
// rand seed added for more "random" randomness, aye.. that one...
#include "Triangle.h"
#include "TrangleGraphComp.h"
#include "TrianglePhysicsComp"

Triangle::~Triangle()
{
}

Triangle::Triangle(float ix, float iy)
	: graphicComp(), physicsComp()
{
	ShapeTransform = std::make_shared<Transform>();
	this->setPosition(glm::vec2(2, 2));
	this->setDirection(glm::vec2(2, 2));
	graphicComp = std::make_unique<TriangleGraphComp>(ShapeTransform);
	physicsComp = std::make_unique<TrianglePhysicsComp>(ShapeTransform);
	inUse = false;
}

void Triangle::Update(std::chrono::milliseconds ElapsedDeltaTime)
{
	physicsComp->Update(ElapsedDeltaTime);
}

void Triangle::Render(std::chrono::milliseconds ElapsedDeltaTime)
{

	graphicComp->Render(ElapsedDeltaTime);

	/*glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 200, y);
	glVertex2f(x + 200 * 0.5, y + 200);
	glEnd();*/ // I added in the drawing code and commented it out but i dont know if i done it right

}

vec2 Triangle::GetDirection()
{
	return ShapeTransform->getDirection();
}

vec2 Triangle::GetPosition()
{
	return ShapeTransform->getPosition();
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
