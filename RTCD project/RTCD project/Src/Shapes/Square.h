#pragma once
#include "Shape.h"
#include "SquareGraphComp.h"
#include "SquarePhysicsComp.h"
#include <memory>

class SquarePhysicsComp;

class Square :
	public Shape

{
private:

	std::unique_ptr<SquareGraphComp> graphicComp;
	std::unique_ptr<SquarePhysicsComp> physicsComp;

	float halfwidth;

	vec2 velocity;
	vec2 acceleration;
	vec2 position; // this will init to random points with in screen dimensions in the constructor -PC

	bool inUse = false;

public:

	Square(vec2& vel, vec2& acc, float& hw);

	virtual ~Square();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void OnCollide(int type);

	bool InUse();

	int GetType();

	float GetDistanceMetric() const;

	float GetHalfwidth();

	glm::vec2 GetDirection() const;

	glm::vec2 GetPosition() const;
};

