#include "../includes/header.hpp"

int     x;
int     y;

int     main()
{
    x = 11;
    y = 11;
    
    srand((unsigned)time(0));

    Game    *game = new Game(x, y);
    game->start();
    delete  game;

    return (0);
}