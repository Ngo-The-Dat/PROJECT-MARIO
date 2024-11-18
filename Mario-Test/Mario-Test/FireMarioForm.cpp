#include "FireMarioForm.h"
#include "SuperMarioForm.h"
#include "SmallMarioForm.h"
#include "Mario.h"

void FireMarioForm::Enter(Mario& mario)
{
    //change the attributes to suit with the form
    mario.setTextureRect(sf::IntRect(0, 0, 16, 32));
    mario.setTexture(Resources::textures["brick"]);
}

void FireMarioForm::handleInput(Mario& mario, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(5.0f, 5.0f);
    //handle keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mario.moveRight(addedVelocity);
        mario.setRunningIfOnGround();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mario.moveLeft(addedVelocity);
        mario.setRunningIfOnGround();
    }
    else {
        mario.setState(PlayerState::idle);
        mario.applyDeceleration(deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mario.isOnGround()) {
        mario.jump(addedVelocity);
        mario.setState(PlayerState::jumping);
    }

    mario.applyGravity(deltaTime);

    mario.updatePosition(deltaTime);
    mario.setOnGround(false);
}

void FireMarioForm::Update(Mario& mario, float deltaTime)
{
    //animation or sth
    handleInput(mario, deltaTime);
}

void FireMarioForm::Exit(Mario& mario)
{
    //change to another form
}

void FireMarioForm::handleCollisionWithMushroom(Mario& mario)
{
}

void FireMarioForm::handleCollisionWithFlower(Mario& mario)
{
    //increase 1000 points
}



