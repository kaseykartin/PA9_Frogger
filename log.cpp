#include "log.hpp"

Log::Log(int x, int y) : MobileGameObject(x, y)
{
	_hitbox = generateHitBox(); // Set unique bus hitbox
	_speed = generateSpeed(); // Set speed 

	_frogRideLog = false;

	if (0 == _direction)
	{
		_texture.loadFromFile("images/shortlog.png");
	}
	else
	{
		_texture.loadFromFile("images/longlog.png");
	}

}

bool Log::check_frog(Frog& playerFrog)
{
	return playerFrog.get_hitbox().intersects(this->get_hitbox());
}

void Log::update(Frog& playerFrog)
{
	_x += (_direction == 0 ? _speed : -_speed);
	if (_x > 1200)
	{
		_x = -100;
	}
	else if (_x < -100)
	{
		_x = 1201;
	}

	if (_frogRideLog)
	{
		playerFrog.move((_direction == 0 ? _speed : -_speed));  // Move the frog along with the log
	}

	// Update hitbox position
	_hitbox.left = _x;
	_hitbox.top = _y;
}



// Generate speed based on row
float Log::generateSpeed() {

	if (_y == 50 || _y == 100) { // Row 1 or 2
		return 3;
	}
	else if (_y == 150 || _y == 200) { // Row 3 or 4
		return 3;
	}
	else {
		return 2;
	}
}

// Generate hitbox specific to log
sf::IntRect Log::generateHitBox()
{
	if (_direction) {
		return sf::IntRect(_x - 1, _y - 1, 149, 49);
	}
	else {
		return sf::IntRect(_x - 1, _y - 1, 99, 49);
	}
}
