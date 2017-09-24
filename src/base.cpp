#include "../includes/base.hpp"

Base::Base() : _type(OPEN)
{
	//_position.x = 10;
	//_position.y = 10;
}

Base::Base(Base const & copy)
{
	*this = copy;
}

Base::Base(int x, int y, char type) : _type(type)
{
	_position.x = x;
	_position.y = y;
}

Base const & Base::operator=(Base const & copy)
{
	this->_position = copy._position;
	this->_type = copy._type;
	return (*this);
}

Base::~Base()
{

}

int	 Base::getX()
{
	return (this->_position.x);
}

int	 Base::getY()
{
	return (this->_position.y);
}

int	 Base::getOldX()
{
	return (this->_position.oldX);
}

int	 Base::getOldY()
{
	return (this->_position.oldY);
}

char	Base::getType()
{
	return (this->_type);
}

void	Base::setX(int x)
{
	this->_position.oldX = this->_position.x;
	this->_position.x = x;
}

void	Base::setY(int y)
{
	this->_position.oldY = this->_position.y;
	this->_position.y = y;
}

void	Base::move(int x, int y)
{
	setX(x);
	setY(y);
}

void	Base::init(int x, int y, char type)
{
	this->_position.x = x;
	this->_position.y = y;
	setX(x);
	setY(y);
	this->_type = type;
}