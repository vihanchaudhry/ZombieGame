#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	void update();
	void render(sf::RenderWindow &);
private:
	sf::Texture bgTexture;
	sf::RectangleShape bgRect;
};

#endif