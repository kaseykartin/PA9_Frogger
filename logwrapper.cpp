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

void logWrapper::update(sf::RenderWindow& window, Frog& playerFrog)
{
	bool frog_on_log = 0;


	for (Log& log : logs)
	{
		if (0 == frog_on_log && 0 == playerFrog.get_hit())
		{
			frog_on_log = log.check_frog(playerFrog);
			log.update(frog_on_log, playerFrog);
		}
	}

	if (0 == frog_on_log && 48 < playerFrog.get_y() && playerFrog.get_y() < 349)
	{
		playerFrog.set_hit();
	}

}

void logWrapper::draw(sf::RenderWindow& window)
{
	for (Log& log : logs)
	{
		log.draw(window);
	}
}

