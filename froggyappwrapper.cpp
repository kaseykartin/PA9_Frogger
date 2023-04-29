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
}

void FroggyAppWrapper::createMenuWindow() {
    _window.create(sf::VideoMode(800, 600), "Frogger");
}

void FroggyAppWrapper::startApplication() {

    while (handleMenu()) {
        newGame();
    }
}

// Display menu and handle menu events (return true if user chose to start a new game)
bool FroggyAppWrapper::handleMenu() {

    createMenuWindow();

    menuMusic.play();

    // Load and display the high score
    sf::Text highScoreText("High Score: " + std::to_string(_highScore), _font, 22);
    highScoreText.setPosition(340, 250);

    sf::Text title("FROGGY", _font, 100);
    title.setPosition(200, 100);

    sf::Text start("Start Game", _font, 30);
    start.setPosition(330, 300);

    sf::Text instruct("How To Play", _font, 30);
    instruct.setPosition(325, 350);

    sf::Text options("Options", _font, 30);
    options.setPosition(350, 400);

    sf::Text quit("Quit Game", _font, 30);
    quit.setPosition(335, 450);

    // High score animation variables
    sf::Clock clock;
    float time = 0;

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

                // Check if the mouse is within the bounding rectangle of the "How To Play" text
                if (instruct.getGlobalBounds().contains(mousePos)) {
                    // If it is, change the fill color of the text to red
                    instruct.setFillColor(sf::Color::Red);
                }
                else {
                    // If it's not, set the fill color back to white
                    instruct.setFillColor(sf::Color::White);
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

                else if (instruct.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Options" menu item click
                    std::cout << "instructions pressed" << std::endl;

                    //We will stay in this window to show options
                    displayInstructions();
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
            }
        }

        _window.clear();

        // Highscore animation with color change
        time = clock.getElapsedTime().asSeconds();
        float r = std::sin(0.6f * time + 0) * 127 + 128;
        float g = std::sin(0.6f * time + 2) * 127 + 128;
        float b = std::sin(0.6f * time + 4) * 127 + 128;
        sf::Color hsColor(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b));
        highScoreText.setFillColor(hsColor);

        // Animate Frogger title with frog-inspired hues
        time = clock.getElapsedTime().asSeconds();
        float hue = std::fmod(60.0f * time, 360.0f); // Vary the hue component from 0 to 360
        sf::Color titleColor = HSVtoRGB(hue, 1.0f, 1.0f); // Convert HSV to RGB color
        title.setFillColor(titleColor);

        // Draw the menu items to the window
        _window.draw(highScoreText); // Draw the high score text
        _window.draw(title);
        _window.draw(start);
        _window.draw(instruct);
        _window.draw(options);
        _window.draw(quit);
        
        // Display the window
        _window.display();
    }

    return false; // User chose to exit
}

void FroggyAppWrapper::newGame() {

    gameMusic.play();

    GameSession game; // Create new game session
    int sessionScore = game.runGame(); // Start game
    
    if (sessionScore > _highScore) _highScore = sessionScore; // Update highscore appropriately

    gameMusic.stop();
}

// Display instructions on how to play
void FroggyAppWrapper::displayInstructions() {
    // Create the instructions items
    sf::Text rules("RULES", _font, 40);
    rules.setPosition(340, 30);

    sf::Text rule1("1. Use the arrow keys to move the frog across the road and river", _font, 20);
    rule1.setPosition(130, 110);

    sf::Text rule2("2. Avoid the obstacles such as cars and logs", _font, 20);
    rule2.setPosition(130, 150);

    sf::Text rule3("3. Reach the other side of the river to win points", _font, 20);
    rule3.setPosition(130, 190);

   /* sf::Text rule4("4. Collect bonuses for extra points", _font, 20);
    rule4.setPosition(20, 220);

    sf::Text rule5("5. Don't fall into the water or get hit by a car", _font, 20);
    rule5.setPosition(20, 260);

    sf::Text rule6("6. Press 'P' to pause the game and 'ESC' to quit", _font, 20);
    rule6.setPosition(20, 300);*/

    sf::Text back("Back", _font, 30);
    back.setPosition(370, 250);

    

    while (_window.isOpen()) {
        sf::Event event;

        while (_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                _window.close();
            }

            if (event.type == sf::Event::MouseMoved) {
                // Get the position of the mouse relative to the window
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                // Check if the mouse is within the bounding rectangle of the "Sound" text
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

                if (back.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Back" menu item click
                    return;
                }
            }
            // Clear the window
            _window.clear(sf::Color::Black);

            _window.draw(rules);
            _window.draw(rule1);
            _window.draw(rule2);
            _window.draw(rule3);
            //_window.draw(rule4);
            //_window.draw(rule5);
            //_window.draw(rule6);

            _window.draw(back);

            // Display the window
            _window.display();
        }
    }

    
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

// Helper color animation function
sf::Color HSVtoRGB(float hue, float saturation, float value) {
    float chroma = value * saturation;
    float huePrime = hue / 60.0f;
    float x = chroma * (1.0f - std::fabs(std::fmod(huePrime, 2.0f) - 1.0f));
    float m = value - chroma;

    sf::Color color;
    if (huePrime >= 0 && huePrime < 1) {
        color = sf::Color(static_cast<sf::Uint8>((chroma + m) * 255), static_cast<sf::Uint8>((x + m) * 255), static_cast<sf::Uint8>(m * 255));
    }
    else if (huePrime >= 1 && huePrime < 2) {
        color = sf::Color(static_cast<sf::Uint8>((x + m) * 255), static_cast<sf::Uint8>((chroma + m) * 255), static_cast<sf::Uint8>(m * 255));
    }
    else if (huePrime >= 2 && huePrime < 3) {
        color = sf::Color(static_cast<sf::Uint8>(m * 255), static_cast<sf::Uint8>((chroma + m) * 255), static_cast<sf::Uint8>((x + m) * 255));
    }
    else if (huePrime >= 3 && huePrime < 4) {
        color = sf::Color(static_cast<sf::Uint8>(m * 255), static_cast<sf::Uint8>((x + m) * 255), static_cast<sf::Uint8>((chroma + m) * 255));
    }
    else if (huePrime >= 4 && huePrime < 5) {
        color = sf::Color(static_cast<sf::Uint8>((x + m) * 255), static_cast<sf::Uint8>(m * 255), static_cast<sf::Uint8>((chroma + m) * 255));
    }
    else if (huePrime >= 5 && huePrime < 6) {
        color = sf::Color(static_cast<sf::Uint8>((chroma + m) * 255), static_cast<sf::Uint8>(m * 255), static_cast<sf::Uint8>((x + m) * 255));
    }

    return color;
}