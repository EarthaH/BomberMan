#include "../includes/header.hpp"

int		x;
int		y;

int		main()
{
	std::cout << "0.0.0" << std::endl;	
	srand((unsigned)time(0));

	Game	*game = new Game();
	game->start();
	delete  game;

	return (0);
}