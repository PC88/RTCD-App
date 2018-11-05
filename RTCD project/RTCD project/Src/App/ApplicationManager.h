#pragma once

class GameWindow;

class ApplicationManager
{
public:
	ApplicationManager();
	virtual ~ApplicationManager();

	void Initialise();

private:

	std::shared_ptr<GameWindow> window;
};

