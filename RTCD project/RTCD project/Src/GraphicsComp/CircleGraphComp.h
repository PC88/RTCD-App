#pragma once
#include "GraphicsComp.h"
class CircleGraphComp :
	public GraphicsComp
{
public:
	CircleGraphComp(std::shared_ptr<Transform> ShapeTransform);
	virtual ~CircleGraphComp();

	void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	virtual void OnCollideSquare() override;

	virtual void OnCollideCircle() override;

	virtual void OnCollideTriangle() override;

private:

	std::shared_ptr<Transform> ShapeTransform;
};

