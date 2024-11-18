#pragma once
#include "Item.h"
#include "Resources.h"

class Mushroom : public Item
{
public:
	Mushroom(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity);
	//void handleCollisionWithPlayer();
	//void Update(float deltaTime);

	//// setter
	//void setOnGround();
	//void setInAir();

	//// update position
	//void updatePosition(float deltaTime);
	//void applyGravity(float deltaTime);

	//// check state
	//bool isMovingRight();
	//bool isMovingUp();
	//void stopMovingVertical();
	//// handle collision
	//void handleCollisionWithGround(sf::FloatRect blockBounds);

private:
};

