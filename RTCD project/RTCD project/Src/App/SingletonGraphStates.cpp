#include "SingletonGraphStates.h"



SingletonGraphStates& SingletonGraphStates::instance()
{
	static SingletonGraphStates _self;
	return _self;
}

/// and Yes I do understand how utterly stupid it is to create 12 variables, which take the value of 4, why not use just 4 you ask? -PC
/// because its about imitating what a real renderer might do using flyweight and singleton in GLUT and with minimal time.
/// The principles applied here show that if I wanted to change the outputs to something more than just one of 4 vec3`s thats possible and it would operate in the big picture
/// in the same way, this was done as a first practice - and to conform to constraints of the course... IF I could have taken this further I would.
/// could I have done this better, no doubt, but time is a luxury I did not have.
void SingletonGraphStates::initialise() 
{
	TriangleDefault = green; // green
	TriangleTriangle = black; // black 
	TriangleCircle = red; // red
	TriangleSquare = blue; // blue

	CircleDefault = red; // red
	CircleCircle = black; // black
	CircleTriangle = green; // green
	CircleSquare = blue; // blue

	SquareDefault = blue; // blue
	SquareCircle = red; // red
	SquareTriangle = green; // green
	SquareSquare = black; // black
}

SingletonGraphStates::SingletonGraphStates()
{
}


SingletonGraphStates::~SingletonGraphStates()
{
}

glm::vec3 SingletonGraphStates::getCircleDefault()
{
	return CircleDefault;
}

glm::vec3 SingletonGraphStates::getCircleCircle()
{
	return CircleCircle;
}

glm::vec3 SingletonGraphStates::getCircleTriangle()
{
	return CircleTriangle;
}

glm::vec3 SingletonGraphStates::getCircleSquare()
{
	return CircleSquare;
}

glm::vec3 SingletonGraphStates::getTriangleDefault()
{
	return TriangleDefault;
}

glm::vec3 SingletonGraphStates::getTriangleCircle()
{
	return TriangleCircle;
}

glm::vec3 SingletonGraphStates::getTriangleTriangle()
{
	return TriangleTriangle;
}

glm::vec3 SingletonGraphStates::getTriangleSquare()
{
	return TriangleSquare;
}

glm::vec3 SingletonGraphStates::getSquareDefault()
{
	return SquareDefault;
}

glm::vec3 SingletonGraphStates::getSquareCircle()
{
	return SquareCircle;
}

glm::vec3 SingletonGraphStates::getSquareTriangle()
{
	return SquareTriangle;
}

glm::vec3 SingletonGraphStates::getSquareSquare()
{
	return SquareSquare;
}
