/*
 * logWrapper.h
 *
 * Description: This file contains the declaration of the logWrapper class.
 *              It manages the spawning, despawning, updating, and drawing of logs in the game.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#pragma once

#include "log.hpp"
#include "frog.hpp"

class logWrapper {
public:

	void spawn_logs_1(sf::RenderWindow& window, int level); // Spawns logs (speed based on the level input)
	void despawn_logs(sf::RenderWindow& window);

	void update(sf::RenderWindow& window, Frog& playerFrog);

	void draw(sf::RenderWindow& window);

private:
	std::vector<Log> logs; // Vector containing the logs that it manages
};