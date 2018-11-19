#include "SquareGraphComp.h"
#include "Transform.h"
#include "SingletonGraphStates.h"




SquareGraphComp::SquareGraphComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& vel, glm::vec2& acc, float& w, float& h)
	: ShapeTransform(ShapeTransform), velocity(vel), acceleration(acc), width(w), height(h)
{
	LastHtObject = GraphicsComp::Nothing;
}

SquareGraphComp::~SquareGraphComp()
{
}

void SquareGraphComp::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	position = ShapeTransform->getPosition();
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)

   
	glBegin(GL_QUADS);
	
	//NOTE: glColor3f(color.r, color.g, color.b) // this is basically whats being done here to avoid copying, and to use the flyweight pattern -PC
	// it may be seen as somewhat "unimpactfull" in this project as its a ref to 9 simple color outcomes as opposed to actual large objects
	// however this is there so show the utilization of what an engine COULD do... if this was not GLUT, and I had more time/experience for example I would have a renderer which had information obound to
	// uniforms like modern OpenGL does, or even further a Material like a REAL game engine, but the principles used here are the same that they use on a smaller scale, but none the less
	// show the usage to be proper and I hope show understanding to a degree. -PC
	switch (LastHtObject)
	{
	case GraphicsComp::Nothing:
		// gl code for color here
		glColor3f(SingletonGraphStates::instance().getSquareDefault().r,
			SingletonGraphStates::instance().getSquareDefault().g,
			SingletonGraphStates::instance().getSquareDefault().b);
		break;
	case GraphicsComp::Triangle:
		// gl code for triangle here
		glColor3f(SingletonGraphStates::instance().getSquareTriangle().r,
			SingletonGraphStates::instance().getSquareTriangle().g,
			SingletonGraphStates::instance().getSquareTriangle().b);
		break;
	case GraphicsComp::Circle:
		// gl code for circle 
		glColor3f(SingletonGraphStates::instance().getSquareCircle().r,
			SingletonGraphStates::instance().getSquareCircle().g,
			SingletonGraphStates::instance().getSquareCircle().b);
		break;
	case GraphicsComp::Square:
		// gl code for circle
		glColor3f(SingletonGraphStates::instance().getSquareSquare().r,
			SingletonGraphStates::instance().getSquareSquare().g,
			SingletonGraphStates::instance().getSquareSquare().b);
		break;
	}
	glVertex2f(2  * aspectRatio / width, 2  / height);
	glVertex2f(-2  * aspectRatio / width, 2  / height);
	glVertex2f(-2  * aspectRatio / width, -2 / height);
	glVertex2f(2  * aspectRatio / width, -2  / height); // TODO work this out to be correct -PC
	glEnd();
}


void SquareGraphComp::OnCollideSquare()
{
	// event system link to change chosen graphic component - PC
}

void SquareGraphComp::OnCollideCircle()
{
	// event system link to change chosen graphic component - PC
}

void SquareGraphComp::OnCollideTriangle()
{
	// event system link to change chosen graphic component - PC
}
