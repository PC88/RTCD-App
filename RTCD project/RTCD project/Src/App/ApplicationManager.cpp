#include "ApplicationManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" // Perhaps how we get the transform Matrix in to main application to be passed around.
#include "glut/include/glut.h" // Glut include
#include <memory>
#include "ObjectPool/ShapePool.h"
#include <time.h>
#include <chrono>
#include <iostream>





ApplicationManager::ApplicationManager()
{
	// initialize shape pool - PC
}



ApplicationManager::~ApplicationManager()
{
}


void ApplicationManager::Initialise()
{
	window = std::make_shared<GameWindow>("RTCD First Build", 640, 450, 50,50); // these args may be wrong - PC
}


int main(int argc, char** argv) // might not need these args - PC
{
	// iterate through the object pool and update and call Update(), Render(), and Collide() on all shape composite objects, graphics and physics respectivley. - PC
	std::unique_ptr <ApplicationManager> AppManager = std::make_unique<ApplicationManager>();

	AppManager->Initialise();

	glutInit(&argc, argv); // INIT GLUT 
	auto LastTime = std::chrono::steady_clock::now(); // better timer than LABs -PC
	std::chrono::milliseconds ElapsedDeltaTime;
	 
	while (true)
	{
		auto CurrentTime = std::chrono::steady_clock::now();
		ElapsedDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastTime);
		LastTime = CurrentTime;
		// Update on shapes physicsComp
	}
	// Render on shapes graphComp
	return 0;
}
