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
#pragma once
#include <chrono>

class CircleGraphComp;
class CirclePhysicsComp;
//class int;

using namespace glm;

class Circle : public Shape

{

private:

	std::unique_ptr<CircleGraphComp> graphicComp;
	std::unique_ptr<CirclePhysicsComp> physicsComp;
	bool inUse = false;
	float radius;
	float halfwidth;

	vec2 velocity;
	vec2 acceleration;
	vec2 position; // this will init to random points with in screen dimensions in the constructor -PC


public:

	Circle(float& r, vec2& vel, vec2& acc);
	virtual ~Circle();

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void OnCollide(int type);

	bool InUse();

	int GetType();

	float GetHalfwidth();

	vec2 GetDirection() const;
	vec2 GetPosition() const;
	float GetDistanceMetric() const;
};

