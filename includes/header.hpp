#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dlfcn.h>
#include <curses.h>
#include <vector>

#include "object.hpp"
#include "game.hpp"
#include "man.hpp"
#include "bomb.hpp"
#include "bomber.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define LIB1 "lib1.so"

bool    equal(Object &, Object &);
bool    equal(Object &, int, int);

#endif