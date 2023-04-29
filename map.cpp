/*
 * map.hpp
 *
 * Description: This file contains the implementation of the draw_map function, which is responsible for drawing the game map.
 *              It draws the endzone, river, middle intersection, and start areas using various shapes and colors.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "map.hpp"

void draw_map(sf::RenderWindow& window)
{
	// Endzone
	sf::RectangleShape endZone(sf::Vector2f(1200, 50));
	endZone.setFillColor(sf::Color::Green);
	endZone.setOrigin(sf::Vector2f(0, 0));

	window.draw(endZone);

	sf::RectangleShape river(sf::Vector2f(1200, 300));
	river.setFillColor(sf::Color::Blue);
	river.setOrigin(sf::Vector2f(0, -50));

	window.draw(river);
	
	// Middle intersection
	sf::RectangleShape mid(sf::Vector2f(1200, 50));
	mid.setFillColor(sf::Color(100, 100, 100));
	mid.setOrigin(sf::Vector2f(0, -350));

	window.draw(mid);
	
    // Start
    sf::RectangleShape start(sf::Vector2f(1200, 100));
	start.setFillColor(sf::Color(100, 100, 100));
    start.setOrigin(sf::Vector2f(0, -700));

	window.draw(start);
}

	

	
