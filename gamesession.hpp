#include "VehicleWrapper.hpp"
#include "logwrapper.hpp"
#include "map.hpp"

class GameSession {

public:

	GameSession(); // Constructor

	void initializeWindow();

	int runGame(); // Run iteration of game, returns session high score
	void winConditionHandler(); // Handles frog death and level clear

	void displayGameOverScreen();
	void resetGame();

	int calculateScore();

private:

	int _score; // Score for a single run
	int _sessionHighScore;
	sf::Text scoreText; // On-screen score counter

	int _levelsCleared; // Number of times player reached endzone

	// Controllers for logs and vehicles
	logWrapper _logController;
	vehicleWrapper _vehicleController;

	Frog _frogPlayer; // User

	sf::RenderWindow _window; // Game window
	sf::Font _font; // Game font

	// Game state flags
	bool _isGameOver;
	bool _displayGameOver;
	bool _quitGame; // User has chosen to quit the game
};

// Helper color animation function
sf::Color HSVtoRGB(float hue, float saturation, float value);