#pragma once
#include "glut/include/glut.h"

class GameWindow
{
public:
	virtual ~GameWindow();

	GameWindow(char* title, int width, int height, int posX, int posY) :width(width), height(height)
	{
		glutInitDisplayMode(GLUT_DOUBLE);	// Enable double buffered mode
		glutInitWindowSize(width, height);	// Initial window width and height
		glutInitWindowPosition(posX, posY); // Initial window top-left corner (x, y)
		glutCreateWindow(title);			// Create window with given title
	}

	void Reshape(int width, int height);
	int getWidth();
	int getHeight();
private:
	// Projection clipping area
	double clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;
	int width, height;
};

