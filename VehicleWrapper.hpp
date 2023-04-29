#pragma once 

#include "bus.hpp"
#include "car.hpp"
#include "frog.hpp"

class vehicleWrapper {
public:
	vehicleWrapper() {};

	void spawn_vehicles_1(sf::RenderWindow& window);
	void despawn_vehicles(sf::RenderWindow& window);

	void update(sf::RenderWindow& window, Frog& playerFrog);

private:
	std::vector<Car> cars;
	std::vector<Bus> buses;
};