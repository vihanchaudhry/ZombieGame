#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	void render(sf::RenderWindow &);
	void update();
	void handleShooting(float, sf::Clock &, Bullet, std::vector<Bullet> &);

	// Mutators
	void setPosition(float, float);
	void setSpeedX(float);
	void setSpeedY(float);
	void rotateBullet(float);

	// Accessors
	const float getX()
	{ return bulletSprite.getPosition().x; }
	const float getY()
	{ return bulletSprite.getPosition().y; }
	const float getSpeedX()
	{ return speedX; }
	const float getSpeedY()
	{ return speedY; }
	const float getBulletRotation()
	{ return bulletSprite.getRotation(); }

	// Fire functions
	void fireUp();
	void fireDown();
	void fireLeft();
	void fireRight();
private:
	float speedX;
	float speedY;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
};

#endif