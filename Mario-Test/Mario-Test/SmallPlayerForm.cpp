#include "SmallPlayerForm.h"
#include "SuperPlayerForm.h"
#include "Player.h"
#include <iostream>

void SmallPlayerForm::Enter(Player& player)
{
    //change the attributes to suit with the form
    player.setTextureRect(sf::IntRect(0, 0, 16, 16));
    player.setTexture(Resources::textures["small_mario01"]);
}

void SmallPlayerForm::handleInput(Player& player, float deltaTime)
{
    sf::Vector2f addedVelocity = sf::Vector2f(0.0f, 0.0f);
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

void SmallPlayerForm::Update(Player& player, float deltaTime)
{
    //animation or sth
    handleInput(player, deltaTime);
}

void SmallPlayerForm::Exit(Player& Player)
{
    //change to another form
}

void SmallPlayerForm::handleCollisionWithMushroom(Player& player)
{
    player.setCurrenForm(std::make_shared<SuperPlayerForm>());
}

void SmallPlayerForm::handleCollisionWithFlower(Player& player)
{
    player.setImmortal(true);
}
