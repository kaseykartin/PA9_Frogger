#include "froggyappwrapper.hpp"

// Default constructor
FroggyAppWrapper::FroggyAppWrapper() {

    _highScore = 0; // Set session highscore at 0
    _soundEnabled = true; // Sound on by default
    _volume = 100;
    _storedVol = 100;

    menuMusic.openFromFile("audio/menumusic.wav");
    gameMusic.openFromFile("audio/gamemusic.wav");
    menuMusic.setLoop(true);
    gameMusic.setLoop(true);

    menuMusic.setVolume(100);
    gameMusic.setVolume(20); // Wav file of gamemusic is louder by default, so compensate here

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

    // Initialize the window
    _window.create(sf::VideoMode(800, 600), "Frogger");
}

void FroggyAppWrapper::startApplication() {

    if (handleMenu()) {
        newGame();
    }
}

// Display menu and handle menu events (return true if user chose to start a new game)
bool FroggyAppWrapper::handleMenu() {

    menuMusic.play();

    sf::Text title("FROGGY", _font, 100);
    title.setPosition(200, 100);

    sf::Text start("Start Game", _font, 30);
    start.setPosition(330, 300);

    sf::Text options("Options", _font, 30);
    options.setPosition(350, 350);

    sf::Text quit("Quit Game", _font, 30);
    quit.setPosition(335, 400);

    sf::Text rules("How to Play", _font, 30);
    rules.setPosition(340, 450);

    // Main menu loop
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            // Handle menu events
            if (event.type == sf::Event::Closed) {
                _window.close();
            }

            // Handle mouse movement events
            if (event.type == sf::Event::MouseMoved) {
                // Get the position of the mouse relative to the window
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                // Check if the mouse is within the bounding rectangle of the "Start Game" text
                if (start.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    start.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    start.setFillColor(sf::Color::White);
                }

                // Check if the mouse is within the bounding rectangle of the "Options" text
                if (options.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    options.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    options.setFillColor(sf::Color::White);
                }

                // Check if the mouse is within the bounding rectangle of the "Quit Game" text
                if (quit.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    quit.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    quit.setFillColor(sf::Color::White);
                }
            }

            // Handle mouse button press events
            if (event.type == sf::Event::MouseButtonPressed) {
                // Get the position of the mouse relative to the window
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                // Check which menu item was clicked based on the position of the mouse
                if (start.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Start Game" menu item click
                    std::cout << "start game pressed" << std::endl;

                    menuMusic.stop();
                    // Close window (new window will be opened for the game)
                    _window.close();
                    return true;
                }
                else if (options.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Options" menu item click
                    std::cout << "options pressed" << std::endl;

                    //We will stay in this window to show options
                    handleOptionsMenu();
                }
                else if (quit.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Quit Game" menu item click
                    _window.close();
                }
                else if (rules.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    rules.setFillColor(sf::Color::Red);

                    // Handle the "How to Play" menu item click
                    if (event.type == sf::Event::MouseButtonPressed) {
                        displayRules();
                    }
                }
                else {
                    // If it's not, set the fill color back to white
                    rules.setFillColor(sf::Color::White);
                }

            }
        }


        _window.clear(sf::Color(25,25,25));

        // Draw the menu items to the window
        _window.draw(title);
        _window.draw(start);
        _window.draw(options);
        _window.draw(quit);
        _window.draw(rules);
        // Display the window
        _window.display();
    }


    return false; // User chose to exit
}

void FroggyAppWrapper::newGame() {

    gameMusic.play();

    GameSession game; // Create new game session
    game.runGame(); // Start game
    
    gameMusic.stop();
}

// Display options menu and handle menu events
void FroggyAppWrapper::handleOptionsMenu() {
    // Create the options menu items
    sf::Text title("Options", _font, 50);
    title.setPosition(330, 50);

    sf::Text sound("Sound: ON", _font, 30);
    sound.setPosition(300, 200);

    sf::Text volumeLabel("Volume:", _font, 30);
    volumeLabel.setPosition(300, 250);

    sf::RectangleShape volumeSlider(sf::Vector2f(200, 10));
    volumeSlider.setFillColor(sf::Color::White);
    volumeSlider.setPosition(300, 290);

    sf::Text volumeUp("+", _font, 40);
    volumeUp.setPosition(520, 250);

    sf::Text volumeDown("-", _font, 50);
    volumeDown.setPosition(522.5, 280);

    sf::Text back("Back", _font, 30);
    back.setPosition(360, 400);

    // Options menu loop
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            // Handle menu events
            if (event.type == sf::Event::Closed) {
                _window.close();
            }

            // Handle mouse movement events
            if (event.type == sf::Event::MouseMoved) {
                // Get the position of the mouse relative to the window
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                // Check if the mouse is within the bounding rectangle of the "Sound" text
                if (sound.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    sound.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    sound.setFillColor(sf::Color::White);
                }

                //// Check if the mouse is within the bounding rectangle of the volume slider
                //if (volumeSlider.getGlobalBounds().contains(mousePos)) {
                //    // If it is, change the fill color of the slider to red
                //    volumeSlider.setFillColor(sf::Color::Red);
                //}
                //else {
                //    // If it's not, set the fill color back to white
                //    volumeSlider.setFillColor(sf::Color::White);
                //}

                // Check if the mouse is within the bounding rectangle of the volume up button
                if (volumeUp.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the button to red
                    volumeUp.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    volumeUp.setFillColor(sf::Color::White);
                }

                // Check if the mouse is within the bounding rectangle of the volume down button
                if (volumeDown.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the button to red
                    volumeDown.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    volumeDown.setFillColor(sf::Color::White);
                }

                // Check if the mouse is within the bounding rectangle of the "Back" text
                if (back.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    back.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    back.setFillColor(sf::Color::White);
                }
            }

            // Handle mouse button press events
            if (event.type == sf::Event::MouseButtonPressed) {
                // Get the position of the mouse relative to the window
                sf::Vector2f mousePos(sf::Mouse::
                    getPosition(_window));

                // Check if the mouse clicked the "Sound" text
                if (sound.getGlobalBounds().contains(mousePos)) {
                    // Toggle sound on or off
                    if (_soundEnabled) {
                        sound.setString("Sound: OFF");
                        _soundEnabled = false;

                        _storedVol = _volume;
                        _volume = 0;

                    }
                    else {
                        sound.setString("Sound: ON");
                        _soundEnabled = true;

                        _volume = _storedVol;
                    }

                    updateVolume();
                }

                // Check if the mouse clicked the volume up button
                if (volumeUp.getGlobalBounds().contains(mousePos)) {
                    // Increase the volume by 10
                    if (_volume < 100) {
                        _volume += 10;
                        updateVolume();
                        std::cout << _volume << std::endl;
                        volumeSlider.setSize(sf::Vector2f(200 * _volume / 100, 10));
                    }
                }

                // Check if the mouse clicked the volume down button
                if (volumeDown.getGlobalBounds().contains(mousePos)) {
                    // Decrease the volume by 10
                    if (_volume > 0) {
                        _volume -= 10;
                        updateVolume();
                        std::cout << _volume << std::endl;
                        volumeSlider.setSize(sf::Vector2f(200 * _volume / 100, 10));
                    }
                }


                if (back.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Back" menu item click
                    return;
                }
            }

            // Clear the window
            _window.clear(sf::Color::Black);

            // Draw the options menu items
            _window.draw(title);
            _window.draw(sound);
            _window.draw(volumeLabel);
            _window.draw(volumeSlider);
            _window.draw(volumeUp);
            _window.draw(volumeDown);
            _window.draw(back);

            // Display the window
            _window.display();
        }
    }
}

void FroggyAppWrapper::updateVolume() {
    // Convert the volume percentage to a range from 0 to 100
    float volumeRange = _volume / 100.0f;

    // Update the sound volume
    menuMusic.setVolume(100 * volumeRange);
    gameMusic.setVolume(20 * volumeRange);
}

void FroggyAppWrapper::displayRules() {
    sf::RenderWindow rulesWindow(sf::VideoMode(1000, 1000), "Rules");

    sf::Text rules("RULES", _font, 40);
    rules.setPosition(120, 20);

    sf::Text rule1("1. Use the arrow keys to move the frog across the road and river", _font, 20);
    rule1.setPosition(20, 100);

    sf::Text rule2("2. Avoid the obstacles such as cars and logs", _font, 20);
    rule2.setPosition(20, 140);

    sf::Text rule3("3. Reach the other side of the river to win points", _font, 20);
    rule3.setPosition(20, 180);

    sf::Text rule4("4. Collect bonuses for extra points", _font, 20);
    rule4.setPosition(20, 220);

    sf::Text rule5("5. Don't fall into the water or get hit by a car", _font, 20);
    rule5.setPosition(20, 260);

    sf::Text rule6("6. Press 'P' to pause the game and 'ESC' to quit", _font, 20);
    rule6.setPosition(20, 300);

    rulesWindow.draw(rules);
    rulesWindow.draw(rule1);
    rulesWindow.draw(rule2);
    rulesWindow.draw(rule3);
    rulesWindow.draw(rule4);
    rulesWindow.draw(rule5);
    rulesWindow.draw(rule6);
    rulesWindow.display();

    while (rulesWindow.isOpen()) {
        sf::Event event;
        while (rulesWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                rulesWindow.close();
            }
        }
    }
}
