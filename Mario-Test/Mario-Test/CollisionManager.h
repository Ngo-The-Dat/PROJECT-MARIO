#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Mushroom.h"
#include "Flower.h"
#include "Star.h"
#include "Coin.h"
#include "Map.h"
#include "Koopa.h"
#include "BulletBill.h"
#include "CheepCheep.h"

class CollisionManager
{
public:
	void checkCollisionPlayerWithMap(Player& player, Map& map);// ensure players can move freely on map
	void checkCollisionPlayerWithItem(Player& player, Item& item);
	void checkCollisionMushroomWithMap(Mushroom& mushroom, Map& map);
	void checkCollisionStarWithMap(Star& star, Map& map);
	void checkCollisionPlayerWithBlock(Player& player, Block& block);

	void checkCollisionEnemyWithMap(Enemy& enemy, Map& map);
	void checkCollisionPlayerWithEnemy(Player& player, Enemy& enemy);
	void checkCollisionEnemyWithEnemy(Enemy& enemy1, Enemy& enemy2);


	void Update(float deltaTime);
private:
	std::vector<Entity*> m_entities;
};

