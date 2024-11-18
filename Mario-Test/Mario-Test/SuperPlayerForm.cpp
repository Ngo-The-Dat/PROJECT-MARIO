#include "SuperPlayerForm.h"
#include "SmallPlayerForm.h"
#include "FirePlayerForm.h"
#include "Player.h"

void SuperPlayerForm::Enter(Player& player)
{
    //change the attributes to suit with the form
    player.setTextureRect(sf::IntRect(0, 0, 16, 32));
    player.setTexture(Resources::textures["super_mario"]);
}

void SuperPlayerForm::handleInput(Player& player, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(5.0f, 5.0f);
    //handle keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.moveRight(addedVelocity);
        player.setRunningIfOnGround();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.moveLeft(addedVelocity);
        player.setRunningIfOnGround();
    }
    else {
        player.setState(PlayerState::idle);
        player.applyDeceleration(deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.isOnGround()) {
        player.jump(addedVelocity);
        player.setState(PlayerState::jumping);
    }

    player.applyGravity(deltaTime);

    player.updatePosition(deltaTime);
    player.setOnGround(false);
}

void SuperPlayerForm::Update(Player& player, float deltaTime)
{
    //animation or sth
    handleInput(player, deltaTime);
}

void SuperPlayerForm::Exit(Player& player)
{
    //change to another form
}

void SuperPlayerForm::handleCollisionWithMushroom(Player& player)
{
}

void SuperPlayerForm::handleCollisionWithFlower(Player& player)
{
    player.setCurrenForm(std::make_shared<FirePlayerForm>());
}

bool SuperPlayerForm::isSuperForm()
{
    return true;
}


