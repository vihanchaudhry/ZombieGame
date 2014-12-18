#include "Background.h"

Background::Background()
{
	bgTexture.loadFromFile("bg.png");
	bgRect.setSize(sf::Vector2f(1280, 720));
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