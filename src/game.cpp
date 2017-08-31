#include "../includes/game.hpp"

Game::Game() : _width(300), _height(300), score(0), speed(1000)
{
    init();
}

Game::Game(int w, int h) : _width(w), _height(h), score(0), speed(500)
{
    init();
}

Game::Game(Game const &copy)
{
    *this = copy;
}

Game const &Game::operator=(Game const &copy)
{
    this->_width = copy._width;
    this->_height = copy._height;
    return (*this);
}

Game::~Game()
{
    delete  handle;
    dlclose(this->dl_handle);
}

void Game::init()
{
    this->_lib = LIB1;
    this->handle = new Handle(_height, _width);

    setLib();

    score = 0;
}

/* *** *** *** Main Loop *** *** *** */

void Game::start()
{
    int key;
    int enemy_movement = 0;
    
    for (;;)
    {
        if ((key = this->_library->getKey()) != ERR)
            handle->checkKey(key);
        if (enemy_movement == 5)
            enemy_movement = handle->moveEnemy();
        handle->checkBombs();
        enemy_movement++;
        
        draw();
    }
}

/* Library handling */

void Game::setLib()
{
    IEntity *(*lib_ptr)();

    this->dl_handle = dlopen(this->_lib, RTLD_LAZY | RTLD_LOCAL);
    if (!this->dl_handle)
        dlerror_wrapper();
    lib_ptr = (IEntity * (*)()) dlsym(dl_handle, "createLibrary");
    if (!lib_ptr)
        dlerror_wrapper();
        
    this->_library = lib_ptr();
    if (!this->_library->createWindow(this->_height - 1, this->_width - 1))
        std::cout << "Window not created." << std::endl;
}

void Game::deleteLibrary()
{
    void    (*lib_del)(IEntity *);

    lib_del = (void (*)(IEntity*)) dlsym(dl_handle, "deleteLibrary");

    if (!lib_del)
        dlerror_wrapper();

    lib_del(this->_library);
    dlclose(dl_handle);
}

void Game::dlerror_wrapper()
{
    std::cerr << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}
/* Draw game */

void Game::draw()
{
    _library->clearWindow();
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
            _library->draw(i, j, handle->map->map[j][i]);
        
    this->_library->refresh();
}

/* End game */

void Game::end()
{
    std::cout << "Game over! Score: " << this->score << std::endl;
    exit(0);
}

int Game::getWidth()
{
    return (this->_width);
}

int Game::getHeight()
{
    return (this->_height);
}