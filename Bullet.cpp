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

void Bullet::update(std::vector<Bullet> &bullets, std::vector<Enemies> &enemies, Enemies enemy)
{
	bulletSprite.move(speedX, speedY);
	enemyHit(bullets, enemies, enemy);
}

void Bullet::handleShooting(float delayTime, sf::Clock &delayClock, Bullet bullet, std::vector<Bullet> &bullets)
{
	if (delayTime >= 0.25f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bullets.push_back(bullet);
			if (bullets[bullets.size() - 1].getBulletRotation() != 270)
				bullets[bullets.size() - 1].rotateBullet(270);
			bullets[bullets.size() - 1].fireUp();
			delayClock.restart().asSeconds();
			liveTime.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			bullets.push_back(bullet);
			if (bullets[bullets.size() - 1].getBulletRotation() != 90)
				bullets[bullets.size() - 1].rotateBullet(90);
			bullets[bullets.size() - 1].fireDown();
			delayClock.restart().asSeconds();
			liveTime.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bullets.push_back(bullet);
			if (bullets[bullets.size() - 1].getBulletRotation() != 180)
				bullets[bullets.size() - 1].rotateBullet(180);
			bullets[bullets.size() - 1].fireLeft();
			delayClock.restart().asSeconds();
			liveTime.restart().asSeconds();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bullets.push_back(bullet);
			if (bullets[bullets.size() - 1].getBulletRotation() != 0)
				bullets[bullets.size() - 1].rotateBullet(0);
			bullets[bullets.size() - 1].fireRight();
			delayClock.restart().asSeconds();
			liveTime.restart().asSeconds();
		}
	}
}

void Bullet::enemyHit(std::vector<Bullet> &bullets, std::vector<Enemies> &enemies, Enemies enemy)
{
	for (int i = 0; i < bullets.size(); i++)
		for (int j = 0; j < enemy.getNumEnemies(); j++)
		{
			if (bullets[i].getCollisionBox().intersects(enemies[j].getCollisionBox()))
			{
				bullets.erase(bullets.begin() + j);
				// damage enemy
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

void Bullet::rotateBullet(float rotation)
{
	bulletSprite.setRotation(rotation);
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
