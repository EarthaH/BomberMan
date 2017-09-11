#include "../includes/header.hpp"

bool	equal(Object & a, Object & b)
{
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (true);
	return (false);
}

bool	equal(Object & obj, int x, int y)
{
	if (obj.getX() == x && obj.getY() == y)
		return (true);
	return (false);
}