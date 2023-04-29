/*
 * gamesession.hpp
 *
 * Description: This file contains the necessary includes and declarations for the GameSession class,
 *              which manages the main game logic and controls the game flow.
 *              It includes the necessary header files for the VehicleWrapper, LogWrapper, and Map classes.
 *
 * Author: Brandon Xu
 * Date: 2/28/23
 */


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

	//Testing purposes
	Frog getFrogPlayer();
	void setLevelsCleared(int newLevel);

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