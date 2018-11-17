#pragma once
#include <memory>
#include <vector>

class Shape;
class Transform;
class Circle;
class Square;
class Triangle;

class ShapePool
{
public:
	ShapePool();
	virtual ~ShapePool();

	void create();

	void Distirbute(); // no idea how to do this - PC

	void Display(std::chrono::milliseconds ElapsedDeltaTime);

	void Update(std::chrono::milliseconds ElapsedDeltaTime);

	void Load();

private:

	static const int POOL_SIZE = 120; 

	static Square* squaresInPool[POOL_SIZE / 3];
	static Circle* circlesInPool[POOL_SIZE / 3]; 
	static Triangle* trianglesInPool[POOL_SIZE / 3];


	std::vector<Shape*[POOL_SIZE]> shapes;
};

