#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void render(sf::RenderWindow &);

	// Player movement functions
	void up(float &);
	void down(float &);
	void left(float &);
	void right(float &);

	const float getX()
	{ return playerSprite.getPosition().x; }
	const float getY()
	{ return playerSprite.getPosition().y; }
	const sf::FloatRect getCollisionBox();
private:
	float playerSpeed;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::FloatRect collisionBox;
};

#endif