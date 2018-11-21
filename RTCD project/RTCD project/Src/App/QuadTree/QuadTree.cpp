#include "QuadTree.h"
#include "glm/glm.hpp"

/////////// RECTANGLE STUFF //////////// - PC

Node::Node(float halfWidth)// AABB for Quad Tree
{
}

Node::~Node()
{

};

QuadTree::QuadTree(const Node& Boundary, int poolsize)
	:Boundary(Boundary), Capacity(pool)
{
}


QuadTree::~QuadTree()
{
}

Node * QuadTree::BuildQuadtree(glm::vec2 centre, float halfWidth, int stopDepth)
{
	if (stopDepth < 0) return nullptr;
	else
	{
		Node* pNode = new Node(halfWidth);
		pNode->centre = centre;
		pNode->halfWidth = halfWidth;
		// object list code - shape pool
		glm::vec2 offset; // this is the difference between the current centre and the children centre 
		float step = halfWidth * 0.5;
		for (int i = 0; i < 4; i++)
		{
			float x = ((i & 1) ? step : -step);
			float y = ((i & 2) ? step : -step);
			glm::vec2 o(x, y);
			offset = vec2(o);
			pNode->pChild[i] = BuildQuadtree(centre + offset, step, stopDepth - 1);
		}
		return pNode;
	}
	
}


void QuadTree::Insert()
{
	
}

void QuadTree::SubDevide()
{
}




