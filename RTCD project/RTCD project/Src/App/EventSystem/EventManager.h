#pragma once
class EventManager
{
public:

	bool CircleAABBCollision(PhysicsComp& c1, PhysicsComp& b);
	void ClosestPtPointAABB(vec2& P, PhysicsComp& b, vec2& q);
	bool AABBAABBCollision(PhysicsComp& A, PhysicsComp& B);

	void CheckCollisions();

	EventManager(std::vector<Shape*>&); // this is gonna get wild -PC
	virtual ~EventManager();

private:
	std::vector<Shape*> activePool;
};

