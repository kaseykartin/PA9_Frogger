#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <array>

class Frog
{
public:
	Frog();

	void draw(sf::RenderWindow& window);
	
	void move();

	int get_x();

	int get_y();

	sf::IntRect get_hitbox();

	bool get_hit();

	void set_hit();

	void reset(int new_x, int new_y);

private:
	int x;
	int y;
	sf::Sprite sprite;
	sf::Texture texture;

	bool is_hit;

									//array for control inputs to move the frog by a single frame
	std::array<bool, 4> control_keys; //an array of four bools for up, down, left, right
};