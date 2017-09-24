#ifndef BASE_H
# define BASE_H

#include <iostream>

#define OPEN			0
#define BOMBER			1
#define BOMB			2
#define ENEMY			3
#define WALL			4
#define BLOCK			5
#define FIRE			6
#define LEVEL_UP		7
#define LEVEL_DOWN		8
#define LIFE_UPGRADE	9
#define BOMB_UPGRADE	10
#define FIRE_UPGRADE	11

typedef struct  s_position
{
	int		x;
	int		y;
	int		oldX;
	int		oldY;
}	   t_position;

class Base
{
	protected:
		t_position  _position;
		int		 _type;

	public:
		Base();
		Base(Base const &);
		Base(int, int, char);
		Base const & operator=(Base const &);
		~Base();
		int		getX();
		int		getY();
		int		getOldX();
		int		getOldY();
		char	getType();
		void	setX(int);
		void	setY(int);
		void	move(int, int);
		void	init(int, int, char);
};

#endif