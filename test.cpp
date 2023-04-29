/*
 * Test.cpp
 *
 * Description: This file contains the declaration of the Test class, which is responsible for running various tests
 *              to verify the functionality of the game components.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "Test.hpp"

void Test::testCalculateScore() {

    // Test the calculateScore() function
    int score1 = (749 - (1800)) * 10 + (7500 * 2);

    // Test the calculateScore() function
    int score2 = (749 - (500)) * 10 + (7500 * 6);

    // Test the calculateScore() function
    int score3 = (749 - (2000)) * 10 + (7500 * 0);

    std::cout << "Expected output: 4490, Actual output: " << score1 << std::endl;
    std::cout << "Expected output: 47490, Actual output: " << score2 << std::endl;
    std::cout << "Expected output: -12510, Actual output: " << score3 << std::endl << std::endl;;

    if (score1 == 4490 && score2 == 47490 && score3 == -12510) std::cout << "CALCULATE SCORE SUCCESS" << std::endl << std::endl;
}

// Move away from spawn point for success
void Test::testMovement() {

    sf::RenderWindow window;
    window.create(sf::VideoMode(1200, 800), "Test!"); // Create display window

    Frog test;
    test.set_x(600);
    test.set_y(400);

    // Spawn point marker
    sf::RectangleShape rectangle(sf::Vector2f(49, 49));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(600, 400);

    

    bool leftChecked = false, rightChecked = false, upChecked = false, downChecked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // User closes game window
                window.close();
            window.clear();
            window.draw(rectangle);
            test.draw(window);
            test.move();
            window.display();
        }
        
        // Check all directions
        if (test.get_x() < 600 && !leftChecked) {
            std::cout << "Left movement success" << std::endl;
            leftChecked = true;

        }
        if (test.get_x() > 600 && !rightChecked) {
            std::cout << "Right movement success" << std::endl;
            rightChecked = true;

        }
        if (test.get_y() > 400 && !downChecked) {
            std::cout << "Down movement success" << std::endl;
            downChecked = true;

        }
        if (test.get_y() < 400 && !upChecked) {
            std::cout << "Up movement success" << std::endl;
            upChecked = true;

        }

        // If all directions are successful
        if (leftChecked && rightChecked && downChecked && upChecked) {
            std::cout << std::endl << "MOVEMENT SUCCESS" << std::endl << std::endl;
            return; // Exit test case upon success
        }
    }
}

// Test collision detection
void Test::testCollision() {
    sf::RenderWindow window;
    window.create(sf::VideoMode(1200, 800), "Test!"); // Create display window
    window.setFramerateLimit(60);

    vehicleWrapper testcontroller;

    Frog test;
    test.set_x(600);
    test.set_y(200);

    testcontroller.spawn_vehicles_1(window, 1);

    bool successdetected = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // User closes game window
                window.close();
            
        }

        window.clear();
        test.draw(window);
        test.move();

        testcontroller.update(window, test);

        window.display();

        // If the hit detection is successful
        if (test.get_hit() && !successdetected) {
            std::cout << std::endl << "COLLISION SUCCESS" << std::endl << std::endl;
            successdetected = true;
            return;
        }
    }
}

// Visually discern menu success
void Test::testMenu() {
    FroggyAppWrapper test;

    test.handleMenu();
}

// Visually discern controller spawn/movement success
void Test::testControllers()
{

    Frog placeholder;

    sf::RenderWindow window;
    window.create(sf::VideoMode(1200, 800), "Test!"); // Create display window
    window.setFramerateLimit(60);

    vehicleWrapper vController;
    logWrapper lController;

    vController.spawn_vehicles_1(window, 1);
    lController.spawn_logs_1(window, 1);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // User closes game window
                window.close();

        }

        window.clear();

        vController.update(window, placeholder);

        lController.update(window, placeholder);
        lController.draw(window);

        window.display();
    }
}

void Test::runTests()
{
    testCalculateScore();
    testMovement();
    testCollision();
    testMenu();
    testControllers();
}