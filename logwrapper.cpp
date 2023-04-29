/*
 * logWrapper.hpp
 *
 * Description: This file contains the declaration of the logWrapper class.
 *              It serves as a wrapper for the logs in the game, encapsulating the management of logs.
 *              The class handles the spawning, despawning, updating, and drawing of logs in the game.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "logwrapper.hpp"

// Spawns logs (speed based on the level input)
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

	// Increment speed based on level input
	if (level > 0) {
		for (auto& log : logs) {
			log.incrementSpeed(level);
		}
	}
}

// Clear all logs
void logWrapper::despawn_logs(sf::RenderWindow& window) {
	logs.clear();
}


void logWrapper::update(sf::RenderWindow& window, Frog& playerFrog)
{
	bool frogOnLog = false;

	for (Log& log : logs) // Check each log
	{
		if (log.check_frog(playerFrog)) // Check if the frog is on the log
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

	// If the frog touches the water, register a hit 
	if (!frogOnLog && playerFrog.get_y() > 48 && playerFrog.get_y() < 349 ||
		playerFrog.get_x() + 50 > 1200 || playerFrog.get_x() < 0)
	{
		playerFrog.set_hit();
	}
}

// Draw each log
void logWrapper::draw(sf::RenderWindow& window)
{
	for (Log& log : logs)
	{
		log.draw(window);
	}
}



