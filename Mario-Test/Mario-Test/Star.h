#pragma once
#include "Item.h"
#include "Player.h"
class Star : public Item
{
public:
	Star(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f m_acceleration, sf::Vector2f m_maxVelocity);

	// update movement
	void jump();
	void moveRight();
	void moveLeft();
	/*void changeVerticalDirection();*/

	// handle collision
	void handleCollisionWithGround(sf::FloatRect blockBounds) override;
private:
};

