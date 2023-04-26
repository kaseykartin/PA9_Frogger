#include "log.hpp"
#include <array>
#include <vector>

class logWrapper {
public:
	logWrapper() {};

	void spawn_logs_1(sf::RenderWindow& window);

	void update(sf::RenderWindow& window);

private:
	std::vector<Log> logs;
};