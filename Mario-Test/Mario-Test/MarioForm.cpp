#include "MarioForm.h"
#include "Mario.h"

void MarioForm::Enter(Mario& mario)
{
}

void MarioForm::handleInput(Mario& mario, float deltaTimes)
{
}

void MarioForm::Update(Mario& mario, float deltaTime)
{
}

void MarioForm::Exit(Mario& mario)
{
}

//void MarioForm::handleCollisionWithGround(sf::FloatRect blockBounds, Mario& mario)
//{
//    sf::FloatRect marioBounds = mario.getGlobalBounds();
//    float overlapX = marioBounds.left < blockBounds.left
//        ? marioBounds.left + marioBounds.width - blockBounds.left
//        : blockBounds.left + blockBounds.width - marioBounds.left;
//
//    float overlapY = marioBounds.top < blockBounds.top
//        ? marioBounds.top + marioBounds.height - blockBounds.top
//        : blockBounds.top + blockBounds.height - marioBounds.top;
//
//    if (overlapY < 0) overlapY = 0;
//    if (overlapY < 0) overlapY = 0;
//
//
//    float diff = abs(overlapX - overlapY);
//    const float collisionThreshold = 0.0f;
//    if (overlapX > collisionThreshold && overlapY > collisionThreshold /*diff > collisionThreshold*/) {
//        if (overlapX < overlapY) {
//            if (mario.isMovingRight()) {
//                mario.move(-overlapX, 0); // move mario left
//            }
//            else if (!mario.isMovingRight()) {
//                mario.move(overlapX, 0); // move mario right
//            }
//            mario.stopMovingHorizontal();
//        }
//        else {
//            if (!mario.isMovingUp()) {
//                mario.move(0, -overlapY); // move mario up
//                mario.setOnGround(true);
//                mario.stopMovingVertical();
//            }
//            else if (mario.isMovingUp()) {
//                mario.move(0, overlapY); // move mario down
//            }
//        }
//    }
//
//}

void MarioForm::handleCollisionWithItem(Mario& mario, Item& item)
{
    if (Mushroom* mushroom = dynamic_cast<Mushroom*>(&item)) {
        handleCollisionWithMushroom(mario);
    }
    else if (dynamic_cast<Flower*>(&item)) {
        handleCollisionWithFlower(mario);
    }
    else if (dynamic_cast<Star*>(&item)) {
        handleCollisionWithStar(mario);
    }
    else if (dynamic_cast<Coin*>(&item)) {
        handleCollisionWithCoin(mario);
    }
}

void MarioForm::handleCollisionWithMushroom(Mario& mario)
{
}

void MarioForm::handleCollisionWithFlower(Mario& mario)
{
}

void MarioForm::handleCollisionWithStar(Mario& mario)
{
}

void MarioForm::handleCollisionWithCoin(Mario& mario)
{
    // increase point by 100
}
