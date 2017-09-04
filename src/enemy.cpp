#include "../includes/enemy.hpp"

Enemy::Enemy() : _iq(10)
{

}

Enemy::Enemy(t_position pos, int num) : _iq(10), _number(num)
{
    setX(pos.x);
    setY(pos.y);
    this->_type = ENEMY;
    this->_life = 1;
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

int     Enemy::getNumber()
{
    return (this->_number);
}