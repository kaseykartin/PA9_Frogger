#include "gamesession.hpp"

// Constructor
GameSession::GameSession() {
	
	_score = 0;
	_sessionHighScore = 0;

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
}

void GameSession::runGame()
{
    initializeWindow(); // Setup window

    // Spawn objects
    _vehicleController.spawn_vehicles_1(_window);
    _logController.spawn_logs_1(_window);

    bool isGameOver = false;
    bool displayGameOver = false;

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // User closes game window
                _window.close();
        }

        if (!isGameOver)
        {
            _window.clear();
            draw_map(_window); 
            _logController.update(_window, _frogPlayer);
            _logController.draw(_window);
            _frogPlayer.draw(_window);
            _frogPlayer.move();
           _vehicleController.update(_window, _frogPlayer);
            winConditionHandler(isGameOver);
            _window.display();

        }
        else
        {
            if (!displayGameOver)
            {
                displayGameOverScreen();
                displayGameOver = true;
            }
        }
    }
}



void GameSession::winConditionHandler(bool& isGameOver)
{
    if (_frogPlayer.get_hit())
    {
        isGameOver = true;
    }
    else if (_frogPlayer.get_y() < 48)
    {
        // Frog reached the end of the level, reset everything

        // Calculate score and update high score if needed
        int currentScore = calculateScore();
        if (currentScore > _sessionHighScore)
        {
            _sessionHighScore = currentScore;
        }

        // Respawn objects
        _vehicleController.despawn_vehicles(_window);
        _logController.despawn_logs(_window);
        _vehicleController.spawn_vehicles_1(_window);
        _logController.spawn_logs_1(_window);

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
        "\nScore Achieved: " + std::to_string(calculateScore()));

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
                    // Additional actions for restarting the game
                }
                else if (exitText.getGlobalBounds().contains(mousePos))
                {
                    // Handle the "Exit" menu item click
                    std::cout << "Exit clicked" << std::endl;
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
    }
}

int GameSession::calculateScore()
{
    int score = _frogPlayer.get_y() * 10;  // Assign score based on frog's vertical position
    return score;
}




