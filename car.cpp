#include "car.hpp"

void Car::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Car::update()
{
	if (0 == direction)
	{
		x += speed;
	}
	else
	{
		x -= speed;
	}
}