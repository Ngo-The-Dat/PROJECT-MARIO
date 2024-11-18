#pragma once
#include "Item.h"
#include "Player.h"

class Flower : public Item
{
public:
	Flower(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity);

private:
};
