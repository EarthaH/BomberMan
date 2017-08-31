#include "../includes/handle.hpp"

Handle::Handle()
{

}

Handle::Handle(int h, int w)
{
    Bomb    bomb(1, 1);

    this->map = new Map(h, w);
    this->bomberman = new Bomber(1, 1);
    this->enemy = new Enemy(this->map);
    this->bombs = new std::vector<Bomb>;

    bombs->push_back(bomb);

    initMap();
}

Handle::Handle(Handle const &copy)
{
    *this = copy;
}

Handle const &Handle::operator=(Handle const &copy)
{
    this->map = copy.map;
    this->bomberman = copy.bomberman;
    this->enemy = copy.enemy;
    this->bombs = copy.bombs;

    return (*this);
}

Handle::~Handle()
{
    delete this->bomberman;
    delete this->enemy;
    delete this->map;
    delete [] this->bombs;
}

void    Handle::initMap()
{
    map->map[this->bomberman->getX()][this->bomberman->getY()] = bomberman->getType();
}

void    Handle::checkKey(int key)
{
    if (key == 103 || key == 101 || key == 100 || key == 102)
        moveBomber(key);
    else if (key == SPACE)
        dropBomb(bomberman->getX(), bomberman->getY());
}

void    Handle::moveBomber(int key)
{
    if (key == 103)
        bomberman->moveDown(map);
    else if (key == 101)
        bomberman->moveUp(map);
    else if (key == 100)
        bomberman->moveLeft(map);
    else if (key == 102)
        bomberman->moveRight(map);

    if (bomberman->getLife() == 0)
        endGame();
    
    map->update(bomberman, bomberman->getType());
}

void    Handle::dropBomb(int x, int y)
{
    int bomb_number = getBomb();

    if (bomb_number != -1)
        bombs->at(bomb_number).activate(x, y);
}

size_t  Handle::getBomb()
{
    for (size_t i = 0; i < bombs->size(); i++)
        if (!bombs->at(i).isActive())
            return (i);
    return (-1);
}

int     Handle::moveEnemy()
{
    enemy->move(this->map);
    map->update(enemy, enemy->getType());

    return (0);
}

void    Handle::checkBombs()
{
    map->clear();

    for (size_t i = 0; i < bombs->size(); i++)
        if (updateBomb(&bombs->at(i)))
            if (bombs->at(i).explode())
                activeBomb(&bombs->at(i));
}

void    Handle::activeBomb(Bomb *bomb)
{
    for (int i = bomb->getX() + 1, r = 0; r < bomb->getRange() && map->isOpen(i, bomb->getY() ); r++, i++)
        map->update(i, bomb->getY(), FIRE);
    for (int i = bomb->getX()  - 1, r = 0; r < bomb->getRange() && map->isOpen(i, bomb->getY()); r++, i--)
        map->update(i, bomb->getY(), FIRE);
    for (int i = bomb->getY() + 1, r = 0; r < bomb->getRange() && map->isOpen(bomb->getX() , i); r++, i++)
        map->update(bomb->getX() , i, FIRE);
    for (int i = bomb->getY() - 1, r = 0; r < bomb->getRange() && map->isOpen(bomb->getX() , i); r++, i--)
        map->update(bomb->getX() , i, FIRE);

    bomb->exploded();
    map->update(bomb, bomb->type());
}

bool    Handle::updateBomb(Bomb *bomb)
{
    if (bomb->isActive())
        map->update(bomb, bomb->type());
    else
        return (false);
    return (true);
}

void    Handle::endGame()
{
    exit(0);
}