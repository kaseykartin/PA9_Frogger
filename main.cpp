
#include "SFML/Graphics.hpp"
#include "frog.hpp"
#include "map.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    Frog frog;

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
        window.display();
    }

    return 0;
}