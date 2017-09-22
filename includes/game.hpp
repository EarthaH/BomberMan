#ifndef GAME_H
# define GAME_H

#include "header.hpp"
#include <thread>

class   Handle;
class   Level;
class	Load;
class	Lib;

class   Game 
{
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
		void	save();
		void	load(char *);
		
		bool	blockClear();
		bool	endLevel();
		
		int		score;
		int		speed;
		Handle  *handle;
		Lib		*library;
		Level   *level;
		Load	*load_handle;
};

#endif