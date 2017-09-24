#ifndef MAN_H
# define MAN_H

#include "base.hpp"
#include "map.hpp"

#define PLAYER 0
#define SIMPLE_ENEMY 1
#define PLAYER_ENEMY 2

class   Base;
class   Map;

class   Man: public Base
{
	protected:
		int		_type;
		int		_life;
		int		_direction;
		bool	_alive;

	public:
		Man();
		Man(int, int, int);
		Man(Man const &);
		Man const & operator=(Man const &);
		~Man();

		int		getType();
		int		getLife();
		int		getDirection();
		bool	getAlive();
		void	changeDirection(int);
		void	setLife(int);

		void	moveUp(Map *);
		void	moveDown(Map *);
		void	moveLeft(Map *);
		void	moveRight(Map *);

		void	moveToBlock(Map *, int, int);
};

#endif