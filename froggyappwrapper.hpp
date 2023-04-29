/*
 * FroggyAppWrapper.h
 *
 * Description: This file contains the declaration of the FroggyAppWrapper class.
 *              It serves as a wrapper for the Froggy application, encapsulating the main application logic.
 *              The class manages the menu, game session, and settings related to sound and volume.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */

#pragma once

#include "gamesession.hpp"

class FroggyAppWrapper {

public:

	FroggyAppWrapper(); // Default constructor

	void startApplication(); // Contains overarching application logic 

	void createMenuWindow();
	bool handleMenu(); // Display menu and handle menu events
	void newGame(); // Start a new game
	void displayInstructions();
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