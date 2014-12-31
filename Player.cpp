#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "Background.h"

Player::Player()
{
	playerTexture.loadFromFile("player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(31.5, 53.5);
	playerSprite.setPosition(640, 360);

	collisionBox = playerSprite.getGlobalBounds();
	
	playerSpeed = 0.5;
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(playerSprite);
}

void Player::up(float &dT)
{
	playerSprite.move(0.f, -playerSpeed * dT);
}

void Player::down(float &dT)
{
	playerSprite.move(0.f, playerSpeed * dT);
}

void Player::left(float &dT)
{
	playerSprite.move(-playerSpeed * dT, 0.f);
}

void Player::right(float &dT)
{
	playerSprite.move(playerSpeed * dT, 0.f);
}

const sf::FloatRect Player::getCollisionBox()
{
	return collisionBox;
}