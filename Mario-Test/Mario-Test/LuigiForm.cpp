#include "LuigiForm.h"
#include "Luigi.h"

void LuigiForm::Enter(Luigi& luigi)
{
}

void LuigiForm::handleInput(Luigi& luigi, float deltaTimes)
{
}

void LuigiForm::Update(Luigi& luigi, float deltaTime)
{
}

void LuigiForm::Exit(Luigi& luigi)
{
}

//void LuigiForm::handleCollisionWithGround(sf::FloatRect blockBounds, Luigi& luigi)
//{
//    sf::FloatRect luigiBounds = luigi.getGlobalBounds();
//    float overlapX = luigiBounds.left < blockBounds.left
//        ? luigiBounds.left + luigiBounds.width - blockBounds.left
//        : blockBounds.left + blockBounds.width - luigiBounds.left;
//
//    float overlapY = luigiBounds.top < blockBounds.top
//        ? luigiBounds.top + luigiBounds.height - blockBounds.top
//        : blockBounds.top + blockBounds.height - luigiBounds.top;
//
//    if (overlapY < 0) overlapY = 0;
//    if (overlapY < 0) overlapY = 0;
//
//
//    float diff = abs(overlapX - overlapY);
//    const float collisionThreshold = 0.0f;
//    if (overlapX > collisionThreshold && overlapY > collisionThreshold /*diff > collisionThreshold*/) {
//        if (overlapX < overlapY) {
//            if (luigi.isMovingRight()) {
//                luigi.move(-overlapX, 0); // move luigi left
//            }
//            else if (!luigi.isMovingRight()) {
//                luigi.move(overlapX, 0); // move luigi right
//            }
//            luigi.stopMovingHorizontal();
//        }
//        else {
//            if (!luigi.isMovingUp()) {
//                luigi.move(0, -overlapY); // move luigi up
//                luigi.setOnGround(true);
//                luigi.stopMovingVertical();
//            }
//            else if (luigi.isMovingUp()) {
//                luigi.move(0, overlapY); // move luigi down
//            }
//        }
//    }
//
//}

void LuigiForm::handleCollisionWithItem(Luigi& luigi, Item& item)
{
    if (Mushroom* mushroom = dynamic_cast<Mushroom*>(&item)) {
        handleCollisionWithMushroom(luigi);
    }
    else if (dynamic_cast<Flower*>(&item)) {
        handleCollisionWithFlower(luigi);
    }
    else if (dynamic_cast<Star*>(&item)) {
        handleCollisionWithStar(luigi);
    }
    else if (dynamic_cast<Coin*>(&item)) {
        handleCollisionWithCoin(luigi);
    }
}

void LuigiForm::handleCollisionWithMushroom(Luigi& luigi)
{
}

void LuigiForm::handleCollisionWithFlower(Luigi& luigi)
{
}

void LuigiForm::handleCollisionWithStar(Luigi& luigi)
{
}

void LuigiForm::handleCollisionWithCoin(Luigi& luigi)
{
    // increase point by 100
}
