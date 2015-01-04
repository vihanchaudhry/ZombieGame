#include "Bullet.h"

Bullet::Bullet()
{
	bulletTexture.loadFromFile("bullet.png");
	bulletSprite.setTexture(bulletTexture);

	speedX = 0;
	speedY = 0;

	bulletSprite.setOrigin(16, 16);

}

void Bullet::render(sf::RenderWindow &window)
{
	window.draw(bulletSprite);
}

void Bullet::update()
{
	bulletSprite.move(speedX, speedY);
}

void Bullet::handleShooting(float delayTime, sf::Clock &delayClock, Bullet bullet, std::vector<Bullet> &bullets)
{
	if (delayTime >= 0.3f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bullets.push_back(bullet);
			bullets[bullets.size() - 1].fireUp();
			delayClock.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			bullets.push_back(bullet);
			bullets[bullets.size() - 1].fireDown();
			delayClock.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bullets.push_back(bullet);
			bullets[bullets.size() - 1].fireLeft();
			delayClock.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bullets.push_back(bullet);
			bullets[bullets.size() - 1].fireRight();
			delayClock.restart().asSeconds();
		}
	}
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