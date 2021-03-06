#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(31.5, 53.5);
	playerSprite.setPosition(640, 360);
	
	playerSpeed = 10;
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(playerSprite);
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		up();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		down();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		left();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		right();
}

void Player::up()
{
	if (getY() >= 105)
		playerSprite.move(0.f, -playerSpeed);
}

void Player::down()
{
	if (getY() <= 1375)
		playerSprite.move(0.f, playerSpeed);
}

void Player::left()
{
	if (getX() >= 85)
		playerSprite.move(-playerSpeed, 0.f);
}

void Player::right()
{
	if (getX() <= 1195)
		playerSprite.move(playerSpeed, 0.f);
}
