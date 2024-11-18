#pragma once
#include "Entity.h"

class Item : public Entity
{
public:
	Item(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity);

	virtual void handleCollisionWithPlayer();
	virtual void Update(float deltaTime);

	// setter
	virtual void setOnGround();
	virtual void setInAir();

	// update position
	virtual void updatePosition(float deltaTime);
	virtual void applyGravity(float deltaTime);

	// check state
	virtual bool isMovingRight();
	virtual bool isMovingUp();
	virtual void stopMovingVertical();
	// handle collision
	virtual void handleCollisionWithGround(sf::FloatRect blockBounds);
protected:
	sf::Vector2f m_currentVelocity;
	sf::Vector2f m_originVelocity;
	sf::Vector2f m_maxVelocity;
	sf::Vector2f m_acceleration;
	bool m_isPicked;
	bool m_isOnGround;
	bool m_isChangeDirection;
};

