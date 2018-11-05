#pragma once
#include "GraphicsComp.h"
#include "glm.hpp"

class SquareGraphComp :
	public GraphicsComp
{
public:
	SquareGraphComp(std::shared_ptr<Transform> ShapeTransform);
	virtual ~SquareGraphComp();

	 void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	 virtual void OnCollideSquare() override; 

	 virtual void OnCollideCircle() override;

	 virtual void OnCollideTriangle() override;

private:

	std::shared_ptr<Transform> ShapeTransform;
};

