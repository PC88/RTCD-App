#pragma once
#include "Shape.h"
#include <chrono>
#include "glut/include/glut.h"

class GraphicsComp
{
public:
	GraphicsComp();
	virtual ~GraphicsComp();

	virtual void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) = 0; // render function which will be called on all of our shapes, and changed on each shape respectively -PC


	/// collision reaction code, graphic element ///

	virtual void OnCollideGraphics(int type) = 0;


protected:

	enum LastcollidedWith { Nothing, Triangle, Circle, Square};
	LastcollidedWith LastHtObject;
	
};

