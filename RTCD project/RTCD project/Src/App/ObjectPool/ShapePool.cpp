#include "ShapePool.h"
#include "Shape.h"
#include "Transform.h"
#include <iterator>
#include <chrono>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"



ShapePool::ShapePool()
{
}


ShapePool::~ShapePool() 
{
	for (std::vector<Shape*[POOL_SIZE]>::iterator I = shapes.begin(); I < shapes.end(); I++) // handles deletion of shape pool
	{
		delete(*I);
	}
}

void ShapePool::create()
{
	// This method should add all 3 arrays contents to the vector container shapes.
	// I do hope this is doing it correctly and not just over writing its self each time I do this. -PC
	shapes.insert(shapes.end(), std::begin(squaresInPool), std::end(squaresInPool)); // C++ 11 way of loading arrays to vector -PC
	shapes.insert(shapes.end(), std::begin(circlesInPool), std::end(circlesInPool));
	shapes.insert(shapes.end(), std::begin(trianglesInPool), std::end(trianglesInPool));
}

void ShapePool::Distirbute() 
{
	
}

void ShapePool::Display(std::chrono::milliseconds ElapsedDeltaTime)
{
	for (std::vector<Shape*>::iterator it = shapes.begin; it < shapes.end; it++)
	{
		(*it)->Render(ElapsedDeltaTime); // just call render which CALLS render on the respective graphic comps via call back -PC
	}
}

void ShapePool::Update(std::chrono::milliseconds ElapsedDeltaTime)
{
	for (std::vector<Shape*>::iterator it = shapes.begin; it < shapes.end; it++)
	{
		(*it)->Update(ElapsedDeltaTime); // just call update which CALLS update on the respective physics comps via call back -PC
	}
}

void ShapePool::Load() //its either this way or 500+ lines of manual code it seems -PC
{
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		squaresInPool[i] = new Square(); // change constructor to take position and respective shite
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		circlesInPool[i] = new Circle(); // change constructor to take position and respective shite
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		trianglesInPool[i] = new Triangle(); // change constructor to take position and respective shite
	}
}
