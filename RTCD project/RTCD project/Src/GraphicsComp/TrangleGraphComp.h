#pragma once
#include "GraphicsComp.h"

class TriangleGraphComp :
	public GraphicsComp
{
public:
	TriangleGraphComp(std::shared_ptr<Transform> ShapeTransform);
	virtual ~TriangleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	virtual void OnCollideSquare() override;

	virtual void OnCollideCircle() override;

	virtual void OnCollideTriangle() override;

private:

	std::shared_ptr<Transform> ShapeTransform;
};

