#include "CircleGraphComp.h"
#include "Transform.h"
#include "SingletonGraphStates.h"

#include "glm/gtc/constants.hpp" // this makes no sense as to why this dosent work
#include "glut/include/glut.h" // makes even less sense

CircleGraphComp::CircleGraphComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc)
	: ShapeTransform(ShapeTransform), radius(r), velocity(vel), acceleration(acc)
{
	LastHtObject = GraphicsComp::Nothing;
}

CircleGraphComp::~CircleGraphComp()
{
}

void CircleGraphComp::Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	position = ShapeTransform->getPosition();
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)

   // Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);

	//NOTE: glColor3f(color.r, color.g, color.b) // this is basically whats being done here to avoid copying, and to use the flyweight pattern -PC
	// it may be seen as somewhat "unimpactfull" in this project as its a ref to 9 simple color outcomes as opposed to actual large objects
	// however this is there so show the utilization of what an engine COULD do... if this was not GLUT, and I had more time/experience for example I would have a renderer which had information obound to
	// uniforms like modern OpenGL does, or even further a Material like a REAL game engine, but the principles used here are the same that they use on a smaller scale, but none the less
	// show the usage to be proper and I hope show understanding to a degree. -PC
	switch (LastHtObject) 
	{
	case GraphicsComp::Nothing:
		// gl code for color here
		glColor3f(SingletonGraphStates::instance().getCircleDefault().r, 
			SingletonGraphStates::instance().getCircleDefault().g, 
			SingletonGraphStates::instance().getCircleDefault().b);
		break;
	case GraphicsComp::Triangle: 
		// gl code for triangle here
		glColor3f(SingletonGraphStates::instance().getCircleTriangle().r,
			SingletonGraphStates::instance().getCircleTriangle().g, 
			SingletonGraphStates::instance().getCircleTriangle().b);
		break;
	case GraphicsComp::Circle:
		// gl code for circle 
		glColor3f(SingletonGraphStates::instance().getCircleCircle().r,
			SingletonGraphStates::instance().getCircleCircle().g,
			SingletonGraphStates::instance().getCircleCircle().b);
		break;
	case GraphicsComp::Square:
		// gl code for circle
		glColor3f(SingletonGraphStates::instance().getCircleSquare().r,
			SingletonGraphStates::instance().getCircleSquare().g,
			SingletonGraphStates::instance().getCircleSquare().b);
		break;
	}

	glVertex2f((float)position.x, (float)position.y);	// Center of circle

	int numSegments = 100;
	float angle;
	for (int i = 0; i <= numSegments; i++)
	{					// Last vertex same as first vertex
		angle = i * 2.0f * pi<float>()/ numSegments;			// 360 deg for all segments // I could approximate this but I refuse to until this is explained ALL ERRORS THIS LINE-PC
		glVertex2f(cos(angle) * (2.0f * radius / width)* aspectRatio,
			sin(angle) * (2.0f * radius / height));
	}
	glEnd();
	
}

void CircleGraphComp::OnCollideSquare()
{
}

void CircleGraphComp::OnCollideCircle()
{

}

void CircleGraphComp::OnCollideTriangle()
{
}

