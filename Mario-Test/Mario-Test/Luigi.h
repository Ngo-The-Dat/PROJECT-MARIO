#pragma once
#include "Player.h"
#include "SmallLuigiForm.h"
#include "SuperLuigiForm.h"
#include "FireLuigiForm.h"

class Luigi :public Player
{
public:
	Luigi(sf::Vector2f position, sf::Vector2f velocity,
		sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity);
	~Luigi();

	void handleCollisionWithMushroom() override;
	void handleCollisionWithFlower() override;
	void handleCollisionWithStar() override;
	void handleCollisionWithCoin() override;

private:

};

