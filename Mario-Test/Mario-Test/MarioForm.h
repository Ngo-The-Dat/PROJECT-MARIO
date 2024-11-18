#pragma once
#include "PlayerForm.h"
class Mario;

class MarioForm : public PlayerForm
{
public:
	virtual void Enter(Mario& mario);
	virtual void handleInput(Mario& mario, float deltaTime);
	virtual void Update(Mario& mario, float deltaTime);
	virtual void Exit(Mario& mario);

	//handle collision
	//virtual void handleCollisionWithGround(sf::FloatRect blockBounds, Mario& Mario);
	virtual void handleCollisionWithItem(Mario& mario, Item& item);
	virtual void handleCollisionWithMushroom(Mario& mario);
	virtual void handleCollisionWithFlower(Mario& mario);
	virtual void handleCollisionWithStar(Mario& mario);
	virtual void handleCollisionWithCoin(Mario& mario);
};

