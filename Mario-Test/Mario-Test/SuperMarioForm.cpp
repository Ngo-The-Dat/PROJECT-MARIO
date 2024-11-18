#include "SuperMarioForm.h"
#include "SmallMarioForm.h"
#include "FireMarioForm.h"
#include "Mario.h"

void SuperMarioForm::Enter(Mario& mario)
{
    //change the attributes to suit with the form
    mario.setTextureRect(sf::IntRect(0, 0, 16, 32));
    mario.setTexture(Resources::textures["super_mario"]);
}

void SuperMarioForm::handleInput(Mario& mario, float deltaTime)
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

void SuperMarioForm::Update(Mario& mario, float deltaTime)
{
    //animation or sth
    handleInput(mario, deltaTime);
}

void SuperMarioForm::Exit(Mario& mario)
{
    //change to another form
}

void SuperMarioForm::handleCollisionWithMushroom(Mario& mario)
{
}

void SuperMarioForm::handleCollisionWithFlower(Mario& mario)
{
    mario.setCurrenForm(std::make_shared<FireMarioForm>());
}


