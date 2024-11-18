#pragma once
#include "Enemy.h"
class PiranhaPlant :
    public Enemy
{
public:
    PiranhaPlant(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);
    void updatePosition(float deltaTime);
    //no hanlde collision with block
    void handleCollisionWithBlock(sf::FloatRect blockBounds) override;
    void handleCollisionWithEnemy(Enemy& enemy) override;
private:
    sf::Clock m_timer;
};

