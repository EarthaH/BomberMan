#include "../includes/menu.hpp"

#include <nanogui/nanogui.h>
#include <nanogui/screen.h>
#include <nanogui/widget.h>
#include <utility>
#include <vector>
#include <fstream>
#include <dirent.h>

nanogui::Screen		*screen = nullptr;

Menu::Menu(GLFWwindow * pWin) : _win(pWin), _menuState(MenuState::MAIN_MENU)
{

}

Menu::~Menu()
{
	glfwTerminate();
}

void	Menu::menuHandler()
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

	screen = new nanogui::Screen;

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

	//Break when time to play :D !!!
	while (_menuState != MenuState::EXIT)
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
				loadMenu();
				break;
			case MenuState::EXIT :
				std::cout << "What the fuck impossible" << std::endl;
		}
	}

	//delete screen;
}

void	Menu::mainMenu()
{
	/* NEEDED FOR EVERY NEW MENU */
	screen->initialize(_win, true);

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
	// delete new_game_button;
	// delete load_game_button;
	// delete settings_button;
	// delete exit_button;
	// delete gui;
}

void	Menu::settingsMenu()
{
	std::cout << "Welcome to Settings Menu!\n";
	//screen->initialize(_win, true);
	std::cout << "++++++++++++++++++++++++\n";

	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), "Settings");

	std::cout << "NanoGui pointer created!\n";
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
		std::cout << "Key Bindings!\n";
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

	std::cout << "Starting Loop!\n";

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::SETTINGS)
	{
		glfwPollEvents();
		renderMenu();
	}

	if (glfwWindowShouldClose(_win))
		_menuState = MenuState::EXIT;

	std::cout << "Exiting Menu!\n";

	nanoguiWindow->dispose();
	// delete screen_res_button;
	// delete full_screen_button;
	// delete key_bindings_button;
	// delete sound_button;
	// delete back_button;
	// delete gui;
}

void	Menu::loadMenu()
{
	// char						buffer[4242];
	// char						*dir = getcwd(buffer, sizeof(buffer));
	// std::string					cwd;
	// std::vector<std::string>	*files = new std::vector<std::string>();

	// if (dir)
	// 	cwd = dir;

	// for (auto &p : std::filesystem::directory_iterator(cwd))
	// 	if (isTextFile(p))
	// 		files->push_back(p);

	DIR				*dpdf;
	struct	dirent	*epdf;

	dpdf = opendir("./");

	if (dpdf != NULL)
		while ((epdf = readdir(dpdf)))
			std::cout << epdf->d_name << std::endl;

	screen->initialize(_win, true);

	nanogui::FormHelper	*gui = new nanogui::FormHelper(screen);
	nanogui::ref<nanogui::Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(100, 100), "Load");

	nanoguiWindow->setLayout(new nanogui::GroupLayout);

	//new nanogui::ComboBox(_win, files);

	screen->setVisible(1);
	screen->performLayout();
	nanoguiWindow->center();

	while (!glfwWindowShouldClose(_win) && _menuState == MenuState::LOAD)
	{
		glfwPollEvents();
		renderMenu();
	}

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

bool	Menu::isTextFile(std::string file)
{
	// size_t		pos = file.find(".txt");
	// std::string	ex;

	// if (pos == -1)
	// 	return (false);

	// ex = file.substr(pos);
	// if (ex.compare(".txt"))
	// 	return (true);
	return (false);
}

void	Menu::popUpErrorMenu(std::string title, std::string message, std::string buttonText)
{
	std::cout << "HELLLO" << std::endl;
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