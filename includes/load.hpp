#ifndef LOAD_H
# define LOAD_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dlfcn.h>
#include <curses.h>
#include <vector>

class   Load
{
	public:
		Load();
		Load(char *);
		Load(Load const &);
		Load const & operator=(Load const &);
        ~Load();

        int		str_to_int(char *);
        void	load(std::string);
        void	convert(std::vector<char *> *);
        
        std::vector<char *>			split(char *, char *);
        std::vector<int>			split_num(char *, char *);
        
        int     map_size, level, score, range, life, bomb_size;
        std::vector<std::vector<int> >  map;
};

#endif