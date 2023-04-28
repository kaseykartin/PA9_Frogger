#pragma once

#include "log.hpp"
#include "frog.hpp"

class logWrapper {
public:
	logWrapper() {};

	void spawn_logs_1(sf::RenderWindow& window);

	void update(sf::RenderWindow& window, Frog& playerFrog);

	void draw(sf::RenderWindow& window);

private:
	std::vector<Log> logs;
};