#ifndef MAP_H
# define MAP_H

#include <vector>
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

        void    init();
        void    update(int, int, int);
        void    update(Object *, int);
        void    clear();
        bool    isOpen(int, int);
        bool    isType(int, int, int);

        std::vector<std::vector<int> >  map;
        int                             width;
        int                             height;
};

#endif