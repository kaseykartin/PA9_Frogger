#include "bus.hpp"

Bus::Bus(int y) : Car(y)
{
	const int cell_size = 50;
	const int screen_width = 1200;
	const int screen_height = 800;

	if (y % 2 != 0)
	{
		x = 1150;
	}
	else
	{
		x = 0;
	}


	if (y == 12 || y == 13)
	{
		speed = 2;
	}
	else if (y == 10 || y == 11)
	{
		speed = 3;
	}
	else
	{
		speed = 4;
	}

}


void Bus::draw(sf::RenderWindow& window)
{

	if (0 == direction)
	{
		texture.loadFromFile("images/Bus1.png");
	}
	else
	{
		texture.loadFromFile("images/Bus1Reverse.png");
	}


	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	window.draw(sprite);

}