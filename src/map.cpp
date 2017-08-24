#include "../includes/map.hpp"

Map::Map() : width(100), height(100)
{
    init();
}

Map::Map(int w, int h) : width(w), height(h)
{
    init();
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

void Map::init()
{
    map.resize(height);
    for (int i = 0; i < height; ++i)
    {
        map[i].resize(width);
        map[i][0] = map[i][width - 1] = WALL;
    }
    for (int i = 0; i < width; ++i)
        map[0][i] = map[height - 1][i] = WALL;
    for (int i = 2; i < (width - 2); i += 2)
        for (int j = 2; j < (height - 2); j += 2)
            map[j][i] = WALL;
}

void Map::update(int x, int y, int type)
{
    map[y][x] = type;
}

void Map::update(Object *obj, int type)
{
    if (isType(obj->getOldX(), obj->getOldY(), type))
        map[obj->getOldY()][obj->getOldX()] = OPEN;
    map[obj->getY()][obj->getX()] = type;
}

void Map::clear()
{
    for (int i = 1; i < (width - 1); i++)
        for (int j = 1; j < (height - 1); j++)
            if (map[j][i] == FIRE)
                map[j][i] = OPEN;
}

bool Map::isOpen(int x, int y)
{
    if (map[y][x] == OPEN || map[y][x] == UPGRADE)
        return true;
    return false;
}

bool Map::isType(int x, int y, int type)
{
    if (map[y][x] == type)
        return true;
    return false;
}