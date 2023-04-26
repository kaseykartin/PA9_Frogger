#include "car.hpp"

Car::Car(int x, int y) : direction(y % 2),x(50 * x), y(50 * y)
{
	const int cell_size = 50;
	const int screen_width = 1200;
	const int screen_height = 800;

	if (y == 12 || y == 13)
	{
		speed = 2;
	}
	else if (y == 10 || y == 11)
	{
		speed = 4;
	}
	else
	{
		speed = 3;
	}

}


void Car::draw(sf::RenderWindow& window)
{

	if (0 == direction)
	{
		texture.loadFromFile("images/Car1.png");
	}
	else
	{
		texture.loadFromFile("images/Car1Reverse.png");
	}


	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	window.draw(sprite);

}

void Car::update()
{
	if (0 == direction)
	{
		x += speed;
		if (x > 1200)
		{
			x = -100;
		}
	}
	else
	{
		x -= speed;

		if (x < -100)
		{
			x = 1201;
		}
	}
}

sf::IntRect Car::get_hitbox()
{
	return sf::IntRect(x, y, 49, 49);
}