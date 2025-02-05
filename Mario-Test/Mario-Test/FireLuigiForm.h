#pragma once
#include "LuigiForm.h"
class FireLuigiForm :
    public LuigiForm
{
public:
	void Enter(Luigi& luigi) override;
	void handleInput(Luigi& luigi, float deltaTime) override;
	void Update(Luigi& luigi, float deltaTime) override;
	void Exit(Luigi& luigi) override;

	//handle collision

	void handleCollisionWithMushroom(Luigi& luigi) override;
	void handleCollisionWithFlower(Luigi& luigi) override;
};

