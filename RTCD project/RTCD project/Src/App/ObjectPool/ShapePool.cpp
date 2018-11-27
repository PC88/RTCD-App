#include "ShapePool.h"
#include "Shape.h"
#include "Transform.h"
#include <iterator>
#include "glut/include/glut.h" 
#include "QuadTree.h"



ShapePool::ShapePool()
{
}


ShapePool::~ShapePool() 
{
	for (int i = 0; i < POOL_SIZE; i++) // I think this does the job -PC
	{
		delete(shapes[i]);
	}
}

void ShapePool::create()
{
	this->Load(); // fills vector with all respective shapes -PC
}

void ShapePool::Display(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		shapes[i]->Update(ElapsedDeltaTime, width, height);
	}
}

void ShapePool::Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height)
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		shapes[i]->Update(ElapsedDeltaTime, width, height);
	}
}

void ShapePool::Load() 
{
	Shape* lastObject;
	Shape* startObject = shapes[0]->pNextObject;
	shapes[0]->pNextObject = startObject; // initialise linked list start -PC
	lastObject = shapes[0];

	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		if (!shapes[i]->InUse()) // makes sure the entire array does in fact get filled - just a re-useage of the object pool pattern -PC
		{
			float hw = 3.0f;
			glm::vec2 vel;
			glm::vec2 acc;
			shapes[i] = new Square(vel, acc, hw);
			lastObject = shapes[i]->pNextObject; // link the list -PC
		}
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		if (!shapes[i]->InUse())
		{
			float radius = 3.0f;
			glm::vec2 vel;
			glm::vec2 acc;
			shapes[i] = new Circle(radius, vel, acc);
			lastObject = shapes[i]->pNextObject;
		}
	}
	for (int i = 0; i < POOL_SIZE / 3; i++)
	{
		if (!shapes[i]->InUse())
		{
			float hw = 3.0f;
			glm::vec2 vel;
			glm::vec2 acc;
			shapes[i] = new Triangle(hw, vel, acc);
			lastObject = shapes[i]->pNextObject;
		}
	}
}

int ShapePool::GetSize() const
{
	return POOL_SIZE;
}
