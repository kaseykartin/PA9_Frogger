#include "froggyappwrapper.hpp"

// Default constructor
FroggyAppWrapper::FroggyAppWrapper() {
	
    int highScore = 0; // Set session highscore at 0
    bool isSoundOn = true; // Sound on by default

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

    sf::Text title("FROGGY", _font, 100);
    title.setPosition(200, 100);

    sf::Text start("Start Game", _font, 30);
    start.setPosition(330, 300);

    sf::Text options("Options", _font, 30);
    options.setPosition(350, 350);

    sf::Text quit("Quit Game", _font, 30);
    quit.setPosition(335, 400);

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
            }
        }

        _window.clear();

        // Draw the menu items to the window
        _window.draw(title);
        _window.draw(start);
        _window.draw(options);
        _window.draw(quit);

        // Display the window
        _window.display();
    }

    return false; // User chose to exit
}

void FroggyAppWrapper::newGame() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    Frog frog;
    Car Car1(12);
    Bus Car2(13);
    Car Car3(11);
    Bus Car4(10);
    Car Car5(9);
    Bus Car6(8);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        draw_map(window);
        frog.draw(window);
        frog.move();
        Car1.draw(window);
        Car1.update();

        Car2.draw(window);
        Car2.update();

        Car3.draw(window);
        Car3.update();

        Car4.draw(window);
        Car4.update();

        Car5.draw(window);
        Car5.update();

        Car6.draw(window);
        Car6.update();

        window.display();
    }
}

// Display options menu and handle menu events
void FroggyAppWrapper::handleOptionsMenu() {
    // Create the options menu items
    sf::Text title("Options", _font, 50);
    title.setPosition(300, 50);

    sf::Text sound("Sound: ON", _font, 30);
    sound.setPosition(300, 200);

    sf::Text back("Back", _font, 30);
    back.setPosition(300, 300);

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
                sf::Vector2f mousePos(sf::Mouse::getPosition(_window));

                // Check which menu item was clicked based on the position of the mouse
                if (sound.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Sound" menu item click
                    if (_soundEnabled) {
                        sound.setString("Sound: OFF");
                        _soundEnabled = false;
                    }
                    else {
                        sound.setString("Sound: ON");
                        _soundEnabled = true;
                    }
                }
                else if (back.getGlobalBounds().contains(mousePos)) {
                    // Handle the "Back" menu item click
                    return;
                }
            }
        }

        // Draw the options menu items to the window
        _window.clear();
        _window.draw(title);
        _window.draw(sound);
        _window.draw(back);

        // Display the window
        _window.display();
    }
}
