#include "VehicleWrapper.hpp"

void vehicleWrapper::spawn_vehicles_1(sf::RenderWindow& window)
{
	//spawning in cars and buses row by row using vectors of each
	//first "row" starting from the top
	cars.push_back(Car(1, 8));
	cars.push_back(Car(8, 8));
	cars.push_back(Car(16, 8));

	//second row
	buses.push_back(Bus(1, 9));
	buses.push_back(Bus(8, 9));
	buses.push_back(Bus(16, 9));

	//third row
	cars.push_back(Car(1, 10));
	cars.push_back(Car(12, 10));

	//fourth row
	cars.push_back(Car(1, 11));
	cars.push_back(Car(8, 11));
	cars.push_back(Car(16, 11));

	//fifth row
	buses.push_back(Bus(1, 12));
	buses.push_back(Bus(12, 12));

	//sixth row
	cars.push_back(Car(1, 13));
	cars.push_back(Car(12, 13));
}

void vehicleWrapper::despawn_vehicles(sf::RenderWindow& window) {
	cars.clear();
	buses.clear();
}


void vehicleWrapper::update(sf::RenderWindow& window, Frog& playerFrog)
{
	for (Car& car : cars)
	{
		car.draw(window); //go thru the vector list and update each car
		car.update();
	}
	for (Bus& bus : buses)
	{
		bus.draw(window); //doing the same with the buses
		bus.update();
	}

	if (false == playerFrog.get_hit()) //when the frog is alive check every frame for intersection/collision
	{
		for (Car& car : cars)
		{
			if (1 == car.get_hitbox().intersects(playerFrog.get_hitbox()))
			{
				playerFrog.set_hit();
			}
		}

		for (Bus& bus : buses)
		{
			if (1 == bus.get_hitbox().intersects(playerFrog.get_hitbox()))
			{
				playerFrog.set_hit();
			}
		}
	}
}



