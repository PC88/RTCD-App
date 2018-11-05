#pragma once
#include <memory>

class Shape;
class Transform;

class ShapePool
{
public:
	ShapePool();
	virtual ~ShapePool();

	void create(Transform transform); // may not need this param - PC

	void Distirbute(); // no idea how to do this - PC

private:

	static const int POOL_SIZE = 120;

	std::shared_ptr<Shape[POOL_SIZE]> Shapes; // shared for now maybe best to use raw later - PC
};

