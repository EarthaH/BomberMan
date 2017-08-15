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
    dlclose(this->dl_handle);
}

void Game::init()
{
    const char *libs[3] = {LIB1, LIB2, LIB3};
    this->_libs = libs;

    setLib(0);
    this->bomberman = new Bomber(1, 1);

    score = 0;
}

/* *** *** *** Main Loop *** *** *** */

void Game::start()
{
    int key;
    
    for (;;)
    {
        if ((key = this->_library->getKey()) != ERR)
            changeDir(key);
        draw();
        //std::this_thread::sleep_for(std::chrono::milliseconds(this->speed));
    }
}

/* Library handling */

void Game::setLib(int num)
{
    IEntity *(*lib_ptr)();
    
    //if (this->dl_handle)
    //deleteLibrary();
    //std::cout << num << " " << this->_libs[0]<< " " << 1 << " " << this->_libs[1] << " " << 2 << " " << this->_libs[2] <<std::endl;
    std::cout << num << " Library = " << this->_libs[num] << std::endl;
    std::cout << num << " Library = " << this->_libs[1] << std::endl;

    //std::cout << num << " Library = " << this->_libs[0] << std::endl;
    this->dl_handle = dlopen(this->_libs[num], RTLD_LAZY | RTLD_LOCAL);
    if (!this->dl_handle)
        dlerror_wrapper();
    lib_ptr = (IEntity * (*)()) dlsym(dl_handle, "createLibrary");
    if (!lib_ptr)
        dlerror_wrapper();
        
    this->_library = lib_ptr();
    if (!this->_library->createWindow(this->_height, this->_width))
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
    _library->draw(bomberman->getX(), bomberman->getY(), bomberman->getCh());
        
    this->_library->refresh();
}

/* Move bommberman in set direction */

void Game::changeDir(int key)
{
    if (key == 103)
        bomberman->move(DOWN);
    else if (key == 101)
        bomberman->move(UP);
    else if (key == 100)
        bomberman->move(LEFT);
    else if (key == 102)
        bomberman->move(RIGHT);
}

/* End game */

void Game::end()
{
    delete this->bomberman;
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