#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Resources.h"
#include "Entity.h"
class Player;

enum class BlockType {
	Void,
	Ground,
	Brick,
	CoinBrick,
	ItemBrick,
	MysteryCoin,
	MysteryItem,
	Hidden,
	Empty
};

class Block : public Entity
{
private:
	BlockType m_blockType;
	int coinLeft;
public:
	Block();
	Block(sf::Texture* texture, sf::IntRect bound, BlockType blockType);
	

	// setter
	void setBlockType(BlockType blockType);

	// set state
	void setEmpty();

	// check block state
	bool isUnbreakable();

	// handle collision
	void handleCollisionWithPlayer(Player& player);
	void handleCollisionPlayerWithBrick(Player& player);
};

