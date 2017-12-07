#pragma once

// GLEW
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <unistd.h>

#include "game.hpp"

#define CURRENT_GAME "current_game"

#define DROP_BOMB_KEY	5
#define PAUSE_KEY		6

class	Game;

enum class	MenuState
{
	MAIN_MENU,
	SETTINGS,
	LOAD,
	END,
	KEYS,
	RES,
	EXIT
};

enum class	GameState
{
	MENU,
	PLAY,
	STOP,
	EXIT
};

class Menu
{
	private:
		GLFWwindow  *_win;
		MenuState   _menuState;
		GameState	_gameState;
		int			_game_complete;

	public:

		Menu();
		Menu(Menu const &);
		~Menu();
		Menu const & operator=(Menu const &);

		void		setCallbacks();

		void    	mainMenu();
		void		settingsMenu();
		void		loadMenu();
		void		gameOverMenu();
		void		pausedMenu();
		void		keyMenu();
		void		resMenu();

		void		run();
		void		renderMenu();
		void		popUpErrorMenu(std::string title, std::string message, std::string buttonText);
		void		popUpVolume();
		void		popUpKeyMenu(std::string, std::string, int);
		void		changeCallback();
		void		changeKey(int, int);

		GameState	menuHandler();
		GameState	gameHandler();

		Game	*game;
};
