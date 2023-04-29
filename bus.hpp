/*
 * bus.hpp
 *
 * Description: This file contains the necessary includes and declarations for the Bus class,
 *              which is a derived class of the MobileGameObject class.
 *              It represents a bus object in the game, with its own speed and hitbox.
 *
 * Author: Brandon Xu
 * Date: 2/28/23
 */


#include "mobilegameobject.hpp"

class Bus : public MobileGameObject {

public:

	Bus(int x, int y); // Constructor that takes a starting position

	// Overridden abstract methods from MobileGameObject
	float generateSpeed();

};