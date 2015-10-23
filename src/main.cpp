#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Overlap.h"

void handleEvent(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void update(sf::Sprite& charizardSprite, sf::Sprite& cookieSprite, int& eaten)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		charizardSprite.move(0, -5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		charizardSprite.move(0, 5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		charizardSprite.move(-5, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		charizardSprite.move(5, 0);
	if (overlap(charizardSprite, cookieSprite))
	{
		eaten++;
		cookieSprite.setPosition(0, 0);
		charizardSprite.setScale(1.5, 1.5);
	}
}

void draw(sf::RenderWindow& window, sf::Sprite& charizardSprite, sf::Sprite& cookieSprite, int& eaten)
{
	window.clear();
	window.draw(cookieSprite);
	window.draw(charizardSprite);
	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works!");
	window.setVerticalSyncEnabled(true);
	sf::Texture charizardTexture;
	charizardTexture.loadFromFile(resourcePath() + "assets/charizard.png");
	sf::Sprite charizardSprite(charizardTexture);
	
	sf::Texture cookieTexture;
	cookieTexture.loadFromFile(resourcePath() + "assets/cookie.png");
	sf::Sprite cookieSprite(cookieTexture);
	cookieSprite.setPosition(400, 300);
	int eaten = 0;

	while (window.isOpen())
	{
		handleEvent(window);
		update(charizardSprite, cookieSprite, eaten);
		draw(window, charizardSprite, cookieSprite, eaten);
	}

	return 0;
}
