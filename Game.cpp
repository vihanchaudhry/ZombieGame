#include <iostream>
#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Untitled Zombie Game", sf::Style::Fullscreen);
	window.setKeyRepeatEnabled(false);
	window.setMouseCursorVisible(false);

	// For more smoothing, set VSync to false and Framerate to ~500
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	fireTime = fireClock.restart().asSeconds();

	loadAssets();

	GameState = mainMenu;
}

void Game::mainLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
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
	player.update();
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
	}

	// Shooting
	fireTime = fireClock.getElapsedTime().asSeconds();  // Fire delay
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && fireTime > 0.3f)
	{
		bullets.push_back(bullet);
		bullets[bullets.size() - 1].setPosition(player.getX(), player.getY());
		bullets[bullets.size() - 1].fireUp();
		fireClock.restart().asSeconds();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && fireTime > 0.3f)
	{
		bullets.push_back(bullet);
		bullets[bullets.size() - 1].setPosition(player.getX(), player.getY());
		bullets[bullets.size() - 1].fireDown();
		fireClock.restart().asSeconds();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && fireTime > 0.3f)
	{
		bullets.push_back(bullet);
		bullets[bullets.size() - 1].setPosition(player.getX(), player.getY());
		bullets[bullets.size() - 1].fireLeft();
		fireClock.restart().asSeconds();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && fireTime > 0.3f)
	{	
		bullets.push_back(bullet);
		bullets[bullets.size() - 1].setPosition(player.getX(), player.getY());
		bullets[bullets.size() - 1].fireRight();
		fireClock.restart().asSeconds();
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
		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].render(window);
		}
		player.render(window);
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