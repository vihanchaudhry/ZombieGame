#include "Bullet.h"
#include "Game.h"
#include "Player.h"
#include <cmath>

Bullet::Bullet()
{
	bulletTexture.loadFromFile("bullet.png");
	bulletSprite.setTexture(bulletTexture);

	speedX = 0;
	speedY = 0;

	bulletSprite.setOrigin(16, 16);
	bulletSprite.setPosition(650, 330); // temp
}

void Bullet::render(sf::RenderWindow &window)
{
	window.draw(bulletSprite);
}

void Bullet::update()
{
	bulletSprite.move(speedX, speedY);
}

void Bullet::setPosition(float x, float y)
{
	bulletSprite.setPosition(x, y);
}

void Bullet::fireUp()
{
	speedX = 0;
	speedY = -10;
}

void Bullet::fireDown()
{
	speedX = 0;
	speedY = 10;
}

void Bullet::fireLeft()
{
	speedX = -10;
	speedY = 0;
}

void Bullet::fireRight()
{
	speedX = 10;
	speedY = 0;
}