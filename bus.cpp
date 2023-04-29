/*
 * bus.hpp
 *
 * Description: This file contains the declaration of the Bus class, which is a derived class of MobileGameObject.
 *              It represents a bus object in the Froggy game.
 *              The class manages the bus's position, hitbox, texture, and speed.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "bus.hpp"

// Inside the Bus class constructor
Bus::Bus(int x, int y) : MobileGameObject(x, y) {
    _hitbox = sf::IntRect(x, y, 99, 49); // Set unique bus hitbox

    // Load the texture from the image file
    if (0 == _direction) {
        _texture.loadFromFile("images/Bus1.png");
    }
    else {
        _texture.loadFromFile("images/Bus1Reverse.png");
    }

	_speed = generateSpeed();

}

// Generate speed based on row
float Bus::generateSpeed() {

	if (_y == 600 || _y == 650) { // Row 12 or 13
		return 3;
	}
	else if (_y == 500 || _y == 550) { // Row 10 or 11
		return 3;
	}
	else {
		return 2;
	}
}