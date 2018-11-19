#include "TriangleGraphComp.h"
#include "SingletonGraphStates.h"
#include "Transform.h"

TriangleGraphComp::TriangleGraphComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc)
	:ShapeTransform(ShapeTransform), pointOne(p1), pointTwo(p2), pointThree(p3), velocity(vel), acceleration(acc)
{
	LastHtObject = GraphicsComp::Nothing; // init to default color -PC
}

TriangleGraphComp::~TriangleGraphComp()
{
}

void TriangleGraphComp::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) // COPY PASTE OF SQUARE GRAPHCOMP
{
	position = ShapeTransform->getPosition();
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)


	glBegin(GL_TRIANGLES);

	//NOTE: glColor3f(color.r, color.g, color.b) // this is basically whats being done here to avoid copying, and to use the flyweight pattern -PC
	// it may be seen as somewhat "unimpactfull" in this project as its a ref to 9 simple color outcomes as opposed to actual large objects
	// however this is there so show the utilization of what an engine COULD do... if this was not GLUT, and I had more time/experience for example I would have a renderer which had information obound to
	// uniforms like modern OpenGL does, or even further a Material like a REAL game engine, but the principles used here are the same that they use on a smaller scale, but none the less
	// show the usage to be proper and I hope show understanding to a degree. -PC
	switch (LastHtObject)
	{
	case GraphicsComp::Nothing:
		// gl code for color here
		glColor3f(SingletonGraphStates::instance().getTriangleDefault().r,
			SingletonGraphStates::instance().getTriangleDefault().g,
			SingletonGraphStates::instance().getTriangleDefault().b);
		break;
	case GraphicsComp::Triangle:
		// gl code for triangle here
		glColor3f(SingletonGraphStates::instance().getTriangleTriangle().r,
			SingletonGraphStates::instance().getTriangleTriangle().g,
			SingletonGraphStates::instance().getTriangleTriangle().b);
		break;
	case GraphicsComp::Circle:
		// gl code for circle 
		glColor3f(SingletonGraphStates::instance().getTriangleCircle().r,
			SingletonGraphStates::instance().getTriangleCircle().g,
			SingletonGraphStates::instance().getTriangleCircle().b);
		break;
	case GraphicsComp::Square:
		// gl code for circle
		glColor3f(SingletonGraphStates::instance().getTriangleSquare().r,
			SingletonGraphStates::instance().getTriangleSquare().g,
			SingletonGraphStates::instance().getTriangleSquare().b);
		break;
	}
	glVertex2f(pointOne.x,pointTwo.y);
	glVertex2f(pointTwo.x,pointTwo.y);
	glVertex2f(pointThree.x,pointThree.y); // TODO work this out to be correct -PC
	glEnd();
}

void TriangleGraphComp::OnCollideSquare()
{
}

void TriangleGraphComp::OnCollideCircle()
{
}

void TriangleGraphComp::OnCollideTriangle()
{
}
