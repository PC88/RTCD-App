#pragma once
class GraphicsComp
{
public:
	GraphicsComp();
	virtual ~GraphicsComp();

	virtual void Render() = 0; // render function which will be called on all of our shapes, and changed on each shape respectively -PC
};

