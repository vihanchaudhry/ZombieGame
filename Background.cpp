#include "Background.h"

Background::Background()
{
	bgTexture.loadFromFile("extended_bg.png");
	bgRect.setSize(sf::Vector2f(1280, 1440));
	bgRect.setTexture(&bgTexture);
}

void Background::update()
{
	// NOT NEEDED YET
}

void Background::render(sf::RenderWindow &window)
{
	window.draw(bgRect);
}
