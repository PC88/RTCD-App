#pragma once
#include <memory>
#include <vector>
#include <chrono>

class Shape;
class Transform;

#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

class ShapePool
{
public:
	ShapePool();
	virtual ~ShapePool();

	void create();

	void Display(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Load();

	int GetSize() const;

private:

	static const int POOL_SIZE = 120; 

	Shape* shapes[POOL_SIZE];
};

