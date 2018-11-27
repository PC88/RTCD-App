#include "glm/glm.hpp"		
#include "glut/include/glut.h"
#include <memory>
#include "ObjectPool\ShapePool.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include <vector>
#include "SingletonGraphStates.h"
#include "Transform.h"
#include "QuadTree.h"
#include "GameWindow.h"

int width = 1000; // set to 1k/1k so as to allow a nice distribution of QuadTree -PC
int height = 1000; // this is also terrible practice but hey if im using a set of globals I might as well use these -PC


char title[] = "RTCD";
char* ptrTitle = title; // this is quite strange in comparison to the LAB code which seemingly converts implicitly -PC
GameWindow* window = new GameWindow(title, width, height, 100, 100);

std::unique_ptr<ShapePool> Pool = std::make_unique<ShapePool>();
Node* root;
std::unique_ptr<QuadTree> quadTree = std::make_unique<QuadTree>(root, 120);
std::chrono::milliseconds UpdateElapsedDeltaTime;
std::chrono::milliseconds DisplayElapsedDeltaTime;

void ReshapeWindow(int width, int height) 
{
	window->Reshape(width, height);
}

void reshape(int width, int height)
{
	ReshapeWindow(width, height); 
}

void initGL() 
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void display()
{
	auto LastTime = std::chrono::steady_clock::now(); // these have to be duplicated due to limitations of GLUT -PC
	auto CurrentTime = std::chrono::steady_clock::now();
	DisplayElapsedDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastTime);
	Pool->Display(DisplayElapsedDeltaTime, width, height);
	LastTime = CurrentTime;
}

void update(int value) // value not used here as I am using the global "Display/Update ElapsedDeltaTime" to go over GLUTS API in the timer and display callbacks -PC
{
	auto LastTime = std::chrono::steady_clock::now(); // these have to be duplicated due to limitations of GLUT -PC
	auto CurrentTime = std::chrono::steady_clock::now();
	UpdateElapsedDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastTime);
	Pool->Update(UpdateElapsedDeltaTime, width, height);
	quadTree->TestAllcollisions(root); // text collisions within spacial data structure -PC
	LastTime = CurrentTime;
}

void GLUTRenderer()
{	// Register callback handler for window re-paint
	glutReshapeFunc(reshape);		// Register callback handler for window re-shape - goes to global reshape, then Appman::Reshapewindow, then m_window Reshape // this is bad -PC JankAF
	glutTimerFunc(0, update, 0);
	glutDisplayFunc(display);		// First timer call immediately
	initGL();						// Our own OpenGL initialization
	glutMainLoop();					// Enter event-processing loop
}

int main(int argc, char** argv)
{

	int stopDepth = 4; // this means MAX_DEPTH = 256 -PC
	glutInit(&argc, argv); 

	Pool->create(); 
	quadTree->BuildQuadtree(glm::vec2(height / 2, width / 2), width / 2, stopDepth); // init QT, -PC
	for (int i = 0; 1 < Pool->GetSize(); i++)
	{
		quadTree->Insert(root, *Pool[i]); // how do I get a pointer to the root node, to make this generic -PC
	}

	SingletonGraphStates::instance().initialise(); // init singleton -PC
	
	GLUTRenderer(); // This in a similar form - although not the same as LAB`s hence the Param. -PC
	return 0;
}
