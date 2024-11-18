#include "FirePlayerForm.h"
#include "SuperPlayerForm.h"
#include "SmallPlayerForm.h"
#include "Player.h"

void FirePlayerForm::Enter(Player& player)
{
    //change the attributes to suit with the form
    player.setTextureRect(sf::IntRect(0, 0, 16, 32));
    player.setTexture(Resources::textures["brick"]);
}

void FirePlayerForm::handleInput(Player& player, float deltaTime)
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

void FirePlayerForm::Update(Player& player, float deltaTime)
{
    //animation or sth
    handleInput(player, deltaTime);
}

void FirePlayerForm::Exit(Player& player)
{
    //change to another form
}

void FirePlayerForm::handleCollisionWithMushroom(Player& player)
{
}

void FirePlayerForm::handleCollisionWithFlower(Player& player)
{
    //increase 1000 points
}

bool FirePlayerForm::isSuperForm()
{
    return true;
}



