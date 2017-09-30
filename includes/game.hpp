#ifndef GAME_H
# define GAME_H

#include "header.hpp"
#include <thread>


class   Handle;
class   Level;
class	Load;
class	Lib;
class	Menu;

class   Game 
{
	private:
	Sound gameOver;


	public:
		Game();
		Game(Game const &);
		Game const & operator=(Game const &);
		~Game();

		int		loop();
		void	start();
		void	move();
		void	end();
		void	init();
		void	draw();
		void	setLib();
		void	dlerror_wrapper();
		void	deleteLibrary();
		void	clearMap();
		void	levelUp();
		void	levelDown();
		void	changeLevel(int);
		void	save();
		void	load(char *);
		
		bool	blockClear();
		bool	endLevel();
		
		int		speed;
		int		enemy_movement;
		bool	complete;
		Handle  *handle;
		Lib		*library;
		Level   *level;
		Load	*load_handle;
		Menu	*menu;
};

#endif