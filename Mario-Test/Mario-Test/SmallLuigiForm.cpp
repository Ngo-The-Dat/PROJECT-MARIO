#include "SmallLuigiForm.h"
#include "SuperLuigiForm.h"
#include "Luigi.h"

void SmallLuigiForm::Enter(Luigi& luigi)
{
    //change the attributes to suit with the form
    luigi.setTextureRect(sf::IntRect(0, 0, 16, 16));
    luigi.setTexture(Resources::textures["small_luigi01"]);
}

void SmallLuigiForm::handleInput(Luigi& luigi, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(0.0f, 0.0f);
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

void SmallLuigiForm::Update(Luigi& luigi, float deltaTime)
{
    //animation or sth
    handleInput(luigi, deltaTime);
}

void SmallLuigiForm::Exit(Luigi& Luigi)
{
    //change to another form
}

void SmallLuigiForm::handleCollisionWithMushroom(Luigi& luigi)
{
    luigi.setCurrenForm(std::make_shared<SuperLuigiForm>());
}

void SmallLuigiForm::handleCollisionWithFlower(Luigi& luigi)
{
    luigi.setImmortal(true);
}
