/*
 * Frog.hpp
 *
 * Description: This file contains the declaration of the Frog class, representing the player-controlled frog in the game.
 *              The class defines the frog's position, movement, hitbox, and other related functionalities.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#include "frog.hpp"

// Default constructor
Frog::Frog() : x(550) , y(749)
{
    is_hit = false;
	texture.loadFromFile("images/Frog.png");
	sprite.setTexture(texture);
}

// Render frog onto screen
void Frog::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

// Player controlled movement
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

    // Update control key states
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

// Getters
int Frog::get_x()
{
    return x;
}

int Frog::get_y()
{
    return y;
}

void Frog::set_x(int newX) {
    this->x = newX;
}

void Frog::set_y(int newY) {
    this->y = newY;
}


sf::IntRect Frog::get_hitbox()
{
    return sf::IntRect(x, y, 49, 49);
}

bool Frog::get_hit()
{
    return is_hit;
}

// Indicate a collision with frog
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

