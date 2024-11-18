#pragma once
#include "Enemy.h"
class Koopa :
    public Enemy
{
public:
    Koopa(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);
    void handleCollisionWithPlayer(Player& player) override;
    void Update(float deltaTime);
    bool isBouncing() const;

private:
    enum class State
    {
        Walking,
        InShell,
        Bouncing
    };

    State m_state;
    bool m_inShell;
    bool m_isBouncing;
    sf::Clock m_shellTimer;
    bool m_timerStarted;
    sf::Vector2f m_previousVelocity;
};

