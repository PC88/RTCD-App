// UMARS contribution, with edits from PC.
// CHANGES -PC: ElapsedGameTime to ElapsedDeltaTime, Destructor added
// Glut include removed this fools the compiler in to using a glut Macro for "Circle" instead of class circle
// forward decelerations Added to save compile time, includes removed for all forward declarations
// gl functions removed should be in graph comps
// using namespace added to .cpp as well as .h for consistency
// graphic and physics comp declarations and respective implementation added
// rand seed added for more "random" randomness, aye.. that one...
#pragma once
#include <iostream>
#include <glm\glm.hpp>
#include <chrono>
#include "Shape.h"
#include "glut\include\glut.h"

class TriangleGraphComp;
class TrianglePhysicsComp;
class Transform;
using namespace glm;

class Triangle : public Shape
{
private:

	bool inUse;
	float halfwidth;
	glm::vec2 topPoint;
	glm::vec2 leftPoint;
	glm::vec2 rightPoint;
	vec2 position;

	vec2 velocity;
	vec2 acceleration;
	std::shared_ptr<Transform> ShapeTransform;

	std::unique_ptr<TriangleGraphComp> graphicComp;
	std::unique_ptr<TrianglePhysicsComp> physicsComp;

public:

	virtual ~Triangle();
	Triangle(float& hw, vec2& vel, vec2& acc);

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);
	void OnCollide(int type);
	void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);
	vec2 GetDirection() const;
	vec2 GetPosition() const;
	float GetDistanceMetric() const;
	int GetType();
	bool InUse();
};