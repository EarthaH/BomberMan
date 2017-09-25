#pragma once

#include <iostream>
#include <cstring>
#include <nanogui/nanogui.h>

#include "Menu.hpp"

using namespace nanogui;

class GameState {

public:
    char   *TITLE = nullptr;

    GameState( void );
	~GameState( void );

	GameState( GameState const & copy );
	GameState& operator=( GameState const & copy );

    void    setTitle(char *title);
    void    startMenu(nanogui::FormHelper *gui);
    void    endMenu(nanogui::FormHelper *gui);
    void    pauseMenu(nanogui::FormHelper *gui);
    void    settingsMenu(nanogui::FormHelper *gui);
    void    saveMenu(nanogui::FormHelper *gui);
    void    loadMenu(nanogui::FormHelper *gui);
    void    levelMenu(nanogui::FormHelper *gui);
};
