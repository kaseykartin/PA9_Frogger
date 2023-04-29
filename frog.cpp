#include "frog.hpp"

Frog::Frog() : x(550) , y(749)
{
    is_hit = false;
	texture.loadFromFile("images/Frog.png");
	sprite.setTexture(texture);
}

void Frog::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Frog::move()
{
    const int cell_size = 50;
    const int screen_width = 1200;
    const int screen_height = 800;

    if (!control_keys[1] && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (y + cell_size < screen_height - cell_size)
        {
            y += cell_size;
        }
    }
    else if (!control_keys[0] && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (y >= 0)
        {
            y -= cell_size;
        }
    }
    else if (!control_keys[2] && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (x - cell_size >= 0)
        {
            x -= cell_size;
        }
    }
    else if (!control_keys[3] && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (x + cell_size < screen_width)
        {
            x += cell_size;
        }
    }

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    // NOTE: commented out to allow frog to die when hit instead of resetting
    //if (this->get_hit() == true) //collision detected
    //{
    //    reset(550, 749); //resets to starting position
    //}
}

void Frog::move(int logSpeed) //move function used within log section
{
    x += logSpeed;
}

int Frog::get_x()
{
    return x;
}

int Frog::get_y()
{
    return y;
}

sf::IntRect Frog::get_hitbox()
{
    return sf::IntRect(x, y, 49, 49);
}

bool Frog::get_hit()
{
    return is_hit;
}

void Frog::set_hit()
{
    is_hit = true;
}

void Frog::reset(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
    is_hit = false;
}
