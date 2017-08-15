#include "../includes/bomber.hpp"

Bomber::Bomber()
{
    this->_bombs = new std::vector<Bomb>;

    Bomb    bomb(this->_x, this->_y);
    _bombs->push_back(bomb);
}

Bomber::Bomber(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

Bomber::Bomber(Bomber const & copy)
{
    *this = copy;
}

Bomber const & Bomber::operator=(Bomber const & copy)
{
    this->_bombs = copy._bombs;
    return (*this);
}

Bomber::~Bomber()
{
    delete this->_bombs;
}

int     Bomber::getLife() const
{
    return (this->_life);
}

void    Bomber::move(int dir)
{
    if (dir == RIGHT)
        this->moveRight();
    else if (dir == LEFT)
        this->moveLeft();
    else if (dir == UP)
        this->moveUp();
    else if (dir == DOWN)
        this->moveDown();
}