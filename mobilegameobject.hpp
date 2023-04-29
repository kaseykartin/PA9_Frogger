// Abstract class for mobile game objects (excluding player)

#pragma once 

#include "header.h"

class MobileGameObject {

public:

	MobileGameObject(int x, int y); // Constructor that takes starting position

	void draw(sf::RenderWindow& window); // Draw object to display

	void update(); // Updates position of object based on the speed

	sf::IntRect get_hitbox(); // Returns rectangle object that represents hitbox


	// TODO: trying to get the pure virtual function to work so that developers are forced to implement it for unique mobilegameobjects
	// Abstract methods (MUST BE IMPLEMENTED BY DERIVED CLASSES)
	virtual float generateSpeed() = 0; // ABSTRACT set speed (unique to specific game objects)
	//virtual sf::IntRect setHitBox() = 0; // ABSTRACT (unique to specific game objects)

	void incrementSpeed(int incr); // Adds the specified amount to speed modifier
protected:

	// Position 
	int _x;
	int _y;

	float _speed; // Number of pixels object moves per tic

	bool _direction; // 0 = left, 1 = right

	sf::Sprite _sprite;
	sf::Texture _texture;

	sf::IntRect _hitbox; // Rectangle object that represents the object's hitbox
};