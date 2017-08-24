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
        bool    _upgraded;

    public:
        Bomber();
        Bomber(int, int);
        Bomber(Bomber const &);
        Bomber const & operator=(Bomber const &);
        ~Bomber();

        void    init(int, int);
        void    move(int, Map *);
        void    playerHit();
        bool    isUpgraded();
};

#endif