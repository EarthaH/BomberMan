#ifndef BOMB_H
# define BOMB_H

#include "header.hpp"

class   Game;
class   Object;

class   Bomb: public Object
{
    private:
        int     _time;
        int     _range;
        bool    _active;

    public:
        Bomb();
        Bomb(int, int);
        Bomb(Bomb const &);
        Bomb const & operator=(Bomb const &);
        ~Bomb();

        int     getTime();
        void    countDown();
        void    activate();
        void    explode();
        void    upRange();
};

#endif