#pragma once
#include <memory>

class GameWindow;
//class int; // I am not happy with this as I see it as a typedef for int but it dose not function like the LAB code, which converts "ints" primitives to it - PC

class ApplicationManager
{
public:
	ApplicationManager();
	virtual ~ApplicationManager();

	void ReshapeWindow(int width, int height);

private:

	std::shared_ptr<GameWindow> m_window;
};

