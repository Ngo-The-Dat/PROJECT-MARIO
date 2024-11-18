#pragma once
#include "SFML/Graphics.hpp"

class Camera
{
private:
	float zoomLevel;
	sf::Vector2f position;
	
public:
	Camera(float zoomLevel = 500.0f);
	sf::View getView(sf::Vector2u windowSize);
	float getZoomLevel();
	sf::Vector2f& getPosition();
};

