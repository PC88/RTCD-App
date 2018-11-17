// UMARS contribution, with edits from PC.
// CHANGES -PC: ElapsedGameTime to ElapsedDeltaTime, Destructor added
// Glut include removed this fools the compiler in to using a glut Macro for "Circle" instead of class circle
// forward decelerations Added to save compile time, includes removed for all forward declarations
// gl functions removed should be in graph comps
// using namespace added to .cpp as well as .h for consistency
// graphic and physics comp declarations and respective implementation added
// rand seed added for more "random" randomness, aye.. that one...
#pragma once
#include "Shape.h"
#include <memory>
#include <glm\glm.hpp>
#include <chrono>

class CircleGraphComp;
class CirclePhysicsComp;

using namespace glm;

class Circle : public Shape

{

private:

	std::unique_ptr<CircleGraphComp> graphicComp;
	std::unique_ptr<CirclePhysicsComp> physicsComp;
	bool inUse = false;
	float x, y, r;
	float dx, dy;


public:

	Circle(float x, float y, float r);
	virtual ~Circle();

	void Update(std::chrono::milliseconds ElapsedDeltaTime) override;

	void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	bool InUse();

	vec2 GetDirection();
	vec2 GetPoistion()

};

