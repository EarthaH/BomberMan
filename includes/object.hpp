#ifndef OBJECT_H
# define OBJECT_H

#include <iostream>

class Object
{
    protected:
        int     _x;
        int     _y;
        int     _oldX;
        int     _oldY;
        char    _ch;

    public:
        Object();
        Object(Object const &);
        Object(int, int, char);
        Object const & operator=(Object const &);
        ~Object();
        int     getX();
        int     getY();
        int     getOldX();
        int     getOldY();
        char    getCh();
        void    setX(int);
        void    setY(int);
        void    move(int, int);
        void    init(int, int, char);
};

#endif