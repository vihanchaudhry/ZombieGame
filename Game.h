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
#include "Background.h"

class Game
{
private:
	enum
	{
		mainMenu, inGame, paused, postGame
	}GameState;

	sf::RenderWindow window;

	Background background;

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
};

#endif