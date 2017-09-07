#include "../includes/handle.hpp"

Handle::Handle()
{

}

Handle::Handle(int h, int w)
{
    
    this->map = new Map(h, w);

    Bomb    *bomb = new Bomb(1, 1);

    this->bomberman = new Bomber(1, 1);
    this->enemies = new std::vector<Enemy *>;
    this->bombs = new std::vector<Bomb *>;

    bombs->push_back(bomb);
    for (int i = 0; i < 5; i++)
        createEnemy(i);

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
    this->enemies = copy.enemies;
    this->bombs = copy.bombs;

    return (*this);
}

Handle::~Handle()
{
    for (size_t i = 0; i < enemies->size(); i++)
        delete enemies->at(i);
    for (size_t i = 0; i < bombs->size(); i++)
        delete bombs->at(i);
    delete this->bomberman;
    delete this->map;
    delete [] this->enemies;
    delete [] this->bombs;
}

void    Handle::initMap()
{
    map->map[this->bomberman->getX()][this->bomberman->getY()] = bomberman->getType();
    placeUpgrades(5);
    placeWalls(15);
}

void    Handle::createEnemy(int num)
{
    Enemy   *enemy = new Enemy(randomPosition(), num);

    enemies->push_back(enemy);
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
    
    checkUpgrades();
    map->update(bomberman, bomberman->getType());
}

void    Handle::dropBomb(int x, int y)
{
    int bomb_number = getBomb();
    
    if (bomb_number != -1)
        bombs->at(bomb_number)->activate(x, y);
}

size_t  Handle::getBomb()
{
    for (size_t i = 0; i < bombs->size(); i++)
        if (!bombs->at(i)->isActive())
            return (i);
    return (-1);
}

int     Handle::moveEnemy()
{
    for (size_t i = 0; i < enemies->size(); i++)
    {
        enemies->at(i)->move(this->map);
        if (map->isType(enemies->at(i)->getX(), enemies->at(i)->getY(), BOMBER))
            bomberman->playerHit();
        map->update(enemies->at(i), ENEMY);
    }
    
    return (0);
}

void    Handle::killEnemy(int x, int y)
{
    size_t  num;

    for (num = 0; num < enemies->size(); num++)
        if (enemies->at(num)->getX() == x && enemies->at(num)->getY() == y)
            break;
    enemies->erase(enemies->begin() + num);
    map->update(x, y, OPEN);
}

void    Handle::checkBombs()
{    
    map->clear();

    for (size_t i = 0; i < bombs->size(); i++)
        if (updateBomb(bombs->at(i)))
            if (bombs->at(i)->explode())
                activeBomb(bombs->at(i));
}

void    Handle::checkUpgrades()
{
    int     block = map->getType(bomberman->getX(), bomberman->getY());

    if (block == BOMB_UPGRADE)
    {
        Bomb    *bomb = new Bomb(1, 1);
        bombs->push_back(bomb);
    }
    else if (block == FIRE_UPGRADE)
        bomberman->upgradeRange();
    else if (block == LIFE_UPGRADE)
        bomberman->upgradeLife();
}

void    Handle::activeBomb(Bomb *bomb)
{
    for (int i = bomb->getX() + 1, r = 0; r < bomberman->getRange() && checkMapFire(i, bomb->getY() ); r++, i++)
        map->update(i, bomb->getY(), FIRE);
    for (int i = bomb->getX()  - 1, r = 0; r < bomberman->getRange() && checkMapFire(i, bomb->getY()); r++, i--)
        map->update(i, bomb->getY(), FIRE);
    for (int i = bomb->getY() + 1, r = 0; r < bomberman->getRange() && checkMapFire(bomb->getX() , i); r++, i++)
        map->update(bomb->getX() , i, FIRE);
    for (int i = bomb->getY() - 1, r = 0; r < bomberman->getRange() && checkMapFire(bomb->getX() , i); r++, i--)
        map->update(bomb->getX() , i, FIRE);

    bomb->exploded();
    map->update(bomb, bomb->type());
}

void    Handle::placeWalls(int num)
{
    for (int i = 0; i < num; i++)
        map->update(randomPosition(), BLOCK);
}

void    Handle::placeUpgrades(int num)
{
    for (int i = 0; i < num; i++)
    {
        map->update(randomPosition(), LIFE_UPGRADE + BLOCK);
        map->update(randomPosition(), BOMB_UPGRADE + BLOCK);
        map->update(randomPosition(), FIRE_UPGRADE + BLOCK);
    }
}

bool    Handle::checkMapFire(int x, int y)
{
    if (map->isOpen(x, y))
        return (true);
    else if (map->isType(x, y, BOMBER))
        this->bomberman->playerHit();
    else if (map->isType(x, y, ENEMY))
        killEnemy(x, y);
    else if (map->isType(x, y, BLOCK))
        map->update(x, y, OPEN);
    else if (map->getType(x, y) > 9)
        map->update(x, y, map->getType(x, y) - BLOCK);
    return (false);
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

t_position  Handle::randomPosition()
{
    t_position  pos;
    int     x = 0;
    int     y = 0;

    while (!map->blockStart(x, y))
    {
        x = rand() % (map->width - 2) + 1;
        y = rand() % (map->height - 2) + 1;
    }
    pos.x = x;
    pos.y = y;

    return (pos);
}