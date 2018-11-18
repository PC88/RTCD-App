#pragma once
#include "GraphicsComp.h"
#include <memory>
#include "glm/glm.hpp"

class SquareGraphComp :
	public GraphicsComp
{
public:
	SquareGraphComp(std::shared_ptr<Transform> ShapeTransform, vec2& vel, vec2& acc, float& w, float& h);
	virtual ~SquareGraphComp();

	 void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	 virtual void OnCollideSquare() override; 

	 virtual void OnCollideCircle() override;

	 virtual void OnCollideTriangle() override;

private:

	std::shared_ptr<Transform> ShapeTransform;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	float width;
	float height;

};

