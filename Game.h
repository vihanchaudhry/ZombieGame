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


class Game
{
private:
	enum
	{
		mainMenu, inGame, paused, postGame
	}GameState;

	sf::RenderWindow window;

	// For movement - temporary
	sf::Clock clock;
	float deltaTime;

	Background background;
	Player player;

	sf::Font courierNew;
	sf::Font droid;
	sf::Text gameTitle;
	sf::Text instructions;

	void loadAssets();

	// Update functions
	void menuUpdate();
	void gameUpdate();
	void pauseUpdate();
	void postUpdate();

	void render();
public:
	Game();
	void mainLoop();
	void handeEvent(sf::Event);
};

#endif