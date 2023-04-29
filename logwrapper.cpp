#include "logwrapper.hpp"

void logWrapper::spawn_logs_1(sf::RenderWindow& window, int level)
{
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

	if (level > 0) {
		for (auto& log : logs) {
			log.incrementSpeed(level);
		}
	}
}

void logWrapper::despawn_logs(sf::RenderWindow& window) {
	logs.clear();
}

void logWrapper::update(sf::RenderWindow& window, Frog& playerFrog)
{
	bool frogOnLog = false;

	for (Log& log : logs)
	{
		if (log.check_frog(playerFrog))
		{
			frogOnLog = true;
			log.setFrogRidingLog(true);  // Set the log's riding status
		}
		else
		{
			log.setFrogRidingLog(false);  // Reset the log's riding status
		}

		log.update(playerFrog);
	}

	if (!frogOnLog && playerFrog.get_y() > 48 && playerFrog.get_y() < 349 ||
		playerFrog.get_x() + 50 > 1200 || playerFrog.get_x() < 0)
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



