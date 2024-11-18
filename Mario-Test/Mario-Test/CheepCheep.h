#pragma once
#include "Enemy.h"
class CheepCheep :
	public Enemy
{
public:
	CheepCheep(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);
	void updatePosition(float deltaTime) override;
	void handleCollisionWithBlock(sf::FloatRect blockBounds) override;
	void handleCollisionWithEnemy(Enemy& enemy) override;
};

