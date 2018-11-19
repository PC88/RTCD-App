#pragma once
#include "glm\vec3.hpp"
class SingletonGraphStates
{
public:
	static SingletonGraphStates& instance();

	void initialise();

public:
	SingletonGraphStates(SingletonGraphStates const&) = delete;
	void operator=(SingletonGraphStates const&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
		//       C++ book, that deleted functions should generally
		//       be public as it results in better error messages
		//       due to the compilers behavior to check accessibility
		//       before deleted status
	    //       this probably wont matter here but dose not hurt

	glm::vec3 getCircleDefault();
	glm::vec3 getCircleCircle();
	glm::vec3 getCircleTriangle();
	glm::vec3 getCircleSquare();

	glm::vec3 getTriangleDefault();
	glm::vec3 getTriangleCircle();
	glm::vec3 getTriangleTriangle();
	glm::vec3 getTriangleSquare();

	glm::vec3 getSquareDefault();
	glm::vec3 getSquareCircle();
	glm::vec3 getSquareTriangle();
	glm::vec3 getSquareSquare();


private:
	glm::vec3 TriangleDefault;
	glm::vec3 TriangleTriangle;
	glm::vec3 TriangleCircle;
	glm::vec3 TriangleSquare;

	glm::vec3 CircleDefault;
	glm::vec3 CircleCircle;
	glm::vec3 CircleTriangle;
	glm::vec3 CircleSquare;

	glm::vec3 SquareDefault;
	glm::vec3 SquareCircle;
	glm::vec3 SquareTriangle;
	glm::vec3 SquareSquare;

	glm::vec3 red {1.0f,0.0f,0.0f};
	glm::vec3 blue {0.0f,0.0f,1.0f};
	glm::vec3 green{0.0f,1.0f,0.0f};
	glm::vec3 black{0.0f,0.0f,0.0f};



	SingletonGraphStates();
	virtual ~SingletonGraphStates();
};

