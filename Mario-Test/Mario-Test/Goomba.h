#pragma once
#include "Enemy.h"
class Goomba :
    public Enemy
{
public:
    Goomba(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f maxVelocity);
private:
};

