#include <iostream>
#include "Game.h"
using namespace std;


Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Untitled Zombie Game");
	window.setVerticalSyncEnabled(true);

	loadAssets();

	GameState = mainMenu;
}

void Game::mainLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (GameState == mainMenu)
		{
			menuUpdate();
		}
		else if (GameState == inGame)
		{
			gameUpdate();
		}
		else if (GameState == paused)
		{
			pauseUpdate();
		}
		else if (GameState == postGame)
		{
			postUpdate();
		}

		render();
	}
}

void Game::loadAssets()
{

}

void Game::menuUpdate()
{
	background.update();
}

void Game::gameUpdate()
{
	background.update();
}

void Game::pauseUpdate()
{
	background.update();
}

void Game::postUpdate()
{
	background.update();
}

void Game::render()
{
	window.clear();

	background.render(window);

	window.display();
}