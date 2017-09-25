//
// Created by Gabriel GROENER on 2017/09/25.
//

#ifndef BOMBERMAN_MENU_H
#define BOMBERMAN_MENU_H

#include "../includes/handle.hpp"

class menu {

public:
    enum class State {
        START,
        END,
        PAUSE,
        SETTINGS,
        SAVE,
        LOAD,
        LEVEL
    };

    menu( void );
    menu( GLFWwindow *window, int width, int height );
    ~menu( void );

    menu( menu const & copy );
    menu& operator=( menu const & copy );

    void    setWinPosition(nanogui::Window *window, Eigen::Vector2i vec);
    void    setWinLayout(nanogui::Window *window);

};

#endif //BOMBERMAN_MENU_H
