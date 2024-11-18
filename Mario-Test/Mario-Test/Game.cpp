#include "Game.h"

Map map(16.0f);
Camera camera(350.0f);
Mario* mario = nullptr;
//Mushroom* mushroom = nullptr;
//Star* star = nullptr;
//Goomba* goomba = nullptr;
//Goomba* goomba2 = nullptr;
//Koopa* koopa = nullptr;
//PiranhaPlant* piranha = nullptr;
CheepCheep* cheepCheep = nullptr;


CollisionManager colManager;

void Game::Begin(const sf::Window& window)
{
	// loading textures from file to a map of textures
	for (auto& file : std::filesystem::recursive_directory_iterator(/*"./resources-test/textures/"*/"../resources-test/textures/"))
	{
		if (file.is_regular_file() && (file.path().extension() == "png" || file.path().extension() == ".png" ||
			file.path().extension() == ".jpg" || file.path().extension() == ".jpeg"))
		{
			Resources::textures[file.path().stem().string()].loadFromFile(file.path().string());
			Resources::textures[file.path().stem().string()].setSmooth(false);
		}

	}

	//initialize mario and enemy 
	mario = new Mario(sf::Vector2f(300.0f, 170.0f), sf::Vector2f(30.0f, 80.0f), sf::Vector2f(0.3f, 1.0f), sf::Vector2f(20.0f, 20.0f), sf::Vector2f(40.0f, 60.0f));
	//star = new Star(sf::Vector2f(320.0f, 170.0f), sf::Vector2f(20.0f, 60.0f), sf::Vector2f(0.3f, 0.1f), sf::Vector2f(40.0f, 70.0f));
	//mushroom = new Mushroom(sf::Vector2f(340.0f, 180.0f), sf::Vector2f(10.0f, 30.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(25.0f, 40.0f));
	//goomba = new Goomba(sf::Vector2f(340.0f, 180.0f), sf::Vector2f(25.0f, 50.0f), sf::Vector2f(40.0f, 40.0f));
	//goomba2 = new Goomba(sf::Vector2f(320.0f, 180.0f), sf::Vector2f(25.0f, 50.0f), sf::Vector2f(40.0f, 40.0f));
	//koopa = new Koopa(sf::Vector2f(320.0f, 180.0f), sf::Vector2f(25.0f, 50.0f), sf::Vector2f(40.0f, 40.0f));
	//piranha = new PiranhaPlant(sf::Vector2f(380.0f, 150.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(0.0f, 40.0f));
	//bulletbill = new BulletBill(sf::Vector2f(380.0f, 200.0f), sf::Vector2f(-20.0f, 0.0f), sf::Vector2f(-20.0f, 0.0f));
	cheepCheep = new CheepCheep(sf::Vector2f(380.0f, 300.0f), sf::Vector2f(20.0f, -100.0f), sf::Vector2f(50.0f, 50.0f));

	//initialize map and set mario position
	sf::Image image;
	//image.loadFromFile("./resources-test/textures/map.png");
	image.loadFromFile("../resources-test/textures/map.png");
	sf::Vector2f mario_position;
	map.initFromImage(image, mario_position);
	//mario->setPosition(mario_position);
	camera.getPosition() = sf::Vector2f(300.0f, 250.0f);
}

void Game::Update(float deltaTime)
{
	colManager.checkCollisionPlayerWithMap(*mario, map);
	//colManager.checkCollisionPlayerWithItem(*mario, *mushroom);
	//colManager.checkCollisionMushroomWithMap(*mushroom, map);
	//colManager.checkCollisionStarWithMap(*star, map);
	//colManager.checkCollisionEnemyWithMap(*goomba, map);
	//colManager.checkCollisionEnemyWithMap(*goomba2, map);
	//colManager.checkCollisionEnemyWithEnemy(*goomba, *goomba2);
	//colManager.checkCollisionPlayerWithEnemy(*mario, *goomba);
	colManager.checkCollisionPlayerWithEnemy(*mario, *cheepCheep);


	// check collision enemy with map
	//colManager.checkCollisionEnemyWithMap(*piranha, map);
	//colManager.checkCollisionEnemyWithMap(*bulletbill, map);
	//colManager.checkCollisionEnemyWithMap(*koopa, map);
	//colManager.checkCollisionEnemyWithMap(*goomba, map);
	//colManager.checkCollisionEnemyWithMap(*goomba2, map);
	colManager.checkCollisionEnemyWithMap(*cheepCheep, map);

	// check collision enemy with enemy
	//colManager.checkCollisionEnemyWithEnemy(*koopa, *goomba);
	//colManager.checkCollisionEnemyWithEnemy(*koopa, *piranha);
	//colManager.checkCollisionEnemyWithEnemy(*koopa, *bulletbill);	
	//check collision player with enemy
	//colManager.checkCollisionPlayerWithEnemy(*mario, *koopa);
	//colManager.checkCollisionPlayerWithEnemy(*mario, *bulletbill);
	//colManager.checkCollisionEnemyWithEnemy(*koopa, *goomba);

	mario->Update(deltaTime);
	camera.getPosition() = mario->getPosition();
	//star->Update(deltaTime);
	//mushroom->Update(deltaTime);
	//goomba->Update(deltaTime);
	//goomba2->Update(deltaTime);
	//koopa->Update(deltaTime);
	//piranha->Update(deltaTime);
	//bulletbill->Update(deltaTime);
	cheepCheep->Update(deltaTime);
}

void Game::Render(Renderer& renderer)
{
	map.Draw(renderer);
	//renderer.getRenderTarget().draw(*mushroom);
	//renderer.getRenderTarget().draw(*star);
	//renderer.getRenderTarget().draw(*goomba);
	//renderer.getRenderTarget().draw(*goomba2);
	//renderer.getRenderTarget().draw(*koopa);
	//renderer.getRenderTarget().draw(*piranha);
	//renderer.getRenderTarget().draw(*bulletbill);
	renderer.getRenderTarget().draw(*cheepCheep);
	mario->Draw(renderer);
	//renderer.getRenderTarget().draw(enemy->getBody());
}



