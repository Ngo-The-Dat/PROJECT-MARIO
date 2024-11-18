#pragma once
#include "MarioForm.h"
class FireMarioForm :
    public MarioForm
{
public:
	void Enter(Mario& mario) override;
	void handleInput(Mario& mario, float deltaTime) override;
	void Update(Mario& mario, float deltaTime) override;
	void Exit(Mario& mario) override;

	//handle collision

	void handleCollisionWithMushroom(Mario& mario) override;
	void handleCollisionWithFlower(Mario& mario) override;
};

