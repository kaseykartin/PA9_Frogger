
#include "SFML/Graphics.hpp"
#include "frog.hpp"
#include "map.hpp"
#include "car.hpp"
#include "bus.hpp"

int main()
{
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

    return 0;
}