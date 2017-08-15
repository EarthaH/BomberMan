#include "../includes/bomb.hpp"

Bomb::Bomb() : _time(3), _range(2), _active(true)
{

}

Bomb::Bomb(int x, int y) : _time(3), _range(2), _active(true)
{
    this->_x = x;
    this->_y = y;
}

Bomb::Bomb(Bomb const & copy)
{
    this->_time = copy._time;
    this->_range = copy._range;
    this->_active = copy._active;
}

Bomb const & Bomb::operator=(Bomb const & copy)
{
    this->_time = copy._time;
    this->_range = copy._range;
    this->_active = copy._active;

    return (copy);
}

Bomb::~Bomb()
{

}

int     Bomb::getTime()
{
    return (this->_time);
}

void    Bomb::countDown()
{

}

void    Bomb::activate()
{

}

void    Bomb::explode()
{

}

void    Bomb::upRange()
{
    this->_range++;
}