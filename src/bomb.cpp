#include "../includes/bomb.hpp"

Bomb::Bomb() : _time(1), _active(false)
{
	this->_type = BOMB;
}

Bomb::Bomb(int x, int y) : _time(1), _active(false)
{
	this->_position.x = x;
	this->_position.y = y;
	this->_position.oldX = x;
	this->_position.oldY = y;
	this->_type = BOMB;
}

Bomb::Bomb(Bomb const & copy)
{
	this->_time = copy._time;
	this->_active = copy._active;
}

Bomb const & Bomb::operator=(Bomb const & copy)
{
	this->_time = copy._time;
	this->_active = copy._active;

	return (copy);
}

Bomb::~Bomb()
{

}

int	 Bomb::getTime()
{
	return (this->_time);
}

int	 Bomb::type()
{
	if (isActive())
		return (BOMB);
	return (FIRE);
}

void	Bomb::activate(int x, int y)
{
	setX(x);
	setY(y);
	this->_active = true;
	this->_time = 6;
}

void	Bomb::exploded()
{
	this->_active = false;
}

bool	Bomb::explode()
{
	if (this->_time == 0)
		return (true);
	this->_time--;

	return (false);
}

bool	Bomb::isActive()
{
	return (this->_active);
}