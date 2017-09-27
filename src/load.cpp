#include "../includes/load.hpp"

Load::Load()
{
    this->map_size = 0;
    this->level = 0;
    this->score = 0;
    this->range = 0;
    this->life = 0;
    this->bomb_size = 0;
}

Load::Load(char *file)
{
    load(file);
}

Load::Load(Load const & copy)
{
	*this = copy;
}

Load::~Load()
{

}

Load const & Load::operator=(Load const & copy)
{
    this->map_size = copy.map_size;
    this->level = copy.level;
    this->score = copy.score;
    this->range = copy.range;
    this->life = copy.life;
    this->bomb_size = copy.bomb_size;
    this->map = copy.map;

	return (*this);
}

void	Load::load(std::string file)
{
	std::ifstream		ifs(file);
	std::stringstream	buffer;
	std::vector<char *>	lines;

	buffer << ifs.rdbuf();
	std::string	buf = buffer.str();
	char	str[buf.length()];
	char	c[] = " \n";

	for (int i = 0; i < static_cast<int>(buf.length()); i++)
		str[i] = buf[i];
	lines = split(str, c);
	convert(&lines);
}

void	Load::convert(std::vector<char *> *lines)
{
	map_size = str_to_int(lines->at(0));
	char	c[] = ":";

	for (size_t i = 1; i <= static_cast<size_t>(map_size); i++)
		map.push_back(split_num(lines->at(i), c));
	
	level = str_to_int(lines->at(++map_size));
	score = str_to_int(lines->at(++map_size));
	range = str_to_int(lines->at(++map_size));
	life = str_to_int(lines->at(++map_size));
	bomb_size = str_to_int(lines->at(++map_size));
}

std::vector<char *>			Load::split(char *str, char *c)
{
	char					*pch;
	std::vector<char *>		res;

	pch = std::strtok(str, c);
	while (pch != NULL)
	{
		res.push_back(pch);
		pch = std::strtok(NULL, c);
	}
	return (res);
}

std::vector<int>			Load::split_num(char *str, char *c)
{
	int					num;
	char				*pch;
	std::vector<int>	res;

	pch = std::strtok(str, c);
	while (pch != NULL)
	{
		num = str_to_int(pch);
		res.push_back(num);
		pch = std::strtok(NULL, c);
	}
	return (res);
}

int						Load::str_to_int(char *str)
{
	int					num;
	std::stringstream	ss(str);

	ss >> num;
	if (!ss)
		return (0);
	return (num);
}