#include "Camera.h"

Camera::Camera(float zoomLevel) : zoomLevel(zoomLevel)
{
}

sf::View Camera::getView(sf::Vector2u windowSize)
{
    float aspect = (float)windowSize.x / (float)windowSize.y;
    sf::Vector2f size;
    if (aspect < 1.0f)
        size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else
        size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    return sf::View(position, size);
}

float Camera::getZoomLevel()
{
    return zoomLevel;
}

sf::Vector2f& Camera::getPosition()
{
    return position;
}
