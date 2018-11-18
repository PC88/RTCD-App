#pragma once
#include "GraphicsComp.h"
class CircleGraphComp :
	public GraphicsComp
{
public:
	CircleGraphComp(std::shared_ptr<Transform> ShapeTransform, float& r, glm::vec2& vel, glm::vec2& acc);
	virtual ~CircleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime);

	void OnCollideSquare();

	void OnCollideCircle();

	void OnCollideTriangle();

private:

	float radius;

	vec2 velocity;
	vec2 acceleration;
	std::shared_ptr<Transform> ShapeTransform;
};

