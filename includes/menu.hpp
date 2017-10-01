#pragma once

// GLEW
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <unistd.h>

#include "game.hpp"

class	Game;

enum class	MenuState
{
	MAIN_MENU,
	SETTINGS,
	LOAD,
	EXIT
};

enum class	GameState
{
	MENU,
	PLAY,
	END,
	EXIT
};

class Menu
{
	private:
		GLFWwindow  *_win;
		MenuState   _menuState;
		GameState	_gameState;
		int			_gameEnd;

	public:

		Menu();
		Menu(Menu const &);
		~Menu();
		Menu const & operator=(Menu const &);

		void    	mainMenu();
		void		settingsMenu();
		void		loadMenu();
		
		void		run();
		void		renderMenu();
		void		popUpErrorMenu(std::string title, std::string message, std::string buttonText);
		void		setGLFWCallback();

		GameState	menuHandler();
		GameState	gameHandler();
		GameState	endGameMenu();

		Game	*game;
};
