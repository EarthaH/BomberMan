#ifndef GAME_H
# define GAME_H

#include "header.hpp"
#include "IEntity.hpp"
#include <thread>

class   Handle;

class   Game 
{
    private:
        int                             _width;
        int                             _height;
        IEntity                         *_library;
        const char                      *_lib;

    public:
        Game();
        Game(int w, int h);
        Game(Game const &);
        Game const & operator=(Game const &);
        ~Game();
        int     getWidth();
        int     getHeight();
        bool    blockClear();
        void    start();
        void    move();
        void    end();
        void    init();
        void    draw();
        void    setLib();
        void    dlerror_wrapper();
        void    deleteLibrary();
        void    clearMap();

        int     score;
        int     speed;
        void    *dl_handle;
        Handle  *handle;
        
};

#endif