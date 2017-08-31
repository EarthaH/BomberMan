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
    this->_life = 1;

    Bomb    bomb(this->_x, this->_y);
}

Bomber::~Bomber()
{

}

bool    Bomber::isUpgraded()
{
    return (this->_upgraded);
}