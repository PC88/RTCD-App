#pragma once
// First attempt at QuadTree - PC
#include "glm/vec2.hpp"
#include "Shape.h"

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
	glm::vec2 centre;
	Node* pChild[4];
	
};

class QuadTree 
{

private:

	int Capacity;
	Node Boundary;
	int stopDepth;

public:
	QuadTree(const Node& Boundary, int pool)
	{
	};
	~QuadTree();

	Node*  BuildQuadtree(glm::vec2 centre, float halfWidth, int stopDepth); // stopDepth is how tall the tree can grow in our case - PC

	void Insert(Node* pTree, Shape* pShape);

	void SubDevide();

};

