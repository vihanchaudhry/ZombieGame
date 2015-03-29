#include "Enemies.h"

Enemies::Enemies()
{
	enemyTexture.loadFromFile("gray.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(sf::Vector2f(32.f, 32.f));
	
	enemySprite.setPosition(200, 200);  // temp, till randomize is working
	randomizePosition();
}

void Enemies::render(sf::RenderWindow &window)
{
	window.draw(enemySprite);
}

void Enemies::update()
{
	// whatever happens every frame
}

void Enemies::spawnEnemy(Enemies enemy, std::vector<Enemies> &enemies, sf::Vector2f spawnPos)
{
	enemySprite.setPosition(spawnPos);
	enemies.push_back(enemy);
}

void Enemies::randomizePosition()
{
	// nothing yet
}
