#pragma once
#include <memory>
#include "Entity.h"
#include "PlayerForm.h"
#include "SmallPlayerForm.h"
#include "Map.h"
#include "Item.h"
#include "Mushroom.h"
#include "Flower.h"
#include "Star.h"
#include "Coin.h"
#include "Renderer.h"

enum class PlayerState {
	idle,
	crouch,
	jumping,
	running,
	swimming,
	dead
};

class Player : public Entity
{
protected:
	std::shared_ptr<PlayerForm> m_currentForm;
	PlayerState m_playerState;
	sf::Vector2f m_currentVelocity;
	sf::Vector2f m_originVelocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_deceleration;
	sf::Vector2f m_maxVelocity;
	bool m_canMove;
	bool m_isOnGround;
	bool m_isImmortal;
	bool m_isChangeDirection;
public:
	Player(sf::Vector2f position, sf::Vector2f velocity,
		sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity);
	virtual ~Player();

	//setter
	void setOnGround(bool isOnGround);
	void setCurrenForm(std::shared_ptr<PlayerForm> newForm);
	void setState(PlayerState playerState);
	void setImmortal(bool isImmortal);
	void setRunningIfOnGround();
	void setChangeDirection(sf::Keyboard::Key& input);

	// update player
	void Update(float deltaTime);
	void Draw(Renderer& renderer);

	// update all movement
	virtual void moveRight(sf::Vector2f addedVelocity);
	virtual void moveLeft(sf::Vector2f addedVelocity);
	virtual void jump(sf::Vector2f addedVelocity);
	virtual void applyDeceleration(float deltaTime);
	virtual void stopMovingHorizontal();
	virtual void stopMovingVertical();
	virtual void applyGravity(float deltaTime);

	//update position
	virtual void updatePosition(float deltaTime);

	// check state
	bool isOnGround();
	bool isMovingRight();
	bool isMovingUp();
	bool isStopped();
	bool isAlive();
	bool isImmortal();
	bool isSuper();
	bool isFire();

	// handle collision 
	virtual void handleCollisionWithGround(sf::FloatRect blockBounds);
	// collision with item
	virtual void handleCollisionWithItem(Item& item);
	virtual void handleCollisionWithMushroom();
	virtual void handleCollisionWithFlower();
	virtual void handleCollisionWithStar();
	virtual void handleCollisionWithCoin();

	// collision with block
	virtual void handleCollisionWithBlock();

};


