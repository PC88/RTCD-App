#pragma once
#include <memory>
#include <vector>
#include <chrono>

class Shape;
class Transform;
class Circle;
class Square;
class Triangle;
//class int; // Why I have to do this is just nuts.

class ShapePool
{
public:
	ShapePool();
	virtual ~ShapePool();

	void create();

	void Display(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height);

	void Load();

private:

	static const int POOL_SIZE = 120; 

	static Square* squaresInPool[POOL_SIZE / 3];
	static Circle* circlesInPool[POOL_SIZE / 3]; 
	static Triangle* trianglesInPool[POOL_SIZE / 3];


	std::vector<Shape*[POOL_SIZE]> shapes;
};

