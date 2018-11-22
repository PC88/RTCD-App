#pragma once
#include "GraphicsComp.h"
#include <memory>
#include "glm/glm.hpp"

class SquareGraphComp :
	public GraphicsComp
{
public:
	SquareGraphComp(std::shared_ptr<Transform> ShapeTransform, glm::vec2& vel, glm::vec2& acc, float& w, float& h);
	virtual ~SquareGraphComp();

	 void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) ;

	 void OnCollideGraphics(int type);

private:

	std::shared_ptr<Transform> ShapeTransform;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	float width;
	float height;
	glm::vec2 position;

};

