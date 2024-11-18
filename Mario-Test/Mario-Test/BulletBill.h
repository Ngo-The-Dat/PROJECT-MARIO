#pragma once
#include "Enemy.h"
class BulletBill :
	public Enemy
{
public:
	BulletBill(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);
	void updatePosition(float deltaTime);
	//no hanlde collision with block
	void handleCollisionWithBlock(sf::FloatRect blockBounds);
	void handleCollisionWithEnemy(Enemy& enemy) override;
};

