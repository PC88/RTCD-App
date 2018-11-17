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

class CircleGraphComp;
class CirclePhysicsComp;

using namespace glm;

class Triangle
{
private:

	float x, y;
	float dx, dy;
	bool inUse;

	std::unique_ptr<CircleGraphComp> graphicComp;
	std::unique_ptr<CirclePhysicsComp> physicsComp;

public:


	~Triangle() {};
	Triangle(float ix, float iy);

	void Update(std::chrono::milliseconds ElapsedDeltaTime);
	void Render(std::chrono::milliseconds ElapsedDeltaTime);
	vec2 GetDirection();
	vec2 GetPosition();
	bool InUse();
};