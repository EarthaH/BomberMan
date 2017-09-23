#include "../includes/handle.hpp"

Handle::Handle()
{

}

Handle::Handle(Level *level)
{
	
	this->map = new Map(level->getWidth(), level->getHeight());

	Bomb	*bomb = new Bomb(1, 1);

	this->bomberman = new Bomber(1, 1);
	this->enemies = new std::vector<Enemy *>;
	this->bombs = new std::vector<Bomb *>;

	bombs->push_back(bomb);
	initMap(level);
	for (int i = 0; i < level->num_of_enemies; i++)
		createEnemy(i);
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
	delete this->enemies;
	delete this->bombs;
}

void	Handle::initMap(Level *level)
{
	map->map[this->bomberman->getX()][this->bomberman->getY()] = bomberman->getType();
	placeUpgrades(level->num_of_upgrades);
	placeWalls(level->num_of_blocks);
}

void	Handle::createEnemy(int num)
{
	Enemy   *enemy = new Enemy(randomPosition(), num);

	enemies->push_back(enemy);
}

void	Handle::createEnemy(int num, t_position pos)
{
	Enemy   *enemy = new Enemy(pos, num);

	enemies->push_back(enemy);
}

int 	Handle::checkKey(int key)
{
	if (key == 103 || key == 101 || key == 100 || key == 102)
		return (moveBomber(key));
	else if (key == SPACE)
        dropBomb(bomberman->getX(), bomberman->getY());
    return (0);
}

int     Handle::moveBomber(int key)
{
    int     res;

	if (key == 103)
		bomberman->moveDown(map);
	else if (key == 101)
		bomberman->moveUp(map);
	else if (key == 100)
		bomberman->moveLeft(map);
	else if (key == 102)
		bomberman->moveRight(map);
	
	res = checkUpgrades();
    map->update(bomberman, bomberman->getType());
    
    return (res);
}

void	Handle::dropBomb(int x, int y)
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

int	 Handle::moveEnemy()
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

void	Handle::killEnemy(int x, int y)
{
	size_t  num;

	if (enemies->size() == 0)
		return ;
	for (num = 0; num < enemies->size(); num++)
		if (enemies->at(num)->getX() == x && enemies->at(num)->getY() == y)
			break;
	if (enemies->at(num)->getX() != x && enemies->at(num)->getY() != y)
		return ;
	enemies->erase(enemies->begin() + num);
	map->update(x, y, OPEN);
}

void	Handle::checkBombs()
{	
	map->clear();

	for (size_t i = 0; i < bombs->size(); i++)
		if (updateBomb(bombs->at(i)))
			if (bombs->at(i)->explode())
				activeBomb(bombs->at(i));
}

int     Handle::checkUpgrades()
{
	int	 block = map->getType(bomberman->getX(), bomberman->getY());

	if (block == BOMB_UPGRADE)
		createBomb();
	else if (block == FIRE_UPGRADE)
		bomberman->upgradeRange();
	else if (block == LIFE_UPGRADE)
        bomberman->upgradeLife();
    else if (block == LEVEL_UP)
        return (LEVEL_UP);
    else if (block == LEVEL_DOWN)
        return (LEVEL_DOWN);
    return (0);
}

void	Handle::createBomb()
{
	Bomb	*bomb = new Bomb(1, 1);
	bombs->push_back(bomb);
}

void	Handle::activeBomb(Bomb *bomb)
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
	if (bomb->getX() == bomberman->getX() && bomb->getY() == bomberman->getY())
		bomberman->playerHit();
	map->update(bomb, bomb->type());
}

void	Handle::findBomb(int x, int y)
{
	size_t  num;

	for (num = 0; num < bombs->size(); num++)
		if (bombs->at(num)->getX() == x && bombs->at(num)->getY() == y)
			break;
	activeBomb(bombs->at(num));
}

void	Handle::placeWalls(int num)
{
	map->update(1, 3, BLOCK);
	map->update(3, 1, BLOCK);

	for (int i = 0; i < num; i++)
		map->update(randomPosition(), BLOCK);
}

void	Handle::placeUpgrades(int num)
{
	for (int i = 0; i < num; i++)
	{
		map->update(randomPosition(), LIFE_UPGRADE + BLOCK);
		map->update(randomPosition(), BOMB_UPGRADE + BLOCK);
		map->update(randomPosition(), FIRE_UPGRADE + BLOCK);
	}
}

void	Handle::initEnemy()
{
	int		count = map->countType(ENEMY);

	if (count > 0)
		createEnemy(0, map->getPosition(ENEMY));

	for (int i = 1; i < count; i++)
	{
		createEnemy(i);
		enemies->at(i)->init(map->getPosition(enemies->at(i - 1)->getX(), enemies->at(i - 1)->getY(), ENEMY));
	}
		
}

bool	Handle::checkMapFire(int x, int y)
{
	if (map->isOpen(x, y))
		return (true);
	else if (map->isType(x, y, BOMBER))
		this->bomberman->playerHit();
	else if (map->isType(x, y, ENEMY))
		killEnemy(x, y);
	else if (map->isType(x, y, BLOCK) || map->isUpgrade(x, y))
		map->update(x, y, OPEN);
	else if (map->getType(x, y) > 9)
		map->update(x, y, map->getType(x, y) - BLOCK);
	else if (map->isType(x, y, BOMB))
		findBomb(x, y);

	return (false);
}

bool	Handle::updateBomb(Bomb *bomb)
{
	if (bomb->isActive())
		map->update(bomb, bomb->type());
	else
		return (false);
	return (true);
}

t_position  Handle::randomPosition()
{
	t_position  pos;
	int	 x = 0;
	int	 y = 0;

	while (!map->blockStart(x, y))
	{
		x = rand() % (map->width - 2) + 1;
		y = rand() % (map->height - 2) + 1;
	}
	pos.x = x;
	pos.y = y;

	return (pos);
}