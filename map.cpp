#include "map.hpp"

void draw_map(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(sf::Vector2f(1200, 100));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOrigin(sf::Vector2f(0, 0));

	window.draw(rectangle);

	sf::RectangleShape rectangle2(sf::Vector2f(1200, 50));
	rectangle2.setFillColor(sf::Color(100,100,100));
	rectangle2.setOrigin(sf::Vector2f(0, -750));

	window.draw(rectangle2);

	sf::RectangleShape rectangle3(sf::Vector2f(1200, 50));
	rectangle3.setFillColor(sf::Color(100, 100, 100));
	rectangle3.setOrigin(sf::Vector2f(0, -400));

	window.draw(rectangle3);
}
