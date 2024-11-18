#include "Block.h"
#include "Player.h"
#include <iostream>

Block::Block(): m_blockType(BlockType::Ground) {
	
}

Block::Block(sf::Texture* texture, sf::IntRect bound, BlockType blockType): m_blockType(blockType) {
	setTextureRect(bound);
	setTexture(*texture);
}


void Block::setBlockType(BlockType blockType)
{
	m_blockType = blockType;
}

void Block::setEmpty()
{
	m_blockType = BlockType::Empty;
}

bool Block::isUnbreakable()
{
	if (m_blockType == BlockType::Ground || m_blockType == BlockType::Brick)
		return true;

	return false;
}

void Block::handleCollisionWithPlayer(Player& player)
{
	switch (m_blockType)
	{
	case BlockType::Void:
		break;
	case BlockType::Ground:
		break;
	case BlockType::Brick:
		this->handleCollisionPlayerWithBrick(player);
		break;
	case BlockType::CoinBrick:
		break;
	case BlockType::ItemBrick:
		break;
	case BlockType::MysteryCoin:
		break;
	case BlockType::MysteryItem:
		break;
	case BlockType::Hidden:
		break;
	case BlockType::Empty:
		break;
	default:
		break;
	}
}

void Block::handleCollisionPlayerWithBrick(Player& player)
{
	if (player.isMovingUp() && player.isSuper())
	{
		setTextureRect(sf::IntRect(0, 0, 0, 0));
		m_blockType = BlockType::Void;
	}

}
