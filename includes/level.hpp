#ifndef LEVEL_H
# define LEVEL_H

#include <iostream>

class Level
{
    private:
        int     _level;
        int     _height;
        int     _width;
        

    public:
        Level();
        Level(int);
        Level(Level const &);
        Level const & operator=(Level const &);
        ~Level();

        int     getLevel();
        int     getHeight();
        int     getWidth();
        void    setHeight(int);
        void    setWidth(int);
        void    setLevel(int);
        void    one();
        void    two();
        void    three();
        void    four();

        int     num_of_enemies;
        int     num_of_blocks;
        int     num_of_upgrades;
};

#endif