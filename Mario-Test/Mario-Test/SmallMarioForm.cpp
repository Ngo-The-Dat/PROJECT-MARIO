#include "SmallMarioForm.h"
#include "SuperMarioForm.h"
#include "Mario.h"
#include <iostream>

void SmallMarioForm::Enter(Mario& mario)
{
    
    //change the attributes to suit with the form
    mario.setTextureRect(sf::IntRect(0, 0, 16, 16));
    mario.setTexture(Resources::textures["small_mario01"]);
}

void SmallMarioForm::handleInput(Mario& mario, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(0.0f, 0.0f);
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

void SmallMarioForm::Update(Mario& mario, float deltaTime)
{
    //animation or sth
    handleInput(mario, deltaTime);
}

void SmallMarioForm::Exit(Mario& Mario)
{
    //change to another form
}

void SmallMarioForm::handleCollisionWithMushroom(Mario& mario)
{
    mario.setCurrenForm(std::make_shared<SuperMarioForm>());
}

void SmallMarioForm::handleCollisionWithFlower(Mario& mario)
{
    mario.setImmortal(true);
}
