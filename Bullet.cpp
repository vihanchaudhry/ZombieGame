#include "Bullet.h"

Bullet::Bullet()
{
	bulletTexture.loadFromFile("bullet.png");
	bulletSprite.setTexture(bulletTexture);

	speedX = 0;
	speedY = 0;

	bulletSprite.setOrigin(16, 16);
	bulletSprite.setPosition(660, 360); // temp
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

void Bullet::setSpeedX(float x)
{
	speedX = x;
}

void Bullet::setSpeedY(float y)
{
	speedY = y;
}

void Bullet::fireUp()
{
	speedX = 0;
	speedY = -15;
}

void Bullet::fireDown()
{
	speedX = 0;
	speedY = 15;
}

void Bullet::fireLeft()
{
	speedX = -15;
	speedY = 0;
}

void Bullet::fireRight()
{
	speedX = 15;
	speedY = 0;
}