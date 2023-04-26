#pragma once

#include "car.hpp"

class Bus : public Car
{
public:

	Bus(int x, int y);

	void draw(sf::RenderWindow& window);

	sf::IntRect get_hitbox();

};