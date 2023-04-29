/*
 * mobilegameobject.hpp
 *
 * Description: This file contains the declaration of the MobileGameObject class, which represents a mobile game object in the game.
 *              It is a base class for objects that can move on the screen.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "mobilegameobject.hpp"

// Constructor that takes starting position
MobileGameObject::MobileGameObject(int x, int y) {

	//Initialize member attributes (location)
	this->_x = x * 50;
	this->_y = y * 50;
    
	// Random direction (0 or 1)
	_direction = y % 2;
	
	//_speed = generateSpeed(); // Set speed using abstract setSpeed method
    _speed = 1;

	//_hitbox = setHitBox(); // Set hitbox using abstract setHitBox method

}

// Draw object to display
void MobileGameObject::draw(sf::RenderWindow& window) {

	// Set sprite to most updated position
	_sprite.setPosition(_x, _y);

	// Set the texture for the sprite
	_sprite.setTexture(_texture);
	
	// Draw sprite
	window.draw(_sprite);
}

void MobileGameObject::update()
{
    // Determine direction
    if (_direction) { // Going right
        _x -= _speed; // Move right
        if (_x < -100) {
            _x = 1201; // Return to start after reaching the end of the screen
        }
    }
    else { // Going left
        _x += _speed; // Move left
        if (_x > 1200) {
            _x = -100; // Return to start after reaching the end of the screen
        }
    }

    // Update hitbox position
    _hitbox.left = _x;
    _hitbox.top = _y;
}

// Returns rectangle object that represents hitbox
sf::IntRect MobileGameObject::get_hitbox() {

	return _hitbox; // Return member hitbox

}
// Adds the specified amount to speed modifier
void MobileGameObject::incrementSpeed(int incr) {
    _speed += incr;
}

