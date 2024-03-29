#ifndef BOMB_H
# define BOMB_H

#include "header.hpp"

class	Game;
class	Base;
class	Map;

class	Bomb: public Base
{
	private:
		int		_time;
		bool	_active;

	public:
		Bomb();
		Bomb(int, int);
		Bomb(Bomb const &);
		Bomb const & operator=(Bomb const &);
		~Bomb();

		int		getTime();
		int		type();
		void	activate(int, int);
		void	exploded();
		bool	isActive();
		bool	explode();
};

#endif