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
    delete this->bomberman;
    delete this->enemy;
    delete this->map;
    delete [] this->bombs;
    dlclose(this->dl_handle);
}

void Game::init()
{
    const char *libs[1] = {LIB1};
    this->_libs = libs;

    this->map = new Map(_height, _width);

    setLib(0);
    this->bomberman = new Bomber(1, 1);
    this->enemy = new Enemy(this->map);
    Bomb bomb(1, 1);
    this->bombs = new std::vector<Bomb>;

    bombs->push_back(bomb);

    initMap();

    score = 0;
}

void Game::initMap()
{
    map->map[this->bomberman->getX()][this->bomberman->getY()] = bomberman->getType();
}

/* *** *** *** Main Loop *** *** *** */

void Game::start()
{
    int key;
    int enemy_movement = 0;
    
    for (;;)
    {
        map->clear();
        if ((key = this->_library->getKey()) != ERR)
            changeDir(key);
        if (enemy_movement == 5)
        {
            enemy->move(this->map);
            map->update(enemy, enemy->getType());
            enemy_movement = 0;
        }
        for (size_t i = 0; i < bombs->size(); i++)
            if (bombs->at(i).isActive())
                bombs->at(i).countDown(map);
        enemy_movement++;
        
        draw();
    }
}

/* Library handling */

void Game::setLib(int num)
{
    IEntity *(*lib_ptr)();

    this->dl_handle = dlopen(this->_libs[num], RTLD_LAZY | RTLD_LOCAL);
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
            _library->draw(i, j, map->map[j][i]);
        
    this->_library->refresh();
}

/* Move bommberman in set direction */

void Game::changeDir(int key)
{
    if (key == 103)
        bomberman->move(DOWN, map);
    else if (key == 101)
        bomberman->move(UP, map);
    else if (key == 100)
        bomberman->move(LEFT, map);
    else if (key == 102)
        bomberman->move(RIGHT, map);
    else if (key == SPACE)
        dropBomb(bomberman->getX(), bomberman->getY());

    if (bomberman->getLife() == 0)
        end();
    map->update(bomberman, bomberman->getType());
}

void Game::dropBomb(int x, int y)
{
    int bomb_number = getBomb();

    if (bomb_number != -1)
        bombs->at(bomb_number).activate(x, y);
}

size_t Game::getBomb()
{
    for (size_t i = 0; i < bombs->size(); i++)
        if (!bombs->at(i).isActive())
            return (i);
    return (-1);
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