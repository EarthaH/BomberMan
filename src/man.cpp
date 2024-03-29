#include "../includes/man.hpp"

Man::Man() : _type(SIMPLE_ENEMY), _life(1), _direction(1), _alive(true)
{

}

Man::Man(int x, int y, int type) : _life(1), _direction(1), _alive(true)
{
	_type = type;
	this->_position.x = x;
	this->_position.y = y;
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

int	 Man::getType()
{
	return (this->_type);
}

int	 Man::getLife()
{
	return (this->_life);
}

int	 Man::getDirection()
{
	return (this->_direction);
}

bool	Man::getAlive()
{
	return (this->_alive);
}

void	Man::changeDirection(int dir)
{
	this->_direction = dir;
}

void	Man::setLife(int life)
{
	this->_life = life;
}

void	Man::moveUp(Map *map)
{
	isStaticEnemy(map, getX(), getY(), getX(), getY() - 1);
	changeDirection(3);
	moveToBlock(map, getX(), getY() - 1);	
}

void	Man::moveDown(Map *map)
{
	isStaticEnemy(map, getX(), getY(), getX(), getY() + 1);
	changeDirection(4);
	moveToBlock(map, getX(), getY() + 1);
}

void	Man::moveLeft(Map *map)
{
	isStaticEnemy(map, getX(), getY(), getX() - 1, getY());
	changeDirection(2);
	moveToBlock(map, getX() - 1, getY());
}

void	Man::moveRight(Map *map)
{
	isStaticEnemy(map, getX(), getY(), getX() + 1, getY());
	changeDirection(1);
	moveToBlock(map, getX() + 1, getY());
}

void	Man::moveToBlock(Map *map, int x, int y)
{
	if (map->isType(x, y, WALL) || map->isType(x, y, BOMB) || map->isType(x, y, BLOCK) || map->getType(x, y) > 11)
		return;
	if ((map->isType(x, y, ENEMY) && this->_type == BOMBER) || map->isType(x, y, FIRE))
		this->_life--;

	this->move(x, y);
}

void	Man::isStaticEnemy(Map *map, int cx, int cy, int fx, int fy)
{
	if (!map->isType(cx, cy, ENEMY))
		return ;

	if (map->isType(fx, fy, WALL) || map->isType(fx, fy, BOMB) || map->isType(fx, fy, BLOCK) || map->getType(fx, fy) > 11)
	{
		setX(cx);
		setY(cy);
	}
}