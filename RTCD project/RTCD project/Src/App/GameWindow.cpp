#include "GameWindow.h"
#include "glut/include/glut.h"



GameWindow::GameWindow(char* title, int width, int height, int posX, int posY) :width(width), height(height)
{
	glutInitDisplayMode(GLUT_DOUBLE);	// Enable double buffered mode
	glutInitWindowSize(width, height);	// Initial window width and height
	glutInitWindowPosition(posX, posY); // Initial window top-left corner (x, y)
	glutCreateWindow(title);			// Create window with given title
}


GameWindow::~GameWindow()
{
}

void GameWindow::Reshape(GLsizei width, GLsizei height) 
{
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else {
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

int GameWindow::getWidth()
{
	return width;
}

int GameWindow::getHeight()
{
	return height;
}