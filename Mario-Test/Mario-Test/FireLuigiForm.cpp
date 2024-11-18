#include "FireLuigiForm.h"
#include "SuperLuigiForm.h"
#include "SmallLuigiForm.h"
#include "Luigi.h"

void FireLuigiForm::Enter(Luigi& luigi)
{
    //change the attributes to suit with the form
    luigi.setTextureRect(sf::IntRect(0, 0, 16, 32));
    luigi.setTexture(Resources::textures["brick"]);
}

void FireLuigiForm::handleInput(Luigi& luigi, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(5.0f, 5.0f);
    //handle keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        luigi.moveRight(addedVelocity);
        luigi.setRunningIfOnGround();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        luigi.moveLeft(addedVelocity);
        luigi.setRunningIfOnGround();
    }
    else {
        luigi.setState(PlayerState::idle);
        luigi.applyDeceleration(deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && luigi.isOnGround()) {
        luigi.jump(addedVelocity);
        luigi.setState(PlayerState::jumping);
    }

    luigi.applyGravity(deltaTime);

    luigi.updatePosition(deltaTime);
    luigi.setOnGround(false);
}

void FireLuigiForm::Update(Luigi& luigi, float deltaTime)
{
    //animation or sth
    handleInput(luigi, deltaTime);
}

void FireLuigiForm::Exit(Luigi& luigi)
{
    //change to another form
}

void FireLuigiForm::handleCollisionWithMushroom(Luigi& luigi)
{
}

void FireLuigiForm::handleCollisionWithFlower(Luigi& luigi)
{
    //increase 1000 points
}



