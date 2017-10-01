#include "../includes/menu.hpp"

int		x;
int		y;

int		main()
{
	std::cout << "0.0.0" << std::endl;	
	srand((unsigned)time(0));

	Sound musicloop;
	musicloop.initialize("../res/sound/loop.wav");
	musicloop.play(true);

	Menu	*menu = new Menu();
	menu->run();

	delete	menu;
	return (0);
}