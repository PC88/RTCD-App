#pragma once

class GameWindow;

class ApplicationManager
{
public:
	ApplicationManager();
	virtual ~ApplicationManager();

	void ReshapeWindow(int width, int height);

private:

	std::shared_ptr<GameWindow> m_window;
};

