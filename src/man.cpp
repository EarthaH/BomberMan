#include "../includes/man.hpp"

Man::Man() : _type(SIMPLE_ENEMY), _life(1), _direction(1), _alive(true)
{

}

Man::Man(int x, int y, int type) : _life(1), _direction(1), _alive(true)
{
    _type = type;
    this->_x = x;
    this->_y = y;
}

Man::Man(Man const & copy)
{
    *this = copy;
}

Man const & Man::operator=(Man const & copy)
{
    this->_type = copy._type;
    this->_life = copy._life;
    this->_direction = copy._direction;
    this->_alive = copy._alive;
    return (*this);
}

Man::~Man()
{

}

int     Man::getType()
{
    return (this->_type);
}

int     Man::getLife()
{
    return (this->_life);
}

int     Man::getDirection()
{
    return (this->_direction);
}

bool    Man::getAlive()
{
    return (this->_alive);
}

void    Man::changeDirection(int dir)
{
    this->_direction = dir;
}

void    Man::moveUp(Map *map)
{
    if (map->isOpen(getX(), getY() - 1))
        this->move(getX(), getY() - 1);
}

void    Man::moveDown(Map *map)
{
    if (map->isOpen(getX(), getY() + 1))
        this->move(getX(), getY() + 1);
}

void    Man::moveLeft(Map *map)
{
    if (map->isOpen(getX() - 1, getY()))
        this->move(getX() - 1, getY());
}

void    Man::moveRight(Map *map)
{
    if (map->isOpen(getX() + 1, getY()))
        this->move(getX() + 1, getY());
}