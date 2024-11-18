#pragma once
#include "PlayerForm.h"
class FirePlayerForm :
	public PlayerForm
{
public:
	void Enter(Player& player) override;
	void handleInput(Player& player, float deltaTime) override;
	void Update(Player& player, float deltaTime) override;
	void Exit(Player& player) override;

	//handle collision

	void handleCollisionWithMushroom(Player& player) override;
	void handleCollisionWithFlower(Player& player) override;

	bool isSuperForm() override;
};

