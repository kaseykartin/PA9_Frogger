#include "car.hpp"

Car::Car(int y) : direction(y % 2), y(50 * y)
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
		speed = 3;
	}
	else if (y == 10 || y == 11)
	{
		speed = 4;
	}
	else
	{
		speed = 5;
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
	}
	else
	{
		x -= speed;
	}
}