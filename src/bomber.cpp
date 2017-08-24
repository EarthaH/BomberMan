#include "../includes/bomber.hpp"

Bomber::Bomber()
{
    init(1, 1);
}

Bomber::Bomber(int x, int y)
{
    init(x, y);
}

Bomber::Bomber(Bomber const & copy)
{
    *this = copy;
}

Bomber const & Bomber::operator=(Bomber const & copy)
{
    this->_upgraded = copy._upgraded;
    return (*this);
}

void    Bomber::init(int x, int y)
{
    setX(x);
    setY(y);
    this->_type = BOMBER;

    Bomb    bomb(this->_x, this->_y);
}

Bomber::~Bomber()
{

}

void    Bomber::move(int dir, Map *map)
{
    if (dir == RIGHT)
        this->moveRight(map);
    else if (dir == LEFT)
        this->moveLeft(map);
    else if (dir == UP)
        this->moveUp(map);
    else if (dir == DOWN)
        this->moveDown(map);
}

bool    Bomber::isUpgraded()
{
    return (this->_upgraded);
}