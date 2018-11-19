#pragma once
#include "GraphicsComp.h"
#include <memory>

class Transform;

class TriangleGraphComp :
	public GraphicsComp
{
public:
	TriangleGraphComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, glm::vec2& vel, glm::vec2& acc);
	virtual ~TriangleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height) ;

	virtual void OnCollideSquare();

	virtual void OnCollideCircle();

	virtual void OnCollideTriangle();

private:

	glm::vec2 pointOne;
	glm::vec2 pointTwo;
	glm::vec2 pointThree;

	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 position;

	std::shared_ptr<Transform> ShapeTransform;
};

