#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f position, sf::Vector2f velocity,
    sf::Vector2f acceleration, sf::Vector2f deceleration, sf::Vector2f maxVelocity)
    : Entity(position),
    m_currentVelocity(sf::Vector2f(0.0f, velocity.y)),
    m_originVelocity(velocity),
    m_acceleration(acceleration),
    m_deceleration(deceleration),
    m_maxVelocity(maxVelocity),
    m_canMove(true),
    m_isOnGround(false),
    m_isImmortal(false),
    m_playerState(PlayerState::idle),
    m_isChangeDirection(false)
{
    this->setPosition(position);
    m_currentForm = std::make_unique<SmallPlayerForm>();
    m_currentForm->Enter(*this);
}

Player::~Player()
{
}

void Player::setOnGround(bool isOnGround)
{
    m_isOnGround = isOnGround;
}

void Player::setCurrenForm(std::shared_ptr<PlayerForm> newForm)
{
    m_currentForm = newForm;
    m_currentForm->Enter(*this);
}

void Player::setState(PlayerState playerState)
{
    m_playerState = playerState;
}

void Player::setImmortal(bool isImmortal)
{
    m_isImmortal = isImmortal;
}

void Player::setRunningIfOnGround()
{
    if (m_isOnGround)
        m_playerState = PlayerState::running;
}

void Player::setChangeDirection(sf::Keyboard::Key& input)
{
    m_isChangeDirection = false;
    if (!m_isOnGround)
        return;
    if ((input == sf::Keyboard::Right && m_currentVelocity.x < 0) ||
        (input == sf::Keyboard::Left && m_currentVelocity.x > 0))
        m_isChangeDirection = true;
}

void Player::Update(float deltaTime)
{
    m_currentForm->Update(*this, deltaTime);
}


void Player::Draw(Renderer& renderer)
{
    renderer.getRenderTarget().draw(*this);
}


void Player::jump(sf::Vector2f addedVelocity)
{
    float addedVelocityY = addedVelocity.y;
    if (m_isOnGround) {
        m_isOnGround = false;
        m_currentVelocity.y = -(m_originVelocity.y + addedVelocityY + m_acceleration.y);
        if (m_currentVelocity.y > m_maxVelocity.y)
        {
            m_currentVelocity.y = m_maxVelocity.y;
        }
    }
}

// move right with added velocity with acceleration for smooth(added velocity is intended for buffs)
void Player::moveRight(sf::Vector2f addedVelocity)
{
    m_currentVelocity.x += m_acceleration.x;  
    if (m_currentVelocity.x > m_maxVelocity.x) {
        m_currentVelocity.x = m_maxVelocity.x;  
    }
    
}

// move left with added velocity with acceleration for smooth(added velocity is intended for buffs)
void Player::moveLeft(sf::Vector2f addedVelocity)
{
    m_currentVelocity.x -= m_acceleration.x;  
    if (m_currentVelocity.x < -m_maxVelocity.x) {
        m_currentVelocity.x = -m_maxVelocity.x;  
    }
    
}

// apply deceleration for smooth movement
void Player::applyDeceleration(float deltaTime)
{
    if (m_currentVelocity.x > 0) {
        m_currentVelocity.x -= m_deceleration.x * deltaTime;  
        if (m_currentVelocity.x < 0) {
            m_currentVelocity.x = 0;  
        }
    }
    else if (m_currentVelocity.x < 0) {
        m_currentVelocity.x += m_deceleration.x * deltaTime;  
        if (m_currentVelocity.x > 0) {
            m_currentVelocity.x = 0; 
        }
    }

    if (m_currentVelocity.y < 0) {
        m_currentVelocity.y += m_deceleration.y * deltaTime;
        if (m_currentVelocity.y > 0) {
            m_currentVelocity.y = 0;
        }
    }
}

void Player::stopMovingHorizontal()
{
    m_currentVelocity.x = 0;
}

void Player::stopMovingVertical()
{
    m_currentVelocity.y = 0;
}


void Player::applyGravity(float deltaTime)
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

void Player::updatePosition(float deltaTime)
{
    sf::Vector2f newPosition = getPosition() + m_currentVelocity * deltaTime;
    setPosition(newPosition);
}

bool Player::isOnGround()
{
    return m_isOnGround;
}

bool Player::isMovingRight()
{
    return (m_currentVelocity.x > 0);
}

bool Player::isMovingUp()
{
    return (m_currentVelocity.y < 0);
}

bool Player::isStopped()
{
    return (m_currentVelocity == sf::Vector2f(0.0f, 0.0f));
}

bool Player::isAlive()
{
    return true;
}

bool Player::isImmortal()
{
    return m_isImmortal;
}

bool Player::isSuper()
{
    return m_currentForm->isSuperForm();
}

bool Player::isFire()
{
    return m_currentForm->isFireForm();
}


// make sure player can move correctly
void Player::handleCollisionWithGround(sf::FloatRect blockBounds)
{
    if (m_currentForm)
        m_currentForm->handleCollisionWithGround(blockBounds, *this);
}

void Player::handleCollisionWithItem(Item& item)
{
    if (m_currentForm)
    {
        m_currentForm->handleCollisionWithItem(*this, item);
    }
}

void Player::handleCollisionWithMushroom()
{
    if (m_currentForm)
    {
        m_currentForm->handleCollisionWithMushroom(*this);
    }
}

void Player::handleCollisionWithFlower()
{
    if (m_currentForm)
    {
        m_currentForm->handleCollisionWithFlower(*this);
    }
}

void Player::handleCollisionWithStar()
{
    if (m_currentForm)
    {
        m_currentForm->handleCollisionWithStar(*this);
    }
}

void Player::handleCollisionWithCoin()
{
    if (m_currentForm)
    {
        m_currentForm->handleCollisionWithCoin(*this);
    }
}

void Player::handleCollisionWithBlock()
{
}

