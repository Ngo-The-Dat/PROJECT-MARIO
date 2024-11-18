#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity) :
    Entity(position, velocity),
    m_currentVelocity(velocity),
    m_maxVelocity(maxVelocity),
    m_isAlive(true),
    m_isOnGround(false)
{
}

void Enemy::setOnGround(bool isOnGround)
{
    m_isOnGround = isOnGround;
}

void Enemy::Update(float deltaTime)
{
    this->updatePosition(deltaTime);
}

void Enemy::die()
{
    m_isAlive = false;
    setHitBox(sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f));
}




//moving
void Enemy::jump(sf::Vector2f addedVelocity)
{
    float addedVelocityY = addedVelocity.y;
    if (m_isOnGround) {
        m_isOnGround = false;
        m_currentVelocity.y = -(m_originVelocity.y + addedVelocityY);
        if (m_currentVelocity.y > m_maxVelocity.y)
        {
            m_currentVelocity.y = m_maxVelocity.y;
        }
    }
}
// move right with added velocity with acceleration for smooth(added velocity is intended for buffs)
void Enemy::moveRight(sf::Vector2f addedVelocity)
{
    m_currentVelocity.x += addedVelocity.x;
    if (m_currentVelocity.x > m_maxVelocity.x) {
        m_currentVelocity.x = m_maxVelocity.x;
    }

}
void Enemy::moveUp(sf::Vector2f addedVelocity)
{
    m_currentVelocity.y -= addedVelocity.y;
    if (m_currentVelocity.y < -m_maxVelocity.y) {
        m_currentVelocity.y = -m_maxVelocity.y;
    }
}
void Enemy::moveDown(sf::Vector2f addedVelocity)
{
    m_currentVelocity.y += addedVelocity.y;
    if (m_currentVelocity.y > m_maxVelocity.y) {
        m_currentVelocity.y = m_maxVelocity.y;
    }
}
// move left with added velocity with acceleration for smooth(added velocity is intended for buffs)
void Enemy::moveLeft(sf::Vector2f addedVelocity)
{
    m_currentVelocity.x -= addedVelocity.x;
    if (m_currentVelocity.x < -m_maxVelocity.x) {
        m_currentVelocity.x = -m_maxVelocity.x;
    }
}
void Enemy::stopMovingHorizontal()
{
    m_currentVelocity.x = 0;
}
void Enemy::stopMovingVertical()
{
    m_currentVelocity.y = 0;
}


void Enemy::applyGravity(float deltaTime)
{
    if (!m_isOnGround)
    {
        m_currentVelocity.y += 50.0f * deltaTime;

        if (m_currentVelocity.y > m_maxVelocity.y)
        {
            m_currentVelocity.y = m_maxVelocity.y;
        }
    }
}
void Enemy::updatePosition(float deltaTime)
{
    this->applyGravity(deltaTime);
    sf::Vector2f newPosition = getPosition() + m_currentVelocity * deltaTime;
    setPosition(newPosition);
    if (m_isAlive)
        setHitBox(sf::FloatRect(sf::Vector2f(newPosition), sf::Vector2f(16.0f, 16.0f)));
    //std::cout << "Bounds: " << this->getGlobalBounds().top << " " << this->getGlobalBounds().left << '\n';
}
bool Enemy::isOnGround()
{
    return m_isOnGround;
}
bool Enemy::isMovingRight()
{
    return (m_currentVelocity.x > 0);
}
bool Enemy::isMovingUp()
{
    return (m_currentVelocity.y < 0);
}
bool Enemy::isStopped()
{
    return (m_currentVelocity == sf::Vector2f(0.0f, 0.0f));
}
bool Enemy::isAlive()
{
    return m_isAlive;
}

void Enemy::handleCollisionWithBlock(sf::FloatRect blockBounds)
{
    sf::FloatRect enemyBounds = this->getGlobalBounds();
    float overlapX = enemyBounds.left < blockBounds.left
        ? enemyBounds.left + enemyBounds.width - blockBounds.left
        : blockBounds.left + blockBounds.width - enemyBounds.left;

    float overlapY = enemyBounds.top < blockBounds.top
        ? enemyBounds.top + enemyBounds.height - blockBounds.top
        : blockBounds.top + blockBounds.height - enemyBounds.top;

    overlapY = abs(overlapY);
    overlapX = abs(overlapX);

    // collision threshold: when a enemy nearly fits inside a cell, the overlapX will be tiny and can
    // be < overlapY (even when collision is not horizontal). That's why we need threshold to eliminate those cases.
    float diff = abs(overlapX - overlapY);
    const float collisionThreshold = 0.3f;

    // check when the difference between overlapX and overlapY is big enough to avoid miscalculation in float
    if (/*overlapX > collisionThreshold && overlapY > collisionThreshold*/ diff > collisionThreshold) {
        if (overlapX < overlapY) {
            if (this->isMovingRight()) {
                this->move(-overlapX, 0); // move enemy left
            }
            else if (!this->isMovingRight()) {
                this->move(overlapX, 0); // move enemy right
            }
            m_currentVelocity.x = -m_currentVelocity.x;

        }
        else {
            if (!this->isMovingUp()) {
                this->move(0, -overlapY); // move enemy up
                this->setOnGround(true);
            }
            else if (this->isMovingUp()) {
                this->move(0, overlapY); // move enemy down
            }
        }

    }
    //std::cout << "Bounds: " << this->getGlobalBounds().top << " " << this->getGlobalBounds().left << '\n';
}
void Enemy::handleCollisionWithPlayer(Player& player)
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect enemyBounds = this->getHitBox();
    const float buffer = 5.0f; // Small buffer to account for minor overlaps
    bool playerIsAbove = (playerBounds.top + playerBounds.height) <= (enemyBounds.top + buffer);
    if (playerIsAbove && !player.isMovingUp()) {
        this->die();
    }
}
void Enemy::handleCollisionWithEnemy(Enemy& enemy)
{
    sf::FloatRect enemy1Bounds = this->getHitBox();
    sf::FloatRect enemy2Bounds = enemy.getHitBox();

    float overlapX = enemy1Bounds.left < enemy2Bounds.left
        ? enemy1Bounds.left + enemy1Bounds.width - enemy2Bounds.left
        : enemy2Bounds.left + enemy2Bounds.width - enemy1Bounds.left;

    if (this->isMovingRight())
        this->move(-overlapX, 0);
    else
        this->move(overlapX, 0);
    m_currentVelocity.x = -m_currentVelocity.x;
}

