#include "Koopa.h"
#include <iostream>
Koopa::Koopa(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity) :
    Enemy(position, velocity, maxVelocity),
    m_state(State::Walking),
    m_inShell(false),
    m_isBouncing(false),
    m_timerStarted(false),
    m_previousVelocity(velocity)
{
    setTextureRect(sf::IntRect(0, 0, 16, 16));
    setTexture(Resources::textures["small_mario01"]);
    this->setPosition(position);
    this->setHitBox(sf::FloatRect(sf::Vector2f(position), sf::Vector2f(16.0f, 16.0f)));
}

void Koopa::handleCollisionWithPlayer(Player& player)
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect koopaBounds = this->getHitBox();
    const float buffer = 5.0f; // Small buffer to account for minor overlaps
    bool playerIsAbove = (playerBounds.top + playerBounds.height) <= (koopaBounds.top + buffer);
    if (playerIsAbove && !player.isMovingUp())
    {
        switch (m_state)
        {
        case State::Walking:
            m_state = State::InShell;
            m_inShell = true;
            m_isBouncing = false;
            m_timerStarted = true;
            m_shellTimer.restart();
            m_previousVelocity = m_currentVelocity;
            stopMovingHorizontal();
            break;

        case State::InShell:
            m_state = State::Bouncing;
            m_timerStarted = false;
            m_isBouncing = true;
            if (playerBounds.left + playerBounds.width < koopaBounds.left + koopaBounds.width / 2)
                m_currentVelocity.x = m_maxVelocity.x + 100.0f;
            else
                m_currentVelocity.x = -(m_maxVelocity.x + 100.0f);
            break;

        case State::Bouncing:
            m_state = State::Walking;
            m_inShell = false;
            m_isBouncing = false;
            m_timerStarted = false;
            m_currentVelocity = m_previousVelocity;
            break;
        }
    }
}

void Koopa::Update(float deltaTime)
{
    if (m_inShell && m_timerStarted)
    {
        if (m_shellTimer.getElapsedTime().asSeconds() >= 3.0f)
        {
            m_state = State::Walking;
            m_inShell = false;
            m_timerStarted = false;
            // Change Koopa's appearance back to walking state
            m_currentVelocity = m_previousVelocity; // restore previous velocity
        }
    }

    // Call the base class update method to handle movement and other updates
    Enemy::updatePosition(deltaTime);
}

bool Koopa::isBouncing() const
{
    return m_isBouncing;
}

