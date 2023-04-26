#include "logwrapper.hpp"

void logWrapper::spawn_logs_1(sf::RenderWindow& window)
{
	logs.clear();

	//spawning in logs and loges row by row using vectors of each
	//first "row" starting from the top
	logs.push_back(Log(1, 1));
	logs.push_back(Log(8, 1));
	logs.push_back(Log(16, 1));

	//second row
	logs.push_back(Log(1, 2));
	logs.push_back(Log(8, 2));
	logs.push_back(Log(16, 2));

	//third row
	logs.push_back(Log(1, 3));
	logs.push_back(Log(12, 3));

	//fourth row
	logs.push_back(Log(1, 4));
	logs.push_back(Log(8, 4));
	logs.push_back(Log(16, 4));

	//fifth row
	logs.push_back(Log(1, 5));
	logs.push_back(Log(12, 5));

	//sixth row
	logs.push_back(Log(1, 6));
	logs.push_back(Log(12, 6));
}

void logWrapper::update(sf::RenderWindow& window)
{
	for (Log& log : logs)
	{
		log.draw(window);
		log.update();
	}
	for (Log& log : logs)
	{
		log.draw(window);
		log.update();
	}
}