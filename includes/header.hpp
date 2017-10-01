#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>//
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dlfcn.h>
#include <curses.h>
#include <vector>

#include "base.hpp"
#include "SoundEngine.hpp"
#include "game.hpp"
#include "man.hpp"
#include "bomb.hpp"
#include "bomber.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "handle.hpp"
#include "level.hpp"
#include "lib.hpp"
#include "menu.hpp"
//#include "camera.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define SPACE 32

#define LIB1 "lib1.so"

bool	equal(Base &, Base &);
bool	equal(Base &, int, int);

#endif