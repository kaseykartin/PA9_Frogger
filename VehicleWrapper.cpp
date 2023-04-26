#include "VehicleWrapper.hpp"

void vehicleWrapper::spawn_vehicles_1(sf::RenderWindow& window)
{
	cars.clear();
	buses.clear();

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

void vehicleWrapper::update(sf::RenderWindow& window)
{
	for (Car& car : cars)
	{
		car.draw(window);
		car.update();
	}
	for (Bus& bus : buses)
	{
		bus.draw(window);
		bus.update();
	}
}

/*
Car Car1(0, 12);
Bus Car2(0, 13);
Car Car3(0, 11);
Bus Car4(0, 10);
Car Car5(0, 9);
Bus Car6(0, 8)*/;