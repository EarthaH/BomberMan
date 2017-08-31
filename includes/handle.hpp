#ifndef HANDLE_H
# define HANDLE_H

#include "header.hpp"
#include "IEntity.hpp"
#include <thread>

class   Bomber;
class   Map;
class   Enemy;
class   Bomb;

class   Handle 
{
    private:

    public:
        Handle();
        Handle(int, int);
        Handle(Handle const &);
        Handle const & operator=(Handle const &);
        ~Handle();

        Map                 *map;
        Bomber              *bomberman;
        std::vector<Enemy>  *enemies;
        std::vector<Bomb>   *bombs;

        int     moveEnemy();
        void    initMap();
        void    checkKey(int);
        void    moveBomber(int);
        void    endGame();
        void    checkBombs();
        void    dropBomb(int, int);
        void    activeBomb(Bomb *);
        void    killEnemy(int, int);
        bool    updateBomb(Bomb *);
        bool    checkMapFire(int, int);
        size_t  getBomb();
};

#endif