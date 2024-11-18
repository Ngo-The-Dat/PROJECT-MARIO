#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Mushroom.h"
class Player;

class PlayerForm
{
public:
	virtual void Enter(Player& player);
	virtual void handleInput(Player& player, float deltaTime);
	virtual void Update(Player& player, float deltaTime);
	virtual void Exit(Player& player);

	//handle collision
	virtual void handleCollisionWithGround(sf::FloatRect blockBounds, Player& player);
	virtual void handleCollisionWithItem(Player& player, Item& item);
	virtual void handleCollisionWithMushroom(Player& player);
	virtual void handleCollisionWithFlower(Player& player);
	virtual void handleCollisionWithStar(Player& player);
	virtual void handleCollisionWithCoin(Player& player);
	//virtual void handleCollisionWithBlock(Player& player);

	// check state
	virtual bool isSuperForm();
	virtual bool isFireForm();
};

