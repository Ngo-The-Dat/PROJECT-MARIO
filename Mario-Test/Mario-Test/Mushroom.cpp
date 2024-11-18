#include "Mushroom.h"
#include <iostream>

Mushroom::Mushroom(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity): 
    Item(position, velocity, acceleration, maxVelocity)
{
	this->setTextureRect(sf::IntRect(0, 0, 16, 16));
	this->setTexture(Resources::textures["mushroom"]);
	this->setPosition(position);
}
