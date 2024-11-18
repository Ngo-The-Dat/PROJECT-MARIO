#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Camera.h"
#include "Renderer.h"
#include <filesystem>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Hello Mario");
	sf::Clock deltaClock;
	Game g;
	Renderer renderer(window);
	g.Begin(window);


	while (window.isOpen())
	{
		float deltaTime = deltaClock.restart().asSeconds();
		sf::Event ev{};
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed())
			{
				window.close();
			}
		}
		
		window.setView(camera.getView(window.getSize()));
		//update anything here
		g.Update(deltaTime);
		window.clear(sf::Color::Transparent);
		//draw anything here
		g.Render(renderer);
		window.display();
	}
	return 0;
}

