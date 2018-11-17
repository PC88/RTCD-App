#pragma once
#include "glm/vec2.hpp"
#include <memory>
#include <chrono>

class Transform;

class Shape
{
public:
	Shape();
	virtual ~Shape();

	// Transform need to go in here - PC 

	virtual void Update(std::chrono::milliseconds ElapsedDeltaTime) = 0;

	virtual bool InUse() = 0;

	virtual void Render(std::chrono::milliseconds ElapsedDeltaTime) = 0;

	virtual glm::vec2 GetDirection() = 0;

	virtual glm::vec2 GetPoistion() = 0;


private:

	glm::vec2 direction;

	glm::vec2 position;

protected:

	std::shared_ptr<Transform> ShapeTransform; // all shapes will have this TODO better way to do this than accessorfunction accessing an accessor function -PC

};