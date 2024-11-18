#include "Star.h"

Star::Star(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, sf::Vector2f maxVelocity):
    Item(position, velocity, acceleration, maxVelocity)
{
    this->setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->setTexture(Resources::textures["star"]);
}

void Star::jump()
{
    if (m_isOnGround) {
        m_isOnGround = false;
        m_currentVelocity.y = -(m_originVelocity.y + m_acceleration.y);
        if (m_currentVelocity.y > m_maxVelocity.y)
        {
            m_currentVelocity.y = m_maxVelocity.y;
        }
    }
}

// move right with acceleration
void Star::moveRight()
{
    m_currentVelocity.x += m_acceleration.x;
    if (m_currentVelocity.x > m_maxVelocity.x) {
        m_currentVelocity.x = m_maxVelocity.x;
    }

}

// move left with acceleration
void Star::moveLeft()
{
    m_currentVelocity.x -= m_acceleration.x;
    if (m_currentVelocity.x < -m_maxVelocity.x) {
        m_currentVelocity.x = -m_maxVelocity.x;
    }

}

void Star::handleCollisionWithGround(sf::FloatRect blockBounds)
{
    sf::FloatRect itemBounds = this->getGlobalBounds();
    float overlapX = itemBounds.left < blockBounds.left
        ? itemBounds.left + itemBounds.width - blockBounds.left
        : blockBounds.left + blockBounds.width - itemBounds.left;

    float overlapY = itemBounds.top < blockBounds.top
        ? itemBounds.top + itemBounds.height - blockBounds.top
        : blockBounds.top + blockBounds.height - itemBounds.top;

    if (overlapY < 0) overlapY = 0;
    if (overlapY < 0) overlapY = 0;

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
            //std::cout << overlapX << " " << overlapY << "\n";
        }
        else {
            if (!this->isMovingUp()) {
                this->move(0, -overlapY); // move item up
                this->setOnGround();
                this->jump();
            }
            else if (this->isMovingUp()) {
                this->move(0, overlapY); // move item down
            }
        }

    }


}

