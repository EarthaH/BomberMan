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
        int     _range;
        bool    _upgraded;

    public:
        Bomber();
        Bomber(int, int);
        Bomber(Bomber const &);
        Bomber const & operator=(Bomber const &);
        ~Bomber();

        int     getRange();
        void    upgradeRange();
        void    init(int, int);
        void    playerHit();
        void    upgradeLife();
        bool    isUpgraded();
};

#endif