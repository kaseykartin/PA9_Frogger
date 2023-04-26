#include "bus.hpp"
#include "frog.hpp"
#include <vector>

class vehicleWrapper {
public:
	vehicleWrapper() {};

	void spawn_vehicles_1(sf::RenderWindow& window);

	void update(sf::RenderWindow& window, Frog& playerFrog);

private:
	std::vector<Car> cars;
	std::vector<Bus> buses;
};