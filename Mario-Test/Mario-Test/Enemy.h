#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Resources.h"
#include "Player.h"

// version of Enemy which leverage built-in features, have the same interface,
// callable by window.draw()
class Enemy : public Entity
{
public:
    Enemy(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);

    // set on ground
    void setOnGround(bool isOnGround);

    // update
    virtual void Update(float deltaTime);
    void die();

    // update movement
    void moveLeft(sf::Vector2f addedVelocity);
    void moveRight(sf::Vector2f addedVelocity);
    void moveUp(sf::Vector2f addedVelocity);
    void moveDown(sf::Vector2f addedVelocity);
    void jump(sf::Vector2f addedVelocity);
    void stopMovingHorizontal();
    void stopMovingVertical();
    void applyGravity(float deltaTime);

    // update position
    virtual void updatePosition(float deltaTime);

    // check state 
    bool isOnGround();
    bool isMovingRight();
    bool isMovingUp();
    bool isStopped();
    bool isAlive();

    // handle collision
    virtual void handleCollisionWithBlock(sf::FloatRect blockBounds);
    virtual void handleCollisionWithPlayer(Player& player);
    virtual void handleCollisionWithEnemy(Enemy& enemy);
protected:
    sf::Vector2f m_maxVelocity;
    sf::Vector2f m_currentVelocity;
    bool m_isAlive;
    bool m_isOnGround;
};