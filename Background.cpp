#include "Background.h"

Background::Background()
{
	bgTexture.loadFromFile("bg.png");
	bgRect.setSize(sf::Vector2f(1280, 720));
	bgRect.setTexture(&bgTexture);

	leftWall.setSize(sf::Vector2f(50, 620));
	leftWall.setPosition(0, 50);
	leftBox = leftWall.getGlobalBounds();
}

const sf::FloatRect Background::getLeftBox()
{
	return leftBox;
}

void Background::update()
{
	// NOT NEEDED YET
}

void Background::render(sf::RenderWindow &window)
{
	window.draw(bgRect);
}

