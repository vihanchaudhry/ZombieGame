#ifndef ENEMIES_H
#define ENEMIES_H

#include <SFML/Graphics.hpp>

class Enemies
{
public:
	Enemies();
	void render(sf::RenderWindow &);
	void update();

	const float getX()
	{ 
		// return something.x;
	}
	const float getY()
	{ 
		// return something.y; 
	}
	const sf::FloatRect getCollisionBox()
	{ return enemySprite.getGlobalBounds(); }
private:
	float speed;
	sf::Texture enemyTexture; 
	sf::Sprite enemySprite;

	void randomizePosition();
};

#endif
