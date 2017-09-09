#include "../includes/header.hpp"

int     x;
int     y;

int     main()
{
    srand((unsigned)time(0));

    Game    *game = new Game();
    game->start();
    delete  game;

    return (0);
}