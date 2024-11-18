#include "Mario.h"
#include <iostream>

// bug mismatch player form and mario form 
Mario::Mario(sf::Vector2f position, sf::Vector2f velocity,
    sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity)
    : Player(position, velocity, acceleration, deceleration, maxVelocity) {
    
}

Mario::~Mario() {
}

void Mario::handleCollisionWithMushroom()
{
}

void Mario::handleCollisionWithFlower()
{
}

void Mario::handleCollisionWithStar()
{
}

void Mario::handleCollisionWithCoin()
{
}

