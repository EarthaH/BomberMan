#include "../includes/object.hpp"

Object::Object() : _x(10), _y(10), _ch('*')
{
    //std::cout << "Object '" << _ch << "' created at: " << _x << " " << _y << std::endl;
}

Object::Object(Object const & copy)
{
    *this = copy;
}

Object::Object(int x, int y, char ch) : _x(x), _y(y), _ch(ch)
{

}

Object const & Object::operator=(Object const & copy)
{
    this->_x = copy._x;
    this->_y = copy._y;
    this->_oldX = copy._oldX;
    this->_oldY = copy._oldY;
    this->_ch = copy._ch;
    return (*this);
}

Object::~Object()
{

}

int     Object::getX()
{
    return (this->_x);
}

int     Object::getY()
{
    return (this->_y);
}

int     Object::getOldX()
{
    return (this->_oldX);
}

int     Object::getOldY()
{
    return (this->_oldY);
}

char    Object::getCh()
{
    return (this->_ch);
}

void    Object::setX(int x)
{
    this->_x = x;
}

void    Object::setY(int y)
{
    this->_y = y;
}

void    Object::move(int x, int y)
{
    this->_oldX = this->_x;
    this->_oldY = this->_y;
    this->_x = x;
    this->_y = y;
}

void    Object::init(int x, int y, char ch)
{
    this->_x = x;
    this->_y = y;
    this->_ch = ch;
}