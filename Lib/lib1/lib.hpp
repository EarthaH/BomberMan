#ifndef LIB_H
# define LIB_H

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <iostream>
#include <Math.h>     // Needed for sin, cos.. so could possibly delete
#include <stdlib.h>
#include "../../includes/IEntity.hpp"
#include <vector>

#define PI 3.14159265f ///migh tbe able to dlete this soon!!
#define SPACE 32

int window_valid = 1;

typedef struct	s_objectsToDraw
{
	int         x;
    int         y;
    char        c;
}				t_objectsToDraw;
/* *** *** *** Might need to make these in .cpp file *** *** *** */

char title[] = "Bomberman Lib 1";  // Windowed mode's title
int windowWidth  = 480;     // Windowed mode's width
int windowHeight = 480;     // Windowed mode's height
int windowPosX   = 0;      // Windowed mode's top-left corner x
int windowPosY   = 0;      // Windowed mode's top-left corner y //change these depending on user input in earthas input
int keyPressed = -1;

int mapWidth;
int mapHeight;

std::vector<s_objectsToDraw> objectsToDraw;
int refreshMillis = 1;



GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

bool fullScreenMode = false;

class   Lib : public IEntity
{
    private:
        int             _number;
        
    public:
        Lib();
        Lib(Lib const &);
        Lib const & operator=(Lib const &);
        ~Lib();
        int         getNumber();
        int         getKey();
        bool        createWindow(int, int);
        void        refresh();
        void        draw(int, int, char);
        void        clearWindow();

        static void Timer(int value);

        static void			display();
        static void			reshape(GLsizei width, GLsizei height);
        static void			specialKeys(int key, int x, int y);
        static void			keyboard(unsigned char key, int x, int y);
        void				initGL();
        static void         drawBorders();
        
};

extern  "C"
{
    Lib    *createLibrary();
    void    deleteLibrary(Lib *library);
};

void destroy_window();

#endif