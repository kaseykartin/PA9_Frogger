#include "frog.hpp"

Frog::Frog() : x(550) , y(749)
{
	texture.loadFromFile("images/Frog.png");
	sprite.setTexture(texture);
}

void Frog::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Frog::move() //imagining cells of 50 x 50 pixels
{
	if (!control_keys[1] && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		y = y + 50;
	}
	else if (!control_keys[0] && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		y = y - 50;
	}
	else if (!control_keys[2] && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		x = x - 50;
	}
	else if (!control_keys[3] && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		x = x + 50;
	}

	control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}