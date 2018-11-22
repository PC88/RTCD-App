#pragma once
#include "glm/vec2.hpp"
#include <memory>
#include <chrono>

class Transform;
enum TypeOfCreatedObject { circle, triangle, square }; // this is reflection meta data which will tell the event manager what type the super object is -PC
class Shape
{
public:
	Shape();
	virtual ~Shape();

	// Transform need to go in here - PC 

	virtual void Update(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) = 0;

	virtual bool InUse() = 0;

	virtual void Render(std::chrono::milliseconds ElapsedDeltaTime, int width, int height) = 0;

	virtual glm::vec2 GetDirection() = 0;

	virtual float GetDistanceMetric() = 0;

	virtual void OnCollide(int type) = 0;

	virtual glm::vec2 GetPosition() = 0; // returns position, but this will also be the centre by definition - see constructor -PC

	virtual int GetType() = 0; // this will be reflect the value of the Enum thus giving us the type without casting. -PC
private:

	glm::vec2 direction;

	glm::vec2 position;

protected:

	std::shared_ptr<Transform> ShapeTransform; // all shapes will have this TODO better way to do this than accessor function accessing an accessor function -PC

	
	TypeOfCreatedObject Creator;

};