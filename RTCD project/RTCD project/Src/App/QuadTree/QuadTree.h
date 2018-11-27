#pragma once
// First attempt at QuadTree - PC
#include "glm/vec2.hpp"
#include "Shape.h"

struct Node// AABB for Quad Tree
{

public:
	Node();

	virtual ~Node();

	// can be public because its a struct?
	float m_halfWidth;
	glm::vec2 centre;
	Node* pChild[4];
	Shape* pObjList;
	
};

class QuadTree 
{

private:

	int Capacity;
	Node m_Boundary;
	int stopDepth;

public:
	QuadTree(const Node& Boundary, int pool);
	~QuadTree();

	Node*  BuildQuadtree(glm::vec2 centre, float halfWidth, int stopDepth); // stopDepth is how tall the tree can grow in our case - PC

	void Insert(Node* pTree, Shape* pShape);

	void TestAllcollisions(Node* pTree);

};

