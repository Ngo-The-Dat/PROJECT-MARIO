#include "Item.h"
#include <iostream>

Item::Item(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity):
    m_currentVelocity(velocity),
    m_originVelocity(velocity),
    m_maxVelocity(maxVelocity),
    m_isPicked(false),
    m_isChangeDirection(false),
    m_isOnGround(false)
{
    this->setPosition(position);
}

void Item::handleCollisionWithPlayer()
{

}


void Item::Update(float deltaTime)
{
    this->updatePosition(deltaTime);
}

void Item::setOnGround()
{
    m_isOnGround = true;
}

void Item::setInAir()
{
    m_isOnGround = false;
}

void Item::updatePosition(float deltaTime)
{
    //m_currentVelocity.y = -m_velocity.y;
    /*if (!m_isOnGround)*/
    this->applyGravity(deltaTime);

    sf::Vector2f newPosition = getPosition() + m_currentVelocity * deltaTime;
    this->setPosition(newPosition);
}

void Item::applyGravity(float deltaTime)
{
    if (m_currentVelocity.y < m_maxVelocity.y)
        m_currentVelocity.y += 50.0f * deltaTime;
    else
        m_currentVelocity.y = m_maxVelocity.y;
}

bool Item::isMovingRight()
{
    return (m_currentVelocity.x > 0);
}

bool Item::isMovingUp()
{
    return (m_currentVelocity.y < 0);
}

void Item::stopMovingVertical()
{
    m_currentVelocity.y = 0;
}

// handle collision so that item move the other way when hit wall
void Item::handleCollisionWithGround(sf::FloatRect blockBounds)
{
    sf::FloatRect itemBounds = this->getGlobalBounds();
    float overlapX = itemBounds.left < blockBounds.left
        ? itemBounds.left + itemBounds.width - blockBounds.left
        : blockBounds.left + blockBounds.width - itemBounds.left;

    float overlapY = itemBounds.top < blockBounds.top
        ? itemBounds.top + itemBounds.height - blockBounds.top
        : blockBounds.top + blockBounds.height - itemBounds.top;

    overlapY = abs(overlapY);
    overlapX = abs(overlapX);

    // collision threshold: when a item nearly fits inside a cell, the overlapX will be tiny and can
    // be < overlapY (even when collision is not horizontal). That's why we need threshold to eliminate those cases.
    float diff = abs(overlapX - overlapY);
    const float collisionThreshold = 0.2f;
    // check when the difference between overlapX and overlapY is big enough to avoid miscalculation in float
    if (/*overlapX > collisionThreshold && overlapY > collisionThreshold*/ diff > collisionThreshold) {
        if (overlapX < overlapY) {
            if (this->isMovingRight()) {
                this->move(-overlapX, 0); // move item left
            }
            else if (!this->isMovingRight()) {
                this->move(overlapX, 0); // move item right
            }
            m_currentVelocity.x = -m_currentVelocity.x;
            
        }
        else {
            if (!this->isMovingUp()) {
                this->move(0, -overlapY); // move item up
                this->setOnGround();
            }
            else if (this->isMovingUp()) {
                this->move(0, overlapY); // move item down
            }
        }

    }

}