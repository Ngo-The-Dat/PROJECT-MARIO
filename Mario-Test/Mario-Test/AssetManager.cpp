#include "AssetManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;
// dont call a second time
AssetManager::AssetManager() : m_Textures() {
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename) {
    std::map<std::string, sf::Texture>& texMap = sInstance->m_Textures;
    // See if the texture is already loaded
    auto pairFound = texMap.find(filename);
    // If yes, return the texture

    if (pairFound != texMap.end()) {
        return pairFound->second;
    }
    else // Else, load the texture and return it
    {
        // Create an element in the texture map
        sf::Texture& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}
