#pragma once
#include <glm\glm.hpp>
#include<glm\gtc\matrix_access.hpp>

using namespace glm;

class Transform
{
private:
	mat3 transformMatrix;

public:
	Transform();
	virtual ~Transform() {}

	void Translate(vec2& translation);
	void Scale(vec2& scaling);
	void Rotate(float angle);

	vec2 getPosition();
	vec2 getScale();
	vec2 getOrientation();
	vec2 getUpDir();
	vec2 getLeftDir();

	mat3 localToWorldMatrix();
	mat3 worldToLocalMatrix();
};