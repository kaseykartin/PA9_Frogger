#pragma once

#include "header.h"

class Frog
{
public:
	Frog();

	void draw(sf::RenderWindow& window);
	
	void move();

	int get_x();

	int get_y();

private:
	int x;
	int y;
	sf::Sprite sprite;
	sf::Texture texture;

									//array for control inputs to move the frog by a single frame
	std::array<bool, 4> control_keys; //an array of four bools for up, down, left, right
};