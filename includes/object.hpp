#ifndef OBJECT_H
# define OBJECT_H

#include <iostream>

#define OPEN            0
#define BOMBER          1
#define BOMB            2
#define ENEMY           3
#define WALL            4
#define BLOCK           5
#define FIRE            6
#define LIFE_UPGRADE    7
#define BOMB_UPGRADE    8
#define FIRE_UPGRADE    9

typedef struct  s_position
{
    int     x;
    int     y;
    int     oldX;
    int     oldY;
}       t_position;

class Object
{
    protected:
        t_position  _position;
        int         _type;

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