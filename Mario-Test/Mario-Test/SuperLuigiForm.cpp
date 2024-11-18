#include "SuperLuigiForm.h"
#include "SmallLuigiForm.h"
#include "FireLuigiForm.h"
#include "Luigi.h"

void SuperLuigiForm::Enter(Luigi& luigi)
{
    //change the attributes to suit with the form
    luigi.setTextureRect(sf::IntRect(0, 0, 16, 32));
    luigi.setTexture(Resources::textures["super_luigi"]);
}

void SuperLuigiForm::handleInput(Luigi& luigi, float deltaTime)
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

void SuperLuigiForm::Update(Luigi& luigi, float deltaTime)
{
    //animation or sth
    handleInput(luigi, deltaTime);
}

void SuperLuigiForm::Exit(Luigi& luigi)
{
    //change to another form
}

void SuperLuigiForm::handleCollisionWithMushroom(Luigi& luigi)
{
}

void SuperLuigiForm::handleCollisionWithFlower(Luigi& luigi)
{
    luigi.setCurrenForm(std::make_shared<FireLuigiForm>());
}


