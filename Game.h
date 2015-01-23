#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Background.h"
#include "Player.h"
#include "Enemies.h"
#include "Bullet.h"
#include <vector>

class Game
{
private:
	enum
	{
		mainMenu, inGame, paused, postGame
	}GameState;

	sf::RenderWindow window;
	sf::View camera;

	sf::Clock fireClock;
	float fireTime;

	Background background;
	Player player;
	Enemies enemy;
	Bullet bullet;
	std::vector<Bullet> bullets;

	sf::Font courierNew;
	sf::Font droid;
	sf::Text gameTitle;
	sf::Text instructions;

	// Update functions
	void menuUpdate();
	void gameUpdate();
	void pauseUpdate();
	void postUpdate();

	void render();
	void loadAssets();
	bool isCollision(sf::FloatRect, sf::FloatRect);
public:
	Game();
	void mainLoop();
	void handleEvent(sf::Event);
};

#endif
