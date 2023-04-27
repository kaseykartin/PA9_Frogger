#pragma once

#include "car.hpp"
#include "frog.hpp"

class Log : public Car
{
public:

	Log(int x, int y);

	void draw(sf::RenderWindow& window);

	sf::IntRect get_hitbox();

	bool check_frog(Frog& playerFrog);

	void update(bool moveFrog, Frog& playerFrog);

};