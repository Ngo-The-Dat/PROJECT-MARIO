#include "PiranhaPlant.h"

PiranhaPlant::PiranhaPlant(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity) :
	Enemy(position, velocity, maxVelocity)
{
	setTextureRect(sf::IntRect(0, 0, 16, 16));
	setTexture(Resources::textures["small_mario01"]);
	this->setPosition(position);
	this->setHitBox(sf::FloatRect(sf::Vector2f(position), sf::Vector2f(16.0f, 16.0f)));
}

void PiranhaPlant::updatePosition(float deltaTime)
{
	if (m_timer.getElapsedTime().asSeconds() >= 2.0f)
	{
		m_currentVelocity.y = -m_currentVelocity.y;
		m_timer.restart();
	}
	sf::Vector2f newPosition = getPosition() + m_currentVelocity * deltaTime;
	setPosition(newPosition);
	if (m_isAlive)
		setHitBox(sf::FloatRect(sf::Vector2f(newPosition), sf::Vector2f(16.0f, 16.0f)));
}

void PiranhaPlant::handleCollisionWithBlock(sf::FloatRect blockBounds)
{
	// do nothing
}

void PiranhaPlant::handleCollisionWithEnemy(Enemy& enemy)
{
	// do nothing
}

