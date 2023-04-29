/*
 * vehicleWrapper.hpp
 *
 * Description: This file contains the declaration of the vehicleWrapper class.
 *              It serves as a wrapper for the vehicles in the game, encapsulating the management of cars and buses.
 *              The class handles the spawning, despawning, and updating (movement and collision detection) of vehicles in the game.
 *
 * Author: [Author]
 * Date: [Date]
 */


#pragma once 

#include "bus.hpp"
#include "car.hpp"
#include "frog.hpp"

class vehicleWrapper {
public:

	void spawn_vehicles_1(sf::RenderWindow& window, int level); // Spawn vehicles with speed based on the inputted level
	void despawn_vehicles(sf::RenderWindow& window); // Clear all vehicles from the wrapper (effectively deleting them)

	// Move the car and check for collisions with the player
	void update(sf::RenderWindow& window, Frog& playerFrog);

private:

	// Vectors holding the cars and buses managed by this wrapper
	std::vector<Car> cars;
	std::vector<Bus> buses;
};