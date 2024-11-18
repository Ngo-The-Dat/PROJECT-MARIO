#include "PlayerForm.h"
#include "Player.h"

void PlayerForm::Enter(Player& player)
{
}

void PlayerForm::handleInput(Player& player, float deltaTimes)
{
}

void PlayerForm::Update(Player& player, float deltaTime)
{
}

void PlayerForm::Exit(Player& player)
{
}

void PlayerForm::handleCollisionWithGround(sf::FloatRect blockBounds, Player& player)
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    float overlapX = playerBounds.left < blockBounds.left
        ? playerBounds.left + playerBounds.width - blockBounds.left
        : blockBounds.left + blockBounds.width - playerBounds.left;

    float overlapY = playerBounds.top < blockBounds.top
        ? playerBounds.top + playerBounds.height - blockBounds.top
        : blockBounds.top + blockBounds.height - playerBounds.top;
    
    if (overlapX < 0) overlapX = 0;
    if (overlapY < 0) overlapY = 0;

    
    float diff = abs(overlapX - overlapY);
    const float collisionThreshold = 0.0f;
    if (overlapX > collisionThreshold && overlapY > collisionThreshold /*diff > collisionThreshold*/) {
        if (overlapX < overlapY) {
            if (player.isMovingRight()) {
                player.move(-overlapX, 0); // move player left
            }
            else if (!player.isMovingRight()) {
                player.move(overlapX, 0); // move player right
            }
            player.stopMovingHorizontal();
        }
        else {
            if (!player.isMovingUp()) {
                player.move(0, -overlapY); // move player up
                player.setOnGround(true);
                player.stopMovingVertical();
            }
            else if (player.isMovingUp()) {
                player.move(0, overlapY); // move player down
            }
        }
    }

}

void PlayerForm::handleCollisionWithItem(Player& player, Item& item)
{
    if (Mushroom* mushroom = dynamic_cast<Mushroom*>(&item)) {
        handleCollisionWithMushroom(player);
    }
    else if (dynamic_cast<Flower*>(&item)) {
        handleCollisionWithFlower(player);
    }
    else if (dynamic_cast<Star*>(&item)) {
        handleCollisionWithStar(player);
    }
    else if (dynamic_cast<Coin*>(&item)) {
        handleCollisionWithCoin(player);
    }
}

void PlayerForm::handleCollisionWithMushroom(Player& player)
{
}

void PlayerForm::handleCollisionWithFlower(Player& player)
{
}

void PlayerForm::handleCollisionWithStar(Player& player)
{
}

void PlayerForm::handleCollisionWithCoin(Player& player)
{
    // increase point by 100
}

bool PlayerForm::isSuperForm()
{
    return false;
}

bool PlayerForm::isFireForm()
{
    return false;
}
