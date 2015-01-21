#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void render(sf::RenderWindow &);
	void update();

	const float getX()
	{ return playerSprite.getPosition().x; }
	const float getY()
	{ return playerSprite.getPosition().y; }
	const sf::FloatRect getCollisionBox()
	{ return playerSprite.getGlobalBounds(); }
private:
	float playerSpeed;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Player movement functions
	void up();
	void down();
	void left();
	void right();
};

#endif
