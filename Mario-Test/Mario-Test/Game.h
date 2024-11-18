#pragma once
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Camera.h"
#include "Map.h"
#include "Renderer.h"
#include "Mario.h"
#include "Enemy.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "Koopa.h"
#include "PiranhaPlant.h"
#include "BulletBill.h"
#include "CheepCheep.h"
#include "CollisionManager.h"

extern Camera camera;

class Game
{
public:
	void Begin(const sf::Window& window);
	void Update(float deltaTime);
	void Render(Renderer& renderer);
};

