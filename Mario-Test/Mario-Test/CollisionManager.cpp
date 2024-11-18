#include "CollisionManager.h"
#include <iostream>

void CollisionManager::Update(float deltaTime) {
}

// handle player collision with map (for all types of blocks)
// block is pointer in order to modify them in map
void CollisionManager::checkCollisionPlayerWithMap(Player& player, Map& map) {
    sf::FloatRect playerBounds = player.getGlobalBounds();
    std::vector<Block*> collidingBlocks = map.getCollidingBlocks(playerBounds);

    // collision threshold is for miscalculation when player collide because of float 
    for (Block* block : collidingBlocks) {
        const float collisionThreshold = 0.05f;
        sf::FloatRect blockBounds = block->getGlobalBounds();

        bool isHittingFromBeneath = (player.isMovingUp() &&
            playerBounds.top + collisionThreshold > blockBounds.top + blockBounds.height);
        // if player is hitting beneath a block then call handle collision for that block 
        if (isHittingFromBeneath) {
            block->handleCollisionWithPlayer(player);
        }

        player.handleCollisionWithGround(blockBounds);
    }
}

void CollisionManager::checkCollisionPlayerWithItem(Player& player, Item& item) {
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect itemBounds = item.getGlobalBounds();

    if (playerBounds.intersects(itemBounds)) {
        item.handleCollisionWithPlayer();
        player.handleCollisionWithItem(item);
    }
}

void CollisionManager::checkCollisionMushroomWithMap(Mushroom& mushroom, Map& map)
{
    sf::FloatRect mushroomBounds = mushroom.getGlobalBounds();
    std::vector<Block*> collidingBlocks = map.getCollidingBlocks(mushroomBounds);

    mushroom.setInAir();
    for (Block* block : collidingBlocks) {
        sf::FloatRect blockBounds = block->getGlobalBounds();
        mushroom.handleCollisionWithGround(blockBounds);
    }
}

void CollisionManager::checkCollisionStarWithMap(Star& star, Map& map)
{
    sf::FloatRect starBounds = star.getGlobalBounds();
    std::vector<Block*> collidingBlocks = map.getCollidingBlocks(starBounds);

    //star.setChangeDirection(false);
    star.setInAir();
    for (Block* block : collidingBlocks) {
        sf::FloatRect blockBounds = block->getGlobalBounds();
        star.handleCollisionWithGround(blockBounds);
        //if (isChangeDirection)
    }
}

void CollisionManager::checkCollisionPlayerWithBlock(Player& player, Block& block)
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect blockBounds = block.getGlobalBounds();

    if (playerBounds.intersects(blockBounds)) {
        block.handleCollisionWithPlayer(player);
        player.handleCollisionWithBlock();
    }
}

void CollisionManager::checkCollisionEnemyWithMap(Enemy& enemy, Map& map)
{
    sf::FloatRect enemyBounds = enemy.getGlobalBounds();
    std::vector<Block*> collidingBlocks = map.getCollidingBlocks(enemyBounds);

    for (Block* block : collidingBlocks) {
        sf::FloatRect blockBounds = block->getGlobalBounds();
        enemy.handleCollisionWithBlock(blockBounds);
    }
}

void CollisionManager::checkCollisionPlayerWithEnemy(Player& player, Enemy& enemy)
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect enemyBounds = enemy.getHitBox();

    if (playerBounds.intersects(enemyBounds)) {
        enemy.handleCollisionWithPlayer(player);
        //player.handleCollisionWithEnemy();
    }
}

void CollisionManager::checkCollisionEnemyWithEnemy(Enemy& enemy1, Enemy& enemy2)
{
    sf::FloatRect enemy1Bounds = enemy1.getHitBox();
    sf::FloatRect enemy2Bounds = enemy2.getHitBox();

    BulletBill* bulletBill1 = dynamic_cast<BulletBill*>(&enemy1);
    BulletBill* bulletBill2 = dynamic_cast<BulletBill*>(&enemy2);

    // If either enemy is a BulletBill, skip collision handling
    if (bulletBill1 || bulletBill2)
        return;

    CheepCheep* cheepCheep1 = dynamic_cast<CheepCheep*>(&enemy1);
    CheepCheep* cheepCheep2 = dynamic_cast<CheepCheep*>(&enemy2);

    if (cheepCheep1 || cheepCheep2)
        return;

    if (enemy1Bounds.intersects(enemy2Bounds)) {
        enemy1.handleCollisionWithEnemy(enemy2);
        enemy2.handleCollisionWithEnemy(enemy1);
        //player.handleCollisionWithEnemy();
    }

    Koopa* koopa1 = dynamic_cast<Koopa*>(&enemy1);
    Koopa* koopa2 = dynamic_cast<Koopa*>(&enemy2);

    if (koopa1 && koopa1->isBouncing()) {
        enemy2.die();
    }

    if (koopa2 && koopa2->isBouncing()) {
        enemy1.die();
    }
}
