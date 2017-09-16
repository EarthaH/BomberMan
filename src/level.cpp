#include "../includes/level.hpp"

Level::Level() : _level(1)
{
	one();
}

Level::Level(int num) : _level(num)
{
	if (_level == 1)
		one();
	else if (_level == 2)
		two();
	else if (_level == 3)
		three();
	else if (_level == 4)
		four();
}

Level::Level(Level const & copy)
{
	*this = copy;
}

Level::~Level()
{

}

Level const & Level::operator=(Level const & copy)
{
	this->_level = copy._level;
	this->num_of_enemies = copy.num_of_enemies;
	this->num_of_blocks = copy.num_of_blocks;
	this->num_of_upgrades = copy.num_of_upgrades;

	return (*this);
}

int	 Level::getLevel()
{
	return (this->_level);
}

int	 Level::getHeight()
{
	return (this->_height);
}

int	 Level::getWidth()
{
	return (this->_width);
}

void	Level::setHeight(int h)
{
	this->_height = h;
}

void	Level::setWidth(int w)
{
	this->_width = w;
}

void	Level::setLevel(int l)
{
	this->_level = l;
}

void	Level::one()
{
	num_of_enemies = 1;
	num_of_blocks = 20;
	num_of_upgrades = 4;
	_height = 11;
	_width = 11;
}

void	Level::two()
{
	num_of_enemies = 1;
	num_of_blocks = 50;
	num_of_upgrades = 6;
	_height = 15;
	_width = 15;
}

void	Level::three()
{
	num_of_enemies = 6;
	num_of_blocks = 100;
	num_of_upgrades = 8;
	_height = 21;
	_width = 21;
}

void	Level::four()
{
	num_of_enemies = 7;
	num_of_blocks = 200;
	num_of_upgrades = 10;
	_height = 31;
	_width = 31;
}