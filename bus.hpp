#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

#include "car.hpp"

class Bus : public Car
{
public:

	Bus(int y);

	void draw(sf::RenderWindow& window);

};