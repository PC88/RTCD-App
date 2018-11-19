#include "ShapePool.h"
#include "Shape.h"
#include "Transform.h"
#include <iterator>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "glut/include/glut.h" 



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
	this->Load(); // calls once fills all 3 sub arrays -PC
	// This method should add all 3 arrays contents to the vector container shapes.
	// I do hope this is doing it correctly and not just over writing its self each time I do this. -PC
	shapes.insert(shapes.end(), std::begin(squaresInPool), std::end(squaresInPool)); // C++ 11 way of loading arrays to vector -PC
	shapes.insert(shapes.end(), std::begin(circlesInPool), std::end(circlesInPool));
	shapes.insert(shapes.end(), std::begin(trianglesInPool), std::end(trianglesInPool));
}

void ShapePool::Display(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	for (std::vector<Shape*>::iterator it = shapes.begin; it < shapes.end; it++)
	{
		(*it)->Render(ElapsedDeltaTime, width, height); // just call render which CALLS render on the respective graphic comps via call back -PC
	}
}

void ShapePool::Update(std::chrono::milliseconds ElapsedDeltaTime, GLsizei width, GLsizei height)
{
	for (std::vector<Shape*>::iterator it = shapes.begin; it < shapes.end; it++)
	{
		(*it)->Update(ElapsedDeltaTime, width, height); // just call update which CALLS update on the respective physics comps via call back -PC
	}
}

void ShapePool::Load() //its either this way or 500+ lines of manual code it seems -PC
{
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		float width = 3.0f;
		float height = 3.0f;
		glm::vec2 vel;
		glm::vec2 acc;
		squaresInPool[i] = new Square(acc, vel, width, height);
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		float radius = 3.0f;
		glm::vec2 vel;
		glm::vec2 acc;
		circlesInPool[i] = new Circle(radius,vel,acc); // change constructor to take position and respective shite
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		glm::vec2 vec1;
		glm::vec2 vec2;
		glm::vec2 vec3;
		glm::vec2 vel;
		glm::vec2 acc;
		trianglesInPool[i] = new Triangle(vec1, vec2, vec3, vel, acc); // change constructor to take position and respective shite
	}
}
