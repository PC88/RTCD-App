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


Triangle::Triangle(glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc)
	: graphicComp(), physicsComp(), pointOne(p1), pointTwo(p2), pointThree(p3), velocity(vel), acceleration(acc)
{
	float initX = std::rand() % (640 - 0 + 1) + 0; // make initial position between screen limits does hard code at the moment -PC
	float initY = std::rand() % (450 - 0 + 1) + 0;

	ShapeTransform = std::make_shared<Transform>();
	position = vec2(initX, initY); // init to random -PC // this actually has to be set in the transform -PC
	// set Shape transform to position initially -PC
	graphicComp = std::make_unique<TriangleGraphComp>(ShapeTransform, pointOne, pointTwo, pointThree);
	physicsComp = std::make_unique<TrianglePhysicsComp>(ShapeTransform, pointOne, pointTwo, pointThree);
	inUse = false;
}

Triangle::~Triangle()
{
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
	return ShapeTransform->getUpDir();
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
