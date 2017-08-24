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
    this->_bombs = copy._bombs;
    return (*this);
}

void    Bomber::init(int x, int y)
{
    setX(x);
    setY(y);
    this->_type = BOMBER;
    this->_bombs = new std::vector<Bomb>;

    Bomb    bomb(this->_x, this->_y);
    _bombs->push_back(bomb);
}

Bomber::~Bomber()
{
    delete this->_bombs;
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

void    Bomber::dropBomb()
{
    this->_bombs->at(0).activate(this->_x, this->_y);
}

Bomb    *Bomber::getBomb()
{
    return (&this->_bombs->at(0));
}