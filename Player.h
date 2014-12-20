#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void render(sf::RenderWindow &);

	void up(float &);
	void down(float &);
	void left(float &);
	void right(float &);
private:
	float playerSpeed;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
};

#endif