#ifndef MAP_H
# define MAP_H

#include <vector>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>
#include "base.hpp"

class   Base;

class   Map
{
	public:
		Map();
		Map(int, int);
		Map(int, int, std::vector<std::vector<int> >);
		Map(Map const &);
		Map const & operator=(Map const &);
		~Map();

		int     	getType(int, int);
		int			countType(int);
		void		init();
		void		update(int, int, int);
		void		update(t_position, int);
		void		update(Base *, int);
		void		clear();
		bool		isOpen(int, int);
		bool		isType(int, int, int);
		bool		blockStart(int, int);
		bool		isUpgrade(int, int);
		std::string	getMapRow(int);
		t_position	getPosition(int);
		t_position	getPosition(int, int, int);

		std::vector<std::vector<int> >  map;
		int							 width;
		int							 height;
};

#endif