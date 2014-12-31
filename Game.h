#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Background.h"
#include "Player.h"
#include "Bullet.h"

class Game
{
private:
	enum
	{
		mainMenu, inGame, paused, postGame
	}GameState;

	sf::RenderWindow window;

	sf::Clock clock;
	float deltaTime;

	Background background;
	Player player;
	Bullet bullet;

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