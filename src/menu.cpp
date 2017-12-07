#include "../includes/menu.hpp"

#include <nanogui/nanogui.h>
#include <nanogui/screen.h>
#include <nanogui/widget.h>
#include <nanogui/combobox.h>
#include <utility>
#include <vector>
#include <fstream>
#include <dirent.h>

std::vector<std::string>	*getFiles(std::vector<std::string> *files);
bool						isTextFile(std::string file);

nanogui::Screen				*screen = nullptr;
std::vector<std::string>	*files;

int		Game::gameState = 0;

Menu::Menu() : _menuState(MenuState::MAIN_MENU), _gameState(GameState::MENU)
{
	game = new Game();
	Game::gameState = 0;
	_win = game->library->window;
}

Menu::~Menu()
{
	delete screen;
	delete game;
	glfwTerminate();
}

void	Menu::run()
{
	while (_gameState != GameState::EXIT)
	{
		if (_gameState == GameState::MENU)
			_gameState = menuHandler();
		if (_gameState == GameState::PLAY)
			_gameState = gameHandler();
	}
}

void		Menu::setCallbacks()
{
	glfwSetCursorPosCallback(_win, [](GLFWwindow *, double x, double y)
		{
				screen->cursorPosCallbackEvent(x, y);
		}
	);

	glfwSetMouseButtonCallback(_win, [](GLFWwindow *, int button, int action, int modifiers)
		{
			screen->mouseButtonCallbackEvent(button, action, modifiers);
		}
	);

	glfwSetKeyCallback(_win, [](GLFWwindow *, int key, int scancode, int action, int mods)
		{
			screen->keyCallbackEvent(key, scancode, action, mods);
		}
	);

	glfwSetCharCallback(_win, [](GLFWwindow *, unsigned int codepoint)
		{
			screen->charCallbackEvent(codepoint);
		}
	);

	glfwSetFramebufferSizeCallback(_win, [](GLFWwindow *, int width, int height) 
		{
			screen->resizeCallbackEvent(width, height);
		}
	);

	glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

GameState	Menu::menuHandler()
{
	#if defined(NANOGUI_GLAD)
		#if defined(NANOGUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
			#define GLAD_GLAPI_EXPORT
		#endif

		#include <glad/glad.h>
	#else
		#if defined(__APPLE__)
			#define GLFW_INCLUDE_GLCOREARB
		#else
			#define GL_GLEXT_PROTOTYPES
		#endif
	#endif

	setCallbacks();

	screen = new nanogui::Screen;
	screen->initialize(_win, true);

	//Break when time to play :D !!!
	while (_gameState == GameState::MENU && _menuState != MenuState::EXIT)
	{
		switch (_menuState)
		{
			case MenuState::MAIN_MENU :
				mainMenu();
				break;
			case MenuState::SETTINGS :
				settingsMenu();
				break;
			case MenuState::LOAD :
				files = getFiles(new std::vector<std::string>());
				loadMenu();
				delete files;
				break;
			case MenuState::KEYS :
				keyMenu();
				break;
			case MenuState::END :
				gameOverMenu();
				break;
			case MenuState::EXIT :
				std::cout << "What the fuck impossible" << std::endl;
		}
	}
	return (_gameState == GameState::PLAY ? GameState::PLAY : GameState::EXIT);
}

GameState	Menu::gameHandler()
{
	game->library->resetCallback();
	while ((_game_complete = game->start()) == 2)
	{
		_gameState = GameState::STOP;
		pausedMenu();
		if (_gameState == GameState::EXIT)
			return (GameState::EXIT);
		game->library->resetCallback();
	}
	
	_menuState = MenuState::END;

	delete game->handle;
	delete game->level;

	game->level = new Level();
	game->handle = new Handle(game->level);

	return (GameState::MENU);
}

void	Menu::mainMenu()
{
	/* NEEDED FOR EVERY NEW MENU */
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Main Menu");

	nanoguiWindow->setLayout(new nanogui::GroupLayout);
	/* ************************* */

	nanogui::Button	*new_game_button = new nanogui::Button(nanoguiWindow, "New Game");
	nanogui::Button	*load_game_button = new nanogui::Button(nanoguiWindow, "Load Game");
	nanogui::Button	*settings_button = new nanogui::Button(nanoguiWindow, "Settings");
	nanogui::Button	*exit_button = new nanogui::Button(nanoguiWindow, "Exit");
	
	new_game_button->setCallback([&]
	{
		//ADD code for new game
		_gameState = GameState::PLAY;
		_menuState = MenuState::EXIT;
		std::cout << "New Game SHOULD start now!!!\n";
	});

	load_game_button->setCallback([&]
	{
		//ADD code for loading saved games
		_menuState = MenuState::LOAD;
		std::cout << "Load Game list!\n";
	});

	settings_button->setCallback([&]
	{
		//ADD code for settings menu
		_menuState = MenuState::SETTINGS;
		std::cout << "Settings coming...\n";
	});

	exit_button->setCallback([&]
	{
		_menuState = MenuState::EXIT;
		_gameState = GameState::EXIT;
	});

	/* NEEDED FOR EVERY NEW MENU */
	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();
	/* ************************* */

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::MAIN_MENU)
	{
		glfwPollEvents();
		renderMenu();
	}
	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::settingsMenu()
{
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Settings");

	nanoguiWindow->setLayout(new nanogui::GroupLayout);



	nanogui::Button	*screen_res_button = new nanogui::Button(nanoguiWindow, "Screen Resolution");
	nanogui::Button	*full_screen_button = new nanogui::Button(nanoguiWindow, "Full Screen");
	nanogui::Button	*key_bindings_button = new nanogui::Button(nanoguiWindow, "Key Bindings");
	nanogui::Button	*sound_button = new nanogui::Button(nanoguiWindow, "Music and Sound");
	nanogui::Button	*back_button = new nanogui::Button(nanoguiWindow, "Back");
	
	screen_res_button->setCallback([&]
	{
		std::cout << "Screen Res!!!\n";
	});

	full_screen_button->setCallback([&]
	{
		nanoguiWindow->setVisible(false);
		popUpErrorMenu("WARNING", "FILE NOT FOUND", "RETURN");
		nanoguiWindow->setVisible(true);
		std::cout << "Full Screen!\n";
	});

	key_bindings_button->setCallback([&]
	{
		_menuState = MenuState::KEYS;
	});

	sound_button->setCallback([&]
	{
		std::cout << "Music!!!\n";
	});

	back_button->setCallback([&]
	{
		_menuState = MenuState::MAIN_MENU;
		std::cout << "Back!!!\n";
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::SETTINGS)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::loadMenu()
{
	screen->initialize(_win, true);

	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(100, 100), "Load");

	nanoguiWindow->setLayout(new nanogui::GroupLayout);

	nanogui::ComboBox *list = new nanogui::ComboBox(nanoguiWindow, *files);
	nanogui::Button	*load_game_button = new nanogui::Button(nanoguiWindow, "Load Game");
	nanogui::Button	*back_button = new nanogui::Button(nanoguiWindow, "Back");

	load_game_button->setCallback([&]
	{
		game->load(files->at(list->selectedIndex()));
		_gameState = GameState::PLAY;
		_menuState = MenuState::EXIT;
	});

	back_button->setCallback([&]
	{
		_menuState = MenuState::MAIN_MENU;
		std::cout << "Back!!!\n";
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::LOAD)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::gameOverMenu()
{
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Game Over!");
	nanogui::Widget *tools = new nanogui::Widget(nanoguiWindow);

	std::string	message = _game_complete == 0 ? "Well Done! You completed all the levels." : "Looks like you killed yourself...";
	nanoguiWindow->setLayout(new nanogui::GroupLayout);
	tools->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal,
		nanogui::Alignment::Middle, 0, 6));
	new nanogui::Label(tools, message);

	nanogui::Button	*back_button = new nanogui::Button(nanoguiWindow, "Main Menu");
	nanogui::Button	*exit_button = new nanogui::Button(nanoguiWindow, "Exit");

	back_button->setCallback([&]
	{
		_menuState = MenuState::MAIN_MENU;
	});

	exit_button->setCallback([&]
	{
		_gameState = GameState::EXIT;
		_menuState = MenuState::EXIT;
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::END)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::pausedMenu()
{
	setCallbacks();
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Game Paused");
	nanoguiWindow->setLayout(new nanogui::GroupLayout);

	nanogui::Button	*play_button = new nanogui::Button(nanoguiWindow, "Play");
	nanogui::Button	*save_button = new nanogui::Button(nanoguiWindow, "Save");
	nanogui::Button	*exit_button = new nanogui::Button(nanoguiWindow, "Exit");

	play_button->setCallback([&]
	{
		_gameState = GameState::PLAY;
	});

	save_button->setCallback([&]
	{
		game->save();
		popUpErrorMenu("SAVED", "Access saved games from Main Menu 'Load Game'\n", "OK");
	});

	exit_button->setCallback([&]
	{
		std::cout << "EXITING GAME !!!\n";
		_gameState = GameState::EXIT;
		_menuState = MenuState::EXIT;
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _gameState == GameState::STOP)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::keyMenu()
{
	setCallbacks();
	game->library->resetKeyCallback();
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Key Bindings");
	nanoguiWindow->setLayout(new nanogui::GroupLayout);

	nanogui::Button	*up_button = new nanogui::Button(nanoguiWindow, "Up");
	nanogui::Button	*down_button = new nanogui::Button(nanoguiWindow, "Down");
	nanogui::Button	*left_button = new nanogui::Button(nanoguiWindow, "Left");
	nanogui::Button	*right_button = new nanogui::Button(nanoguiWindow, "Right");
	nanogui::Button	*drop_bomb_button = new nanogui::Button(nanoguiWindow, "Drop Bomb");
	nanogui::Button	*pause_button = new nanogui::Button(nanoguiWindow, "Pause");
	nanogui::Button	*back_button = new nanogui::Button(nanoguiWindow, "Back");

	up_button->setCallback([&]
	{
		popUpKeyMenu("Set 'UP' Key", "Press any key to change 'UP' key.", UP);
	});

	down_button->setCallback([&]
	{
		popUpKeyMenu("Set 'DOWN' Key", "Press any key to change 'DOWN' key.", DOWN);
	});

	left_button->setCallback([&]
	{
		popUpKeyMenu("Set 'LEFT' Key", "Press any key to change 'LEFT' key.", LEFT);
	});

	right_button->setCallback([&]
	{
		popUpKeyMenu("Set 'RIGHT' Key", "Press any key to change 'RIGHT' key.", RIGHT);
	});

	drop_bomb_button->setCallback([&]
	{
		popUpKeyMenu("Set 'DROP BOMB' Key", "Press any key to change 'DROP BOMB' key.", DROP_BOMB_KEY);
	});

	pause_button->setCallback([&]
	{
		popUpKeyMenu("Set 'PAUSE' Key", "Press any key to change 'PAUSE' key.", PAUSE_KEY);
	});

	back_button->setCallback([&]
	{
		_menuState = MenuState::SETTINGS;
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::KEYS)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	nanoguiWindow->dispose();
}

void	Menu::renderMenu()
{
	int		width;
	int		height;

	glfwGetFramebufferSize(_win, &width, &height);
	glViewport( 0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	screen->drawContents();
	screen->drawWidgets();
	glfwSwapBuffers(_win);
}

bool	isTextFile(std::string file)
{
	size_t		pos = file.find(".txt");
	std::string	ex;

	if (pos == std::string::npos)
		return (false);

	std::cout << pos << std::endl;
	ex = file.substr(pos);
	if (ex.size() == 4)
		return (true);
	return (false);
}

std::vector<std::string>	*getFiles(std::vector<std::string> *files)
{
	DIR							*dpdf;
	struct	dirent				*epdf;

	dpdf = opendir("./");

	if (dpdf != NULL)
		while ((epdf = readdir(dpdf)))
			if (isTextFile(epdf->d_name))
				files->push_back(epdf->d_name);
	
	return (files);
}

void	Menu::popUpVolume()
{
	bool						breaker = false;
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Volume");
	nanoguiWindow->setLayout(new nanogui::GroupLayout);
	nanogui::Widget *tools = new nanogui::Widget(nanoguiWindow);

	tools->setLayout(new nanogui::GroupLayout);

	nanogui::Slider	*slider = new nanogui::Slider(tools);
	slider->setValue(0.5f);
	slider->setFixedWidth(80);

	nanogui::TextBox	*textBox = new nanogui::TextBox(tools);
	textBox->setFixedSize(Eigen::Vector2i(60, 25));
	textBox->setValue("50");
	textBox->setUnits("%");

	nanogui::Button	*infobutton = new nanogui::Button(tools, "OK");
	
	slider->setCallback([textBox](float value)
	{
		textBox->setValue(std::to_string((int)(value * 100)));
	});
	
	infobutton->setCallback([&]
	{
		breaker = true;
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && !breaker)
	{
		if (glfwGetKey(_win, GLFW_KEY_ENTER) == GLFW_PRESS || glfwGetKey(_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			breaker = true;
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;
	nanoguiWindow->dispose();
	delete gui;
}

void	Menu::popUpKeyMenu(std::string title, std::string message, int dir)
{
	bool	breaker = false;
	int		key;
		
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), title);
	nanoguiWindow->setLayout(new nanogui::GroupLayout);
	nanogui::Widget *tools = new nanogui::Widget(nanoguiWindow);

	tools->setLayout(new nanogui::GroupLayout);
	new nanogui::Label(tools, message);
	nanogui::Button	*infobutton = new nanogui::Button(tools, "Cancel");
	infobutton->setCallback([&]
	{
		breaker = true;
	});

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && !breaker)
	{
		if (glfwGetKey(_win, GLFW_KEY_ENTER) == GLFW_PRESS || glfwGetKey(_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			breaker = true;
		if ((key = game->library->getMenuKeyPressed()) != 0 && !game->library->isKeySet(key))
		{
			changeKey(dir, key);
			breaker = true;
		}
		else if (game->library->isKeySet(key))
			popUpErrorMenu("ERROR", "Key already set. Please try another key.", "OK");
		key = 0;
		glfwPollEvents();
		renderMenu();
	}

	game->setUp();

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;
	nanoguiWindow->dispose();
	delete gui;
}

void	Menu::popUpErrorMenu(std::string title, std::string message, std::string buttonText)
{
	bool						breaker = false;
	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), title);
	nanoguiWindow->setLayout(new nanogui::GroupLayout);
	nanogui::Widget *tools = new nanogui::Widget(nanoguiWindow);

	tools->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Horizontal,
			nanogui::Alignment::Middle, 0, 6));
	new nanogui::Label(tools, message);
	nanogui::Button	*infobutton = new nanogui::Button(tools, buttonText);
	infobutton->setCallback([&]
	{
		breaker = true;
	});


	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();
	std::cout << "error message" << std::endl;

	while (!glfwWindowShouldClose(_win) && !breaker)
	{
		if (glfwGetKey(_win, GLFW_KEY_ENTER) == GLFW_PRESS || glfwGetKey(_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			breaker = true;
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;
	nanoguiWindow->dispose();
	delete gui;
}

void	Menu::changeCallback()
{
	glfwSetCursorPosCallback(_win, [](GLFWwindow *, double x, double y)
		{
				screen->cursorPosCallbackEvent(x, y);
		}
	);

	glfwSetKeyCallback(_win, [](GLFWwindow *, int key, int scancode, int action, int mods)
		{
			screen->keyCallbackEvent(key, scancode, action, mods);
		}
	);

	glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void	Menu::changeKey(int key, int value)
{
	if (key == UP)
	{
		game->library->setUpKey(value);
		game->setUp();
	}
	else if (key == DOWN)
	{
		game->library->setDownKey(value);
		game->setDown();
	}
	else if (key == LEFT)
	{
		game->library->setLeftKey(value);
		game->setLeft();
	}
	else if (key == RIGHT)
	{
		game->library->setRightKey(value);
		game->setRight();
	}
	else if (key == DROP_BOMB_KEY)
	{
		game->library->setBombKey(value);
		game->setDropBomb();
	}
	else if (key == PAUSE_KEY)
	{
		game->library->setPauseKey(value);
		game->setPause();
	}
	game->library->resetMenuKey();
}