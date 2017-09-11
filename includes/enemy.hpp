#ifndef ENEMY_H
# define ENEMY_H

#include "header.hpp"

class	Object;
class	Man;
class	Bomb;
class	Map;

class	Enemy: public Man
{
	private:
		int		_iq;
		int		_number;

	public:
		Enemy();
		Enemy(t_position, int);
		Enemy(Enemy const &);
		Enemy const & operator=(Enemy const &);
		~Enemy();

		int	 getNumber();
		void	init(t_position);
		void	move(Map *);
};

#endif