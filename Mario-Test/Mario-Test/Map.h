#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
#include "Renderer.h"
#include "Block.h"

class Map
{
private:
	//std::vector<std::vector<BlockType>> grid;
	std::vector<std::vector<Block>> body;
	float cellSize;
public:
	Map(float cellSize = 100.0f);
	void Draw(Renderer& renderer);
	void initFromImage(const sf::Image& image, sf::Vector2f& mario_position);
	std::vector<Block*> getCollidingBlocks(const sf::FloatRect& bounds);
};

