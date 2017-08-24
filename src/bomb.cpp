#include "../includes/bomb.hpp"

Bomb::Bomb() : _time(3), _range(2), _active(false)
{
    this->_type = BOMB;
}

Bomb::Bomb(int x, int y) : _time(3), _range(2), _active(false)
{
    this->_x = x;
    this->_y = y;
    this->_oldX = x;
    this->_oldY = y;
    this->_type = BOMB;
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

int     Bomb::type()
{
    if (isActive())
        return (BOMB);
    return (OPEN);
}

void    Bomb::countDown(Map *map)
{
    if (this->_time == 0)
        explode(map);
    else
        this->_time--;
    map->update(this, type());
}

void    Bomb::activate(int x, int y)
{
    setX(x);
    setY(y);
    this->_active = true;
    this->_time = 50;
}

void    Bomb::explode(Map *map)
{
    for (int i = _x + 1, r = 0; r < _range && map->isOpen(i, _y); r++, i++)
        map->update(i, _y, FIRE);
    for (int i = _x - 1, r = 0; r < _range && map->isOpen(i, _y); r++, i--)
        map->update(i, _y, FIRE);
    for (int i = _y + 1, r = 0; r < _range && map->isOpen(_x, i); r++, i++)
        map->update(_x, i, FIRE);
    for (int i = _y - 1, r = 0; r < _range && map->isOpen(_x, i); r++, i--)
        map->update(_x, i, FIRE);
    this->_active = false;
}

void    Bomb::upRange()
{
    this->_range++;
}

bool    Bomb::isActive()
{
    return (this->_active);
}