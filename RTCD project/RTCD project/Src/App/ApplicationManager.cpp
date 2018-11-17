#include "ApplicationManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" // Perhaps how we get the transform Matrix in to main application to be passed around.
#include "glut/include/glut.h" // Glut include
#include <memory>
#include "ObjectPool/ShapePool.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include <vector>

//void ApplicationManager::Initialise(std::shared_ptr<GameWindow> appWindow) // no fucking clue TODO fix this "is not compatible error" -PC
//{                                                                          // encapsulation, later this may be useful - PC
//	m_window = appWindow;
//	appWindow = std::make_shared<GameWindow>();
//}


std::shared_ptr<ApplicationManager> AppManager = std::make_shared<ApplicationManager>(); // JANK -PC will do until I get a better idea
std::shared_ptr<GameWindow> gameWindow = std::make_shared<GameWindow>("RTCD First Build", 640, 450, 50, 50);
std::unique_ptr<ShapePool> Pool = std::make_unique<ShapePool>();
std::chrono::milliseconds ElapsedDeltaTime;


ApplicationManager::ApplicationManager()
{
}



ApplicationManager::~ApplicationManager()
{
}






void ApplicationManager::ReshapeWindow(int width, int height)
{
	m_window->Reshape(width, height);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// global functions -PC ALL JANK QUITE POSSIBLY CHANGE THESE ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reshape(GLsizei width, GLsizei height)
{
	AppManager->ReshapeWindow(width, height); // this is bad -PC JankAF
}

void initGL() 
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}


void display()
{
	Pool->Display(ElapsedDeltaTime);
}

void update(int value) // value not used here as I am using the global "ElapsedDeltaTime" to go over GLUTS API in the timer and display callbacks -PC
{
	Pool->Update(ElapsedDeltaTime);
}

void GLUTRenderer(std::chrono::milliseconds ElapsedDeltaTime)
{
	// this really shows why glut is a terrible API to use
	// I am having to use the time globally - not good practice at all by any means, unless I want to go in to GLUT API files and change the following:
	// GLUTAPI void APIENTRY glutDisplayFunc(void (GLUTCALLBACK *func)(void));
	// GLUTAPI void APIENTRY glutTimerFunc(unsigned int millis, void (GLUTCALLBACK *func)(int value), int value);

	glutDisplayFunc(display);		// Register callback handler for window re-paint
	glutReshapeFunc(reshape);		// Register callback handler for window re-shape - goes to global reshape, then Appman::Reshapewindow, then m_window Reshape // this is bad -PC JankAF
	glutTimerFunc(0, update, 0);	// First timer call immediately
	initGL();						// Our own OpenGL initialization
	glutMainLoop();					// Enter event-processing loop
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// global functions -PC ALL JANK QUITE POSSIBLY CHANGE THESE ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) 
{
	// create pool -PC
	Pool->create(); // creates 4 arrays 1 dynamic 3 standard which are loaded in to the dynamic for abstract iteration -PC

	// iterate through the object pool and update and call Update(), Render(), and Collide() on all shape composite objects, graphics and physics respectivley. - PC
	//title, width, height, posX, posY


	glutInit(&argc, argv); // INIT GLUT 
	auto LastTime = std::chrono::steady_clock::now(); // better timer than LABs -PC
	 
	while (true)
	{
		auto CurrentTime = std::chrono::steady_clock::now();
		ElapsedDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastTime);
		LastTime = CurrentTime;
		GLUTRenderer(ElapsedDeltaTime); // This in a similar form - although not the same as LAB`s hence the Param. -PC
	}
	// Render on shapes graphComp
	return 0;
}
