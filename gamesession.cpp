/*
 * gamesession.hpp
 *
 * Description: This file contains the declaration of the GameSession class.
 *              It represents a session of the Frogger game and manages the game logic.
 *              The class handles the initialization of the game window, spawning and despawning of objects,
 *              updating and drawing the game objects, handling win/loss conditions, and displaying the game over screen.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "gamesession.hpp"

// Constructor
GameSession::GameSession() {
	
	_score = 0;
	_sessionHighScore = 0;
    _levelsCleared = 0;

    _isGameOver = false;
    _displayGameOver = false;

    _quitGame = false;
}

// Initialize game window
void GameSession::initializeWindow() {
    _window.create(sf::VideoMode(1200, 800), "Frogger!"); // Create display window
    _window.setFramerateLimit(60); // Set the frame rate to 60 frames per second (you can adjust this value as needed)

    // Load the font
    if (!_font.loadFromFile("arial.ttf")) {
        // If the font file couldn't be loaded, display the error message in a new window
        sf::RenderWindow errorWindow(sf::VideoMode(400, 200), "Error");
        sf::Font errorFont;
        errorFont.loadFromFile("arial.ttf");
        sf::Text errorMessage("Error: Font file could not be loaded", errorFont, 20);
        errorMessage.setPosition(50, 80);
        errorWindow.draw(errorMessage);
        errorWindow.display();
        while (errorWindow.isOpen()) {
            sf::Event errorEvent;
            while (errorWindow.pollEvent(errorEvent)) {
                if (errorEvent.type == sf::Event::Closed) {
                    errorWindow.close();
                }
            }
        }
    }

    // Set up the on-screen score counter
    scoreText.setFont(_font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);
}

int GameSession::runGame()
{
    initializeWindow(); // Setup window

    // Spawn objects
    _vehicleController.spawn_vehicles_1(_window, _levelsCleared);
    _logController.spawn_logs_1(_window, _levelsCleared);

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // User closes game window
                _window.close();
        }

        if (!_isGameOver)
        {
            _window.clear();
            draw_map(_window); 
            _logController.update(_window, _frogPlayer);
            _logController.draw(_window);
            _frogPlayer.draw(_window);
            _frogPlayer.move();
           _vehicleController.update(_window, _frogPlayer);
            
            _score = calculateScore(); // Update the score
            scoreText.setString("Score: " + std::to_string(_score)); // Set the score text
            _window.draw(scoreText); // Draw the score text

            winConditionHandler();

            _window.display();

        }
        else
        {
            if (!_displayGameOver)
            {   
                _displayGameOver = true;
                displayGameOverScreen();
                
            }
        }

        if (_quitGame) break;
    }

    return _sessionHighScore;
}

// Check win/loss conditions and apply appropriate actions
void GameSession::winConditionHandler()
{
    if (_frogPlayer.get_hit()) // Collision is registered 
    {
        _isGameOver = true;

        _score -= 500; // Subtract the points earned for travelling to death tile
        
        // Update high score if needed
        if (_score > _sessionHighScore)
        {
            _sessionHighScore = _score;
        }
    }
    else if (_frogPlayer.get_y() < 48) // Frog reached the end of the level, reset everything
    {

        _levelsCleared++;

        // Respawn objects
        _vehicleController.despawn_vehicles(_window);
        _logController.despawn_logs(_window);
        _vehicleController.spawn_vehicles_1(_window, _levelsCleared);
        _logController.spawn_logs_1(_window, _levelsCleared);

        // Reset player position to start
        _frogPlayer.reset(550, 749);

        // Reset score
        _score = 0;
    }
}

void GameSession::displayGameOverScreen()
{
    sf::Text gameOverText;
    gameOverText.setFont(_font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(500, 250);

    // Display session high score and score achieved
    sf::Text scoreText;
    scoreText.setFont(_font);
    scoreText.setCharacterSize(28);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(500, 330);
    scoreText.setString("Session High Score: " + std::to_string(_sessionHighScore) +
        "\nScore Achieved: " + std::to_string(_score));

    // Display options
    sf::Text playAgainText;
    playAgainText.setFont(_font);
    playAgainText.setCharacterSize(24);
    playAgainText.setFillColor(sf::Color::White);
    playAgainText.setPosition(500, 500);
    playAgainText.setString("Play Again");

    sf::Text exitText;
    exitText.setFont(_font);
    exitText.setCharacterSize(24);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(500, 550);
    exitText.setString("Exit to Main Menu");

    bool isMouseOverPlayAgain = false;
    bool isMouseOverExit = false;
    bool playAgainClicked = false; // Flag to indicate if "Play Again" is clicked

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                if (playAgainText.getGlobalBounds().contains(mousePos))
                {
                    isMouseOverPlayAgain = true;
                    isMouseOverExit = false;
                }
                else if (exitText.getGlobalBounds().contains(mousePos))
                {
                    isMouseOverPlayAgain = false;
                    isMouseOverExit = true;
                }
                else
                {
                    isMouseOverPlayAgain = false;
                    isMouseOverExit = false;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                if (playAgainText.getGlobalBounds().contains(mousePos))
                {
                    // Handle the "Play Again" menu item click
                    std::cout << "Play Again clicked" << std::endl;

                    resetGame();
                    _isGameOver = false; // Reset the game over flag
                    _displayGameOver = false; // Reset the display game over flag
                    playAgainClicked = true; // Set the flag to indicate play again is clicked
                    
                }
                else if (exitText.getGlobalBounds().contains(mousePos))
                {
                    // Handle the "Exit" menu item click
                    std::cout << "Exit clicked" << std::endl;
                    _quitGame = true;
                    // Additional actions for exiting the game or going back to the main menu
                }
            }
        }

        _window.clear();

        _window.draw(gameOverText);
        _window.draw(scoreText);
        _window.draw(playAgainText);
        _window.draw(exitText);

        if (isMouseOverPlayAgain)
        {
            playAgainText.setFillColor(sf::Color::Red);
        }
        else
        {
            playAgainText.setFillColor(sf::Color::White);
        }

        if (isMouseOverExit)
        {
            exitText.setFillColor(sf::Color::Red);
        }
        else
        {
            exitText.setFillColor(sf::Color::White);
        }

        _window.display();

        if (playAgainClicked || _quitGame) {
            break; // Exit the while loop if "Play Again" is clicked
        }
    }
}

void GameSession::resetGame()
{
    // Reset the game state to start a new game
    _levelsCleared = 0;

    // Respawn objects
    _vehicleController.despawn_vehicles(_window);
    _logController.despawn_logs(_window);
    _vehicleController.spawn_vehicles_1(_window, _levelsCleared);
    _logController.spawn_logs_1(_window, _levelsCleared);

    // Reset player position to start
    _frogPlayer.reset(550, 749);

    // Reset score
    _score = 0;
}

int GameSession::calculateScore()
{
    int score = (749 - (_frogPlayer.get_y())) * 10 + (7500 * _levelsCleared);  // Assign score based on frog's vertical position
    return score;
}

// Testing purposes

Frog GameSession::getFrogPlayer() {
    return _frogPlayer;
}

void GameSession::setLevelsCleared(int newLevel) {
    _levelsCleared = newLevel;
}



