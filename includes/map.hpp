#ifndef MAP_H
# define MAP_H

#include <vector>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>
#include "object.hpp"

class   Object;

class   Map
{
	public:
		Map();
		Map(int, int);
		Map(Map const &);
		Map const & operator=(Map const &);
		~Map();

		int     	getType(int, int);
		void		init();
		void		update(int, int, int);
		void		update(t_position, int);
		void		update(Object *, int);
		void		clear();
		bool		isOpen(int, int);
		bool		isType(int, int, int);
		bool		blockStart(int, int);
		bool		isUpgrade(int, int);
		std::string	getMapRow(int);

		std::vector<std::vector<int> >  map;
		int							 width;
		int							 height;
};

#endif