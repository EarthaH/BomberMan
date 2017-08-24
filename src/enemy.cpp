#include "../includes/enemy.hpp"

Enemy::Enemy() : _iq(10)
{

}

Enemy::Enemy(Map *map) : _iq(10)
{
    int     x = rand() % (map->width - 1) + 1;
    int     y = rand() % (map->height - 1) + 1;

    while (!map->isOpen(x, y))
    {
        x = rand() % (map->width - 1) + 1;
        y = rand() % (map->height - 1) + 1;
    }

    init(x, y);
}

Enemy::Enemy(Enemy const & copy)
{
    *this = copy;
}

Enemy const & Enemy::operator=(Enemy const & copy)
{
    this->_iq = copy._iq;
    return (*this);
}

void    Enemy::init(int x, int y)
{
    setX(x);
    setY(y);
    this->_type = ENEMY;
}

Enemy::~Enemy()
{

}

void    Enemy::move(Map *map)
{
    this->_direction = rand() % 4 + 1;

    if (this->_direction == RIGHT)
        this->moveRight(map);
    else if (this->_direction == LEFT)
        this->moveLeft(map);
    else if (this->_direction == UP)
        this->moveUp(map);
    else if (this->_direction == DOWN)
        this->moveDown(map);
}