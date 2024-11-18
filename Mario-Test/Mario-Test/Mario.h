#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Camera.h"
#include "Renderer.h"
#include "Map.h"
#include "Entity.h"
#include "SmallMarioForm.h"
#include "SuperMarioForm.h"
#include "FireMarioForm.h"

class Mario : public Player
{
public:
	Mario(sf::Vector2f position, sf::Vector2f velocity,
		sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity);
	~Mario();

	void handleCollisionWithMushroom() override;
	void handleCollisionWithFlower() override;
	void handleCollisionWithStar() override;
	void handleCollisionWithCoin() override;

private:
	

};

