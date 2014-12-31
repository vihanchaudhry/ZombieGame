#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	void render(sf::RenderWindow &);

	// Accessors
	const float getX()
	{ return xPos; }
	const float getY()
	{ return yPos; }
	const float getSpeed()
	{ return bulletSpeed; }

	void setPosition(float, float);

	// Fire functions
	void fireUp();
	void fireDown();
	void fireLeft();
	void fireRight();
private:
	float xPos;
	float yPos;
	float bulletSpeed;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
};

#endif