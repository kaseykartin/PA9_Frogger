#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <array>

class Car
{
public:
	Car(int x, int y);

	void draw(sf::RenderWindow& window);

	void update();

	sf::IntRect get_hitbox();

protected:
	int x;
	int y;

	float speed; //how many pixels a car moves per tic

	bool direction; //0 for going left, 1 for going right

	sf::Sprite sprite;
	sf::Texture texture;
};

