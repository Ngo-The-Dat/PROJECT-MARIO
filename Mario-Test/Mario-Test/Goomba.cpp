#include "Goomba.h"

Goomba::Goomba(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity): Enemy(position, velocity, maxVelocity)
{
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setTexture(Resources::textures["small_mario01"]);
	this->setPosition(position);
	this->setHitBox(sf::FloatRect(sf::Vector2f(position), sf::Vector2f(16.0f, 16.0f)));
}
