#pragma once
#include "GraphicsComp.h"
class CircleGraphComp :
	public GraphicsComp
{
public:
	CircleGraphComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc);
	virtual ~CircleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void OnCollideSquare();

	void OnCollideCircle();

	void OnCollideTriangle();

private:

	float radius;

	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 position;
	std::shared_ptr<Transform> ShapeTransform;
};

