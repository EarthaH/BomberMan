#ifndef GAME_H
# define GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dlfcn.h>
#include <vector>
#include <thread>

#include "SoundEngine.hpp"
#include "handle.hpp"
#include "level.hpp"
#include "load.hpp"
#include "lib.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

class   Handle;
class   Level;
class	Load;
class	Lib;

class   Game 
{
	private:
		Sound	gameOver;

	public:
		Game();
		Game(Game const &);
		Game const & operator=(Game const &);
		~Game();

		int		loop();
		int		start();
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
		void	save(std::string);
		void	load(std::string);

		void	setLeft();
		void	setRight();
		void	setUp();
		void	setDown();
		void	setDropBomb();
		void	setPause();
		void	setMapView();
		void	setVolume(float);
	
		static void	setGameState(int);
		
		bool	blockClear();
		bool	endLevel();
		
		int		speed;
		int		enemy_movement;
		static int		gameState;
		bool	complete;
		Handle  *handle;
		Lib		*library;
		Level   *level;
		Load	*load_handle;
};

#endif