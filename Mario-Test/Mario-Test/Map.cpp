#include "Map.h"

Map::Map(float cellSize) : cellSize(cellSize) {}

void Map::Draw(Renderer& renderer) {
    for (int x = 0; x < body.size(); ++x) {
        for (int y = 0; y < body[x].size(); ++y) {
            // Set position for each Block
            //body[x][y].setPosition(sf::Vector2f(cellSize * y + cellSize / 2.0f, cellSize * x + cellSize / 2.0f));
            // Draw each Block on the renderer target
            renderer.getRenderTarget().draw(body[x][y]);
        }
    }
}

void Map::initFromImage(const sf::Image& image, sf::Vector2f& mario_position) {
    // Initialize grid dimensions based on image size
    int rows = image.getSize().y;
    int cols = image.getSize().x;

    //grid = std::vector<std::vector<BlockType>>(rows, std::vector<BlockType>(cols, BlockType::Breakable));
    body.resize(rows);

    for (int y = 0; y < rows; ++y) {
        body[y].resize(cols);
        for (int x = 0; x < cols; ++x) {
            sf::Color color = image.getPixel(x, y); // Note: (y, x) for (col, row) access

            if (color == sf::Color::Black) {
                body[y][x] = Block(&Resources::textures["brick"], sf::IntRect(0, 0, int(cellSize), int(cellSize)), BlockType::Ground);
            }
            else if (color == sf::Color::Red) {
                mario_position = sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
                body[y][x] = Block(&Resources::textures["sky"], sf::IntRect(0, 0, int(cellSize), int(cellSize)), BlockType::Void);
            }
            else if (color == sf::Color(128, 128, 128)) {
                body[y][x] = Block(&Resources::textures["brick_in_air"], sf::IntRect(0, 0, int(cellSize), int(cellSize)), BlockType::Brick);
            }
            else if (color == sf::Color::White) {
                body[y][x] = Block(&Resources::textures["sky"], sf::IntRect(0, 0, int(cellSize), int(cellSize)), BlockType::Void);
            }
            else if (color == sf::Color::Cyan) {
                body[y][x] = Block(&Resources::textures["cloud"], sf::IntRect(0, 0, int(cellSize), int(cellSize)), BlockType::Void);
            }
            
            body[y][x].setPosition(sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f));
            body[y][x].setScale(1.0f, 1.0f);
  
        }
    }
}

// most problematic function in the game, the problem of map collision
std::vector<Block*> Map::getCollidingBlocks(const sf::FloatRect& bounds) {
    std::vector<Block*> collidingBlocks;

    // if the player fits exactly in cells of his size, check collision of all blocks around those cells.
    // if the player fits exactly in a row, check collision with all blocks around those cells in adjacent rows.
    // if the player fits exacly in a column, check collision with all blocks around those cells in adjacent columns
    int startX = static_cast<int>(bounds.left / cellSize);
    int startY = static_cast<int>(bounds.top / cellSize);
    int endX = static_cast<int>((bounds.left + bounds.width) / cellSize);
    int endY = static_cast<int>((bounds.top + bounds.height) / cellSize);

    bool exactWidth = (bounds.width / cellSize == static_cast<int>(bounds.width / cellSize));
    bool exactHeight = (bounds.height / cellSize == static_cast<int>(bounds.height / cellSize));

    int xMin = startX - 1;
    int xMax = endX + 1;
    int yMin = startY - 1;
    int yMax = endY + 1;

    if (exactWidth && exactHeight) {
    }
    else if (exactWidth) {
        yMin = startY;
        yMax = endY;
    }
    else if (exactHeight) {
        xMin = startX;
        xMax = endX;
    }

    for (int y = yMin; y <= yMax; ++y) {
        for (int x = xMin; x <= xMax; ++x) {
            if (y >= 0 && y < body.size() && x >= 0 && x < body[0].size()) {
                bool isUnbreakable = body[y][x].isUnbreakable();

                if (isUnbreakable) {
                    Block& block = body[y][x];
                    if (bounds.intersects(block.getGlobalBounds())) {
                        collidingBlocks.push_back(&block);
                    }
                }
            }
        }
    }
    return collidingBlocks;
}
