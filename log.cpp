#include "log.hpp"

Log::Log(int x, int y) : Car(x, y)
{
	const int cell_size = 50;
	const int screen_width = 1200;
	const int screen_height = 800;


	if (y == 1 || y == 2)
	{
		speed = 2;
	}
	else if (y == 3 || y == 4)
	{
		speed = 3;
	}
	else
	{
		speed = 2;
	}

}


void Log::draw(sf::RenderWindow& window)
{

	if (0 == direction)
	{
		texture.loadFromFile("images/shortlog.png");
	}
	else
	{
		texture.loadFromFile("images/longlog.png");
	}


	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	window.draw(sprite);

}