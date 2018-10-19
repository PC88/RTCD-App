#pragma once
 class Shape
{
public:
	Shape();
	virtual ~Shape();

	// Transform need to go in here - PC

	virtual void Update() = 0;

	virtual void Render() = 0;

	virtual bool InUse() = 0;
};

