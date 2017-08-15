#ifndef MAN_H
# define MAN_H

#include "object.hpp"

#define PLAYER 0
#define SIMPLE_ENEMY 1
#define PLAYER_ENEMY 2

class   Object;

class   Man: public Object
{
    protected:
        int     _type;
        int     _life;
        int     _direction;
        bool    _alive;

    public:
        Man();
        Man(int, int, int);
        Man(Man const &);
        Man const & operator=(Man const &);
        ~Man();

        int     getType();
        int     getLife();
        int     getDirection();
        bool    getAlive();
        void    changeDirection(int);

        void    moveUp();
        void    moveDown();
        void    moveLeft();
        void    moveRight();

        //bool    checkBlock(int, int);
};

#endif