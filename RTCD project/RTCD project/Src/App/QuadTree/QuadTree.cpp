#include "QuadTree.h"
#include "glm/glm.hpp"

Node::Node(float halfWidth) : m_halfWidth(halfWidth)// AABB for Quad Tree/nodes -PC
{
}

Node::~Node()
{

};

QuadTree::QuadTree(const Node& Boundary, int poolsize)
	:Boundary(Boundary), Capacity(poolsize)
{
}


QuadTree::~QuadTree()
{
}

Node* QuadTree::BuildQuadtree(glm::vec2 centre, float halfWidth, int stopDepth)
{
	if (stopDepth < 0) return nullptr;
	else
	{
		Node* pNode = new Node(halfWidth);
		pNode->centre = centre;
		//pNode->m_halfWidth = halfWidth; // done in initialiser list -PC
		glm::vec2 offset; // this is the difference between the current centre and the children centre 
		float step = halfWidth * 0.5;
		for (int i = 0; i < 4; i++) // this performs bitwise partitions, it sets the offset for the centres of the children based on quadrants -PC
		{
			float x = ((i & 1) ? step : -step); // 1&1, 1&3 = true
			float y = ((i & 2) ? step : -step);
			glm::vec2 o(x, y);
			offset = glm::vec2(o);
			pNode->pChild[i] = BuildQuadtree(centre + offset, step, stopDepth - 1); // stop depth -1 to fix hard cap on size -PC
		}
		return pNode;
	}
}


void QuadTree::Insert(Node* pTree, Shape* pShape) // how would I change this to take in and Std:vector ie the entire pool.
{
	int index = 0; // identifies in which quadrant the object is
	int straddle = 0; // flags whether the object overlaps more then one quadrant
	// perhaps incase in a greater loop. -PC
	for (int i = 0; i < 2; i++) // The objective of this loop is to assess which quad the point lies in, by first assessing X, in terms of +- (right or left of centre respectively in Cartesian terms), and then the same for Y.
	{                                                                         // all inserted objects to the partition need to have a accessible value for centre - shapes 
		float delta = pShape->GetPosition().[i] - pTree->centre.[i]; // This is the X and Y aspect of a glm:vec in our scenario and its being iterated through by an Index, set int he forloop -PC
		if (abs(delta) <= pShape->GetDistanceMetric()) // this universally returns the CORRECT basis of measurement for circle, square and triangle in terms of half widths -PC
		{
			straddle = 1; 
			break;
		}
		if (delta > 0.0f)
		{
			index |= (1 << i);
		}
		if (!straddle) // if the object is inside the cell
		{
			if (pTree->pChild[index] == nullptr) // if child does not exist
			{
				pTree->pChild[index] = new Node;
				//Node initialization 
			}
			Insert(pTree->pChild[index], pShape);
		}
		else
		{
			pObject->pNextObject = pTree->pObjList; // subdevide?
			pTree->pObjList = pObject->pNextObject;
		}
	}
}

void QuadTree::SubDevide()
{
}

void QuadTree::TestAllcollisions(Node* pTree)
{
	// keep track of all ancestor objects in a stack
	const int MAX_DEPTH = 256;
	static Node* ancestorStack[MAX_DEPTH];
	static int depth = 0;

	// check collision between all objects on this level and all
	// ancestor objects. The current level is included as its own
	// ancestor so all necesary pairwise tests are done
	ancestorStack[depth++] = pTree;
	for (int n = 0; n < depth; n++)
	{
		//get this explained
	}
}



