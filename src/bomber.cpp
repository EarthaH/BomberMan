#include "../includes/bomber.hpp"

Bomber::Bomber() : _range(2)
{
	init(1, 1);
}

Bomber::Bomber(int x, int y) : _range(2)
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
	this->_range = copy._range;
	return (*this);
}

int	 Bomber::getRange()
{
	return (this->_range);
}

void	Bomber::upgradeRange()
{
	this->_range++;
}

void	Bomber::init(int x, int y)
{
	setX(x);
	setY(y);
	this->_type = BOMBER;
	this->_life = 1;

	Bomb	bomb(this->_position.x, this->_position.y);
}

Bomber::~Bomber()
{

}

void	Bomber::playerHit()
{
	this->_life--;
	
	if (this->_life == 0)
		exit(0);
}

void	Bomber::upgradeLife()
{
	this->_life++;
}

void	Bomber::setRange(int r)
{
	this->_range = r;
}

bool	Bomber::isUpgraded()
{
	return (this->_upgraded);
}