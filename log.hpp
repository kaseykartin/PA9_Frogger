#pragma once

#include "car.hpp"

class Log : public Car
{
public:

	Log(int x, int y);

	void draw(sf::RenderWindow& window);

	sf::IntRect get_hitbox();

};