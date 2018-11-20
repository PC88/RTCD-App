#pragma once
// First attempt at QuadTree - PC


struct Node// AABB for Quad Tree
{

public:
	Node(float halfWidth)
	{
	};

	virtual ~Node()
	{
	};

private:
	float halfWidth;
	Node* pChild[4];
	//GameObject* pObjList, should this be the literal pool of objects passed as param? -PC
};

class QuadTree
{

private:

	int Capacity;
	Node Boundary;

public:
	QuadTree(const Node& Boundary, int pool)
	{
	};
	~QuadTree();

	void Insert();

	void SubDevide();

};

