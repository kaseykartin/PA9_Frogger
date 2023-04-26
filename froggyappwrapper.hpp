#include "frog.hpp"
#include "map.hpp"

class FroggyAppWrapper {

public:

	FroggyAppWrapper(); // Default constructor

	void startApplication(); // Contains overarching application logic 

	bool handleMenu(); // Display menu and handle menu events
	void newGame(); // Start a new game
	void handleOptionsMenu();
private:

	sf::RenderWindow _window; // Menu window

	int _highScore; // Session highscore
	sf::Font _font; // Main font

	// Settings
	bool _soundEnabled;

};