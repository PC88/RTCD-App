#pragma once

class GameWindow
{
public:
	virtual ~GameWindow();

	GameWindow(char* title, int width, int height, int posX, int posY);

	void Reshape(int width, int height);
	int getWidth();
	int getHeight();
private:
	// Projection clipping area
	double clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;
	int width, height;
};

