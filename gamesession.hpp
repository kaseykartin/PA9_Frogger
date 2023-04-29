#include "VehicleWrapper.hpp"
#include "logwrapper.hpp"
#include "map.hpp"

class GameSession {

public:

	GameSession(); // Constructor

	void initializeWindow();

	void runGame(); // Run iteration of game
	void winConditionHandler(bool& isGameOver); // Handles frog death and level clear

	void displayGameOverScreen();

	int calculateScore();

private:

	int _score; // Score for a single run
	int _sessionHighScore;

	// Controllers for logs and vehicles
	logWrapper _logController;
	vehicleWrapper _vehicleController;

	Frog _frogPlayer; // User

	sf::RenderWindow _window; // Game window
	sf::Font _font; // Game font
};