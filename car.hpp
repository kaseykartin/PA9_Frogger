#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

class Car
{
public:
	Car(int y);

	void draw(sf::RenderWindow& window);

	void update();

protected:
	int x;
	int y;

	float speed; //how many pixels a car moves per tic

	bool direction; //0 for going left, 1 for going right

	sf::Sprite sprite;
	sf::Texture texture;
};

