#ifndef ENEMY_H
# define ENEMY_H

#include "header.hpp"

class   Object;
class   Man;
class   Bomb;
class   Map;

class   Enemy: public Man
{
    private:
        int     _iq;

    public:
        Enemy();
        Enemy(Map *);
        Enemy(Enemy const &);
        Enemy const & operator=(Enemy const &);
        ~Enemy();

        void    init(int, int);
        void    move(Map *);
};

#endif