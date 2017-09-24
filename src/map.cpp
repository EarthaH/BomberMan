#include "../includes/map.hpp"

Map::Map() : width(100), height(100)
{
	init();
}

Map::Map(int w, int h) : width(w), height(h)
{
	init();
}

Map::Map(int w, int h, std::vector<std::vector<int> > loaded_map) : width(w), height(h)
{
	map = loaded_map;
}

Map::Map(Map const &copy)
{
	*this = copy;
}

Map const &Map::operator=(Map const &copy)
{
	this->map = copy.map;
	this->width = copy.width;
	this->height = copy.height;
	return (*this);
}

Map::~Map()
{

}

int		Map::getType(int x, int y)
{
	return (map[y][x]);
}

int		Map::countType(int type)
{
	int		count = 0;

	for (int i = 0; i < (width - 1); i++)
		for (int j = 0; j < (height - 1); j++)
			if (map[j][i] == type)
				count++;

	return (count);
}

void	Map::init()
{
	//std::cout << "Height: " << height << " Width: " << width << std::endl;
	map.resize(height);
	//std::cout << "Map height resized.\n";
	for (int i = 0; i < height; ++i)
	{
		map[i].resize(width);
		map[i][0] = map[i][width - 1] = WALL;
	}
	//std::cout << std::endl << "Map width resized.\n";
	for (int i = 0; i < width; ++i)
		map[0][i] = map[height - 1][i] = WALL;
	//std::cout << "Border walls added.\n";
	for (int i = 2; i < (width - 2); i += 2)
		for (int j = 2; j < (height - 2); j += 2)
			map[j][i] = WALL;
	//std::cout << "Maze walls added.\n";
}

void	Map::update(int x, int y, int type)
{
	map[y][x] = type;
}

void	Map::update(t_position pos, int type)
{
	map[pos.y][pos.x] = type;
}

void	Map::update(Base *obj, int type)
{
	if (isType(obj->getOldX(), obj->getOldY(), type))
		map[obj->getOldY()][obj->getOldX()] = OPEN;
	map[obj->getY()][obj->getX()] = type;
}

void	Map::clear()
{
	for (int i = 1; i < (width - 1); i++)
		for (int j = 1; j < (height - 1); j++)
			if (map[j][i] == FIRE)
				map[j][i] = OPEN;
}

bool	Map::isOpen(int x, int y)
{
	if (map[y][x] == OPEN)
		return true;
	return false;
}

bool	Map::isType(int x, int y, int type)
{
	if (map[y][x] == type)
		return true;
	return false;
}

bool	Map::blockStart(int x, int y)
{
	if ((x == 2 && y == 1) || (x == 1 && y == 2) || (x == 0 && y == 0))
		return (false);
	return (isOpen(x, y));
}

bool	Map::isUpgrade(int x, int y)
{
	if (map[y][x] == FIRE_UPGRADE || map[y][x] == BOMB_UPGRADE || map[y][x] == LIFE_UPGRADE)
		return (true);
	return (false);
}

std::string	Map::getMapRow(int num)
{
	std::string			res;
	std::stringstream	ss;

	for (size_t i = 0; i < static_cast<size_t>(width); i++)
	{
		ss << map[num][i] << (i == static_cast<size_t>(width) - 1 ? "" : ":");
		res = ss.str();
	}
	
	return (res);
}

t_position	Map::getPosition(int Type)
{
	t_position	pos;
	pos.x = pos.y = 1;

	for (int i = 0; i < (width - 1); i++)
		for (int j = 0; j < (height - 1); j++)
			if (map[j][i] == Type)
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
	return (pos);
}

t_position	Map::getPosition(int x, int y, int Type)
{
	t_position	pos;
	int		j = y + 1;

	for (int i = x; i < (width - 1); i++, j = 0)
		for (; j < (height - 1); j++)
			if (map[j][i] == Type)
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
	pos.x = pos.y = 1;
	return (pos);
}