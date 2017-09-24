#include "../includes/header.hpp"

bool	equal(Base & a, Base & b)
{
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (true);
	return (false);
}

bool	equal(Base & obj, int x, int y)
{
	if (obj.getX() == x && obj.getY() == y)
		return (true);
	return (false);
}