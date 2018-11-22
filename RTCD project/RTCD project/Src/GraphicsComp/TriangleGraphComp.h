#pragma once
#include "GraphicsComp.h"
#include <memory>

class Transform;

class TriangleGraphComp :
	public GraphicsComp
{
public:
	TriangleGraphComp(std::shared_ptr<Transform> ShapeTransform, float& hw, glm::vec2& vel, glm::vec2& acc);
	virtual ~TriangleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) ;

	virtual void OnCollideGraphics(int type);

private:

	glm::vec2 topPoint;
	glm::vec2 leftPoint;
	glm::vec2 rightPoint;

	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 position;

	std::shared_ptr<Transform> ShapeTransform;
};

