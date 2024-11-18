#include "Luigi.h"

Luigi::Luigi(sf::Vector2f position, sf::Vector2f velocity,
    sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity)
    : Player(position, velocity, acceleration, deceleration, maxVelocity) {

    m_currentForm = std::make_unique<SmallLuigiForm>();
    m_currentForm->Enter(*this);
}

Luigi::~Luigi() {
}

void Luigi::handleCollisionWithMushroom()
{
}

void Luigi::handleCollisionWithFlower()
{
}

void Luigi::handleCollisionWithStar()
{
}

void Luigi::handleCollisionWithCoin()
{
}

