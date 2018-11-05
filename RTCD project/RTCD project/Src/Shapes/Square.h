#pragma once
#include "Shape.h"
#include "SquareGraphComp.h"
#include "SquarePhysicsComp.h"
#include <memory>

class Square :
	public Shape

{
private:

	std::unique_ptr<SquareGraphComp> graphicComp;
	std::unique_ptr<SquarePhysicsComp> physicsComp;

	bool inUse = false;

public:
	Square();
	virtual ~Square();

	void Update(std::chrono::milliseconds ElapsedDeltaTime) override;

	void Render(std::chrono::milliseconds ElapsedDeltaTime) override;

	bool InUse() override;

	glm::vec2 GetDirection() override;

	glm::vec2 GetPoistion() override;

	glm::vec2 SetPositon(glm::vec2 NewPosition) override;

	glm::vec2 SetDirection(glm::vec2 NewDirection) override;
};

