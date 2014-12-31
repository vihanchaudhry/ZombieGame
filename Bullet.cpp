#include "Bullet.h"
#include "Game.h"
#include "Player.h"
#include <cmath>

Bullet::Bullet()
{
	bulletTexture.loadFromFile("bullet.png");
	bulletSprite.setTexture(bulletTexture);

	bulletSpeed = 30;

	bulletSprite.setPosition(650, 330); // temp
}

void Bullet::render(sf::RenderWindow &window)
{
	window.draw(bulletSprite);
}

void Bullet::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Bullet::fireUp()
{
	bulletSprite.move(0.f, -bulletSpeed);
}

void Bullet::fireDown()
{
	bulletSprite.move(0.f, bulletSpeed);
}

void Bullet::fireLeft()
{
	bulletSprite.move(-bulletSpeed, 0.f);
}

void Bullet::fireRight()
{
	bulletSprite.move(bulletSpeed, 0.f);
}