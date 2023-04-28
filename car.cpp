#include "car.hpp"

Car::Car(int x, int y) : MobileGameObject(x, y) {

	_hitbox = sf::IntRect(x, y, 49, 49); // Set unique car hitbox
	//_speed = generateSpeed(); // Set speed 

	// Load texture
	if (_direction) { // Facing right
		_texture.loadFromFile("images/Car1Reverse.png");
	}
	else { // Facing left
		_texture.loadFromFile("images/Car1.png");
	}

	_speed = generateSpeed();
}

// Generate speed based on row
float Car::generateSpeed() {

	if (_y == 600 || _y == 650) { // Row 12 or 13
		return 2;
	}
	else if (_y == 500 || _y == 550) { // Row 10 or 11
		return 4;
	}
	else {
		return 3;
	}
}