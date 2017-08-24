#ifndef BOMBER_H
# define BOMBER_H

#include "header.hpp"

class   Object;
class   Man;
class   Bomb;
class   Map;

class   Bomber: public Man
{
    private:
        std::vector<Bomb>   *_bombs;

    public:
        Bomber();
        Bomber(int, int);
        Bomber(Bomber const &);
        Bomber const & operator=(Bomber const &);
        ~Bomber();

        void    init(int, int);
        void    move(int, Map *);
        void    dropBomb();
        void    playerHit();
        Bomb    *getBomb();
};

#endif