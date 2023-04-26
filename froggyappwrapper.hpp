#pragma once

#include "frog.hpp"
#include "map.hpp"
#include "car.hpp"
#include "bus.hpp"

class FroggyAppWrapper {

public:

	FroggyAppWrapper(); // Default constructor
	
	void startApplication(); // Contains overarching application logic 
	
	bool handleMenu(); // Display menu and handle menu events
	void newGame(); // Start a new game
	void handleOptionsMenu();
	void updateVolume();
private:

	sf::RenderWindow _window; // Menu window

	int _highScore; // Session highscore
	sf::Font _font; // Main font

	// Settings
	bool _soundEnabled;
	int _volume;
	int _storedVol; // Remember previous volume setting when user chooses to toggle mute

	sf::Music menuMusic;
	sf::Music gameMusic;

};