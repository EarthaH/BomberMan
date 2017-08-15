#ifndef BOMBER_H
# define BOMBER_H

#include "header.hpp"

class   Object;
class   Man;
class   Bomb;

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

        int     getLife() const;
        void    init(int, int);
        void    move(int);
        void    move(int, std::vector<std::vector<int> > *);
        void    dropBomb();
        void    playerHit();
};

#endif