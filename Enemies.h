#ifndef ENEMIES_H
#define ENEMIES_H

#include <SFML/Graphics.hpp>

class Enemies
{
public:
	Enemies();
	void render(sf::RenderWindow &);
	void update();
	void spawnEnemy(Enemies, std::vector<Enemies> &, sf::Vector2f);

	const float getX()
	{ return enemySprite.getPosition().x;	}
	const float getY()
	{ return enemySprite.getPosition().y; }
	const sf::FloatRect getCollisionBox()
	{ return enemySprite.getGlobalBounds(); }
	const int getNumEnemies()
	{ return numEnemies; }
private:
	float speed;
	int numEnemies;
	sf::Texture enemyTexture; 
	sf::Sprite enemySprite;

	void randomizePosition();
};

#endif
