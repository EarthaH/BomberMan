//
// Created by Gabriel GROENER on 2017/09/25.
//
#pragma once
#include "header.hpp"

class Menu {

public:

    Menu();
    Menu(int width, int height, const char& windowName);
    ~Menu();

    void initializeMenu(int width, int height, const char* windowName);

};
