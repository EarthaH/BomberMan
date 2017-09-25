#include "GameState.hpp"

GameState::GameState( void ) {};

GameState::~GameState( void ) {
};

GameState::GameState(GameState const &copy) {
	*this = copy;
};

GameState&		GameState::operator=(GameState const &copy) {
    if (this != &copy) {
        *this = copy;
    }
	return *this;
};

void            GameState::setTitle(char *title) {
    this->TITLE = strdup(title);
};

void            GameState::startMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Welcome to Bomberman");
    ref<Window> startWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
    
    startWindow->setPosition(Vector2i(15, 15));
    startWindow->setLayout(new GroupLayout());

    /* No need to store a pointer, the data structure will be automatically
    freed when the parent window is deleted */
    new Label(startWindow, "Start a new Bomberman game", "sans-bold");
    Button *newBut = new Button(startWindow, "New Game");
    newBut->setCallback([] { std::cout << "pushed!" << std::endl; });
    newBut->setTooltip("Will initiate a new Bomberman game");

    new Label(startWindow, "Load an existing Bomberman game", "sans-bold");
    Button *loadBut = new Button(startWindow, "Load Game");
    loadBut->setCallback([] { std::cout << "pushed!" << std::endl; });
    loadBut->setTooltip("Will load an existing Bomberman game");

    new Label(startWindow, "Exit Bombeman", "sans-bold");
    Button *exitBut = new Button(startWindow, "Exit");
    exitBut->setCallback([] { std::cout << "pushed!" << std::endl; });
    exitBut->setTooltip("Are you sure?");
};

void            GameState::endMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("End Menu");
    ref<Window> startWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};

void            GameState::pauseMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Pause Menu");
    ref<Window> startWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};

void            GameState::settingsMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Settings Menu");
    ref<Window> settingsWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};

void            GameState::saveMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Save Menu");
    ref<Window> saveWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};

void            GameState::loadMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Load Menu");
    ref<Window> loadWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};

void            GameState::levelMenu(nanogui::FormHelper *gui) {
    this->TITLE = strdup("Level Menu");
    ref<Window> levelWindow = gui->addWindow(Eigen::Vector2i(20, 20), this->TITLE);
};