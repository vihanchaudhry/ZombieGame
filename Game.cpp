#include <iostream>
#include "Game.h"
#include "Player.h"
#include <cmath>

Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Untitled Zombie Game", sf::Style::Fullscreen); //  Doesn't have to be fullscreen
	window.setKeyRepeatEnabled(false);

	// For more smoothing, set VSync to false and Framerate to ~500
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	loadAssets();

	GameState = mainMenu;
}

void Game::mainLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		deltaTime = clock.restart().asMilliseconds();
		while (window.pollEvent(event))
			handleEvent(event);
		if (GameState == mainMenu)
			menuUpdate();
		else if (GameState == inGame)
			gameUpdate();
		else if (GameState == paused)
			pauseUpdate();
		else if (GameState == postGame)
			postUpdate();
		render();
	}
}

void Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Escape)
			window.close();
	// All events during main menu
	if (GameState == mainMenu)
	{
		// Keys being pressed in menu
		if (sf::Event::KeyPressed)
		{
			// Specifically if space is pressed
			if (event.key.code == sf::Keyboard::Space)
			{
				// Move to inGame (start playing)
				GameState = inGame;
			}
		}
	}
	if (GameState == inGame)
	{

	}
	// Rest of the events here
}

void Game::loadAssets()
{
	courierNew.loadFromFile("cour.ttf");
	droid.loadFromFile("DroidSans.ttf");

	gameTitle.setFont(courierNew);
	gameTitle.setString("Untitled Zombie Game");
	gameTitle.setCharacterSize(80);
	gameTitle.setColor(sf::Color::Black);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setPosition(150, 225);

	instructions.setFont(droid);
	instructions.setString("[Press space to begin]");
	instructions.setCharacterSize(36);
	instructions.setColor(sf::Color::Black);
	instructions.setPosition(465, 425);
}

bool Game::isCollision(sf::FloatRect box1, sf::FloatRect box2)
{
	bool collision = false;
	if (box1.intersects(box2))
		collision = true;
	return collision;
}

void Game::menuUpdate()
{
	background.update();
}

void Game::gameUpdate()
{
	background.update();
	bullet.update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.up(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.down(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.left(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.right(deltaTime);

	// Testing shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		bullet.setPosition(player.getX(), player.getY());
		bullet.fireUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		bullet.setPosition(player.getX(), player.getY());
		bullet.fireDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		bullet.setPosition(player.getX(), player.getY());
		bullet.fireLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		bullet.setPosition(player.getX(), player.getY());
		bullet.fireRight();
	}
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
	if (GameState == mainMenu)
	{
		window.draw(gameTitle);
		window.draw(instructions);
	}
	else if (GameState == inGame)
	{
		player.render(window);
		bullet.render(window);
	}
	else if (GameState == paused)
	{
		// Load pause stuff
	}
	else if (GameState == postGame)
	{
		// Load post-game stuff
	}

	window.display();
}