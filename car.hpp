/*
 * Car.hpp
 *
 * Description: This file contains the declaration of the Car class, which is a derived class of MobileGameObject.
 *              It represents a car object in the game with its own position, speed, and hitbox.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "mobilegameobject.hpp"

class Car : public MobileGameObject {

public:

	Car(int x, int y); // Constructor that takes a starting position

	// Overridden abstract methods from MobileGameObject
	float generateSpeed(); 
	//sf::IntRect setHitBox() override;

};

