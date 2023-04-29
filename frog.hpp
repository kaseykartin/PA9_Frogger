/*
 * frog.hpp
 *
 * Description: This file contains the necessary includes and declarations for the Frog class,
 *              which represents the player-controlled frog character in the game.
 *              It includes the necessary header file for the "header.h" and uses SFML for graphics.
 *
 * Author: Brandon Xu
 * Date: 2/28/23
 */


#pragma once

#include "header.h"

class Frog {
public:
	Frog();

	void draw(sf::RenderWindow& window);
	
	void move();

	void move(int logSpeed);

	int get_x();

	int get_y();

	void set_x(int newX);

	void set_y(int newY);

	sf::IntRect get_hitbox();

	bool get_hit(); // Returns collision state

	void set_hit(); // Registers a collision

	void reset(int new_x, int new_y);


private:

	// Position
	int x;
	int y;

	sf::Sprite sprite;
	sf::Texture texture;

	bool is_hit; // Collision state

									//array for control inputs to move the frog by a single frame
	std::array<bool, 4> control_keys; //an array of four bools for up, down, left, right
};