#include "TriangleGraphComp.h"

TriangleGraphComp::TriangleGraphComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc)
	:ShapeTransform(ShapeTransform), pointOne(p1), pointTwo(p2), pointThree(p3), velocity(vel), acceleration(acc)
{
}

TriangleGraphComp::~TriangleGraphComp()
{
}

void TriangleGraphComp::Render(std::chrono::milliseconds ElapsedDeltaTime) // COPY PASTE OF SQUARE GRAPHCOMP
{
	switch (LastHtObject) // TODO finish this up
	{
	case GraphicsComp::Nothing:
		// gl code for color here

		break;
	case GraphicsComp::Triangle: // TODO change the elements of this to be a SQUARE ELEMENT issue - PC
		// gl code for triangle here
		vec2 position = ShapeTransform->getPosition();
		glLoadIdentity();				// Reset model-view matrix
		float aspectRatio = (width / (float)height);
		glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
			(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)

	   // Use triangular segments to form a circle
		glBegin();
		glColor3f(color.r, color.g, color.b);						// Cyan
		glVertex2f(0.0f, 0.0f);										// Center of circle
		int numSegments = 100;
		float angle;
		for (int i = 0; i <= numSegments; i++) {					// Last vertex same as first vertex
			angle = i * 2.0f * pi<float>() / numSegments;			// 360 deg for all segments
			glVertex2f(cos(angle) * (2.0f * radius / width)* aspectRatio,
				sin(angle) * (2.0f * radius / height));
		}
		glEnd();
		break;
	case GraphicsComp::Circle:
		// gl code for circle 

		break;
	case GraphicsComp::Square:
		// gl code for circle

		break;
	}
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
