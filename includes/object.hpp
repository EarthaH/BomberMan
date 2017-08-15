#ifndef OBJECT_H
# define OBJECT_H

#include <iostream>

#define OPEN    0
#define BOMBER  1
#define BOMB    2
#define ENEMY   3
#define WALL    4
#define BLOCK   5
#define UPGRADE 6

class Object
{
    protected:
        int     _x;
        int     _y;
        int     _oldX;
        int     _oldY;
        int     _type;

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
        char    getType();
        void    setX(int);
        void    setY(int);
        void    move(int, int);
        void    init(int, int, char);
};

#endif