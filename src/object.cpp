#include "../includes/object.hpp"

Object::Object() : _type(OPEN)
{
	//_position.x = 10;
	//_position.y = 10;
}

Object::Object(Object const & copy)
{
	*this = copy;
}

Object::Object(int x, int y, char type) : _type(type)
{
	_position.x = x;
	_position.y = y;
}

Object const & Object::operator=(Object const & copy)
{
	this->_position = copy._position;
	this->_type = copy._type;
	return (*this);
}

Object::~Object()
{

}

int	 Object::getX()
{
	return (this->_position.x);
}

int	 Object::getY()
{
	return (this->_position.y);
}

int	 Object::getOldX()
{
	return (this->_position.oldX);
}

int	 Object::getOldY()
{
	return (this->_position.oldY);
}

char	Object::getType()
{
	return (this->_type);
}

void	Object::setX(int x)
{
	this->_position.oldX = this->_position.x;
	this->_position.x = x;
}

void	Object::setY(int y)
{
	this->_position.oldY = this->_position.y;
	this->_position.y = y;
}

void	Object::move(int x, int y)
{
	setX(x);
	setY(y);
}

void	Object::init(int x, int y, char type)
{
	this->_position.x = x;
	this->_position.y = y;
	setX(x);
	setY(y);
	this->_type = type;
}