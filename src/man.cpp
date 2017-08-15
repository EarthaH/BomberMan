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

void    Man::moveUp()
{
    this->move(getX(), getY() - 1);
}

void    Man::moveDown()
{
    this->move(getX(), getY() + 1);
}

void    Man::moveLeft()
{
    this->move(getX() - 1, getY());
}

void    Man::moveRight()
{
    this->move(getX() + 1, getY());
}

// bool    Man::checkBlock(int x, int y)
// {
//     if (x == 200 || y == 200)
//         return (false);
//     return (true);
// }