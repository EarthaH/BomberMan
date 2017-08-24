#ifndef BOMB_H
# define BOMB_H

#include "header.hpp"

class   Game;
class   Object;
class   Map;

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
        int     type();
        void    countDown(Map *);
        void    activate(int, int);
        void    explode(Map *);
        void    upRange();
        bool    isActive();
};

#endif