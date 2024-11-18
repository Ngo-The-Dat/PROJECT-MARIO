#include "BulletBill.h"
#include <iostream>

BulletBill::BulletBill(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity) :
	Enemy(position, velocity, maxVelocity)
{
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setTexture(Resources::textures["small_mario01"]);
	this->setPosition(position);
	this->setHitBox(sf::FloatRect(sf::Vector2f(position), sf::Vector2f(16.0f, 16.0f)));
}


void BulletBill::updatePosition(float deltaTime)
{
	sf::Vector2f newPosition = getPosition() + m_currentVelocity * deltaTime;
	setPosition(newPosition);
	if (m_isAlive)
		setHitBox(sf::FloatRect(sf::Vector2f(newPosition), sf::Vector2f(16.0f, 16.0f)));
}

void BulletBill::handleCollisionWithBlock(sf::FloatRect blockBounds)
{
	// Do nothing
}

void BulletBill::handleCollisionWithEnemy(Enemy& enemy)
{
	// Do nothing
}


