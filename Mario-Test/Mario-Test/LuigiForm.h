#pragma once
#include "PlayerForm.h"
class Luigi;

class LuigiForm : public PlayerForm
{
public:
	virtual void Enter(Luigi& luigi);
	virtual void handleInput(Luigi& luigi, float deltaTime);
	virtual void Update(Luigi& luigi, float deltaTime);
	virtual void Exit(Luigi& luigi);

	//handle collision
	//virtual void handleCollisionWithGround(sf::FloatRect blockBounds, Luigi& Luigi);
	virtual void handleCollisionWithItem(Luigi& luigi, Item& item);
	virtual void handleCollisionWithMushroom(Luigi& luigi);
	virtual void handleCollisionWithFlower(Luigi& luigi);
	virtual void handleCollisionWithStar(Luigi& luigi);
	virtual void handleCollisionWithCoin(Luigi& luigi);
};

