#include "../includes/game.hpp"

Game::Game() : score(0), speed(1000)
{
	init();
}

Game::Game(Game const &copy)
{
	*this = copy;
}

Game const &Game::operator=(Game const &copy)
{
	this->score = copy.score;
	this->speed = copy.speed;
	this->handle = copy.handle;
	this->level = copy.level;
	this->library = copy.library;

	return (*this);
}

Game::~Game()
{
	delete  handle;
	delete  level;
	delete	load_handle;
	delete	library;
}

void	Game::init()
{
	this->level = new Level();
	this->handle = new Handle(level);
	this->library = new Lib();
	this->load_handle = new Load();

	library->createWindow(level->getHeight(), level->getWidth());

	score = 0;
}

/* *** *** *** Main Loop *** *** *** */

void	Game::start()
{
	int		change;
	//char	file[] = "Test.txt";

	while ((change = loop()) != 0) 
	{
		//save();
		if (change == LEVEL_UP)
			levelUp();
		else if (change == LEVEL_DOWN)
			levelDown();
		//load(file);
	}

	end();
}

int		Game::loop()
{
	int		key;
	int		change_level = 0;
	int		enemy_movement = 0;
	bool	complete = false;

	for (;;)
	{
		if ((key = this->library->getKey()) != ERR)
			change_level = handle->checkKey(key);
		if (enemy_movement == 5)
			enemy_movement = handle->moveEnemy();
		handle->checkBombs();
		enemy_movement++;
		draw();

		if (handle->bomberman->getLife() == 0)
			return (0);
		else if (handle->enemies->size() == 0 && !complete)
			complete = endLevel();
		if (change_level != 0)
			return (change_level);
	}
}

bool	Game::endLevel()
{
	if (level->getLevel() < 4)
		handle->map->update(handle->randomPosition(), LEVEL_UP);
	if (level->getLevel() > 1)
		handle->map->update(handle->randomPosition(), LEVEL_DOWN);

	return (true);
}

void	Game::levelUp()
{
	int		current_level = level->getLevel();

	delete level;
	delete handle;

	level = new Level(current_level + 1);
	handle = new Handle(level);
}

void	Game::levelDown()
{
	int		current_level = level->getLevel();

	delete level;
	delete handle;

	level = new Level(current_level - 1);
	handle = new Handle(level);
}

void	Game::changeLevel(int l)
{
	delete level;
	delete handle;

	level = new Level(l);
	level->num_of_enemies = 0;
	handle = new Handle(level);
}

/* Draw game */

void	Game::draw()
{
	library->clearWindow();
	for (int i = 0; i < level->getHeight(); ++i)
		for (int j = 0; j < level->getWidth(); ++j)
			library->draw(level->getHeight(), level->getWidth(), i, j, handle->map->map[j][i]);
		
	this->library->refresh();
}

/* End game */

void	Game::end()
{
	std::cout << "Game over! Score: " << this->score << std::endl;
	exit(0);
}

/* Saving and Loading */

void	Game::save()
{
	std::ofstream	ofs;
	time_t	_tm = time(NULL);
	struct tm * curtime = localtime(&_tm);
	std::string file = strcat(asctime(curtime), ".txt");

	ofs.open (file, std::ofstream::out | std::ofstream::app);
	ofs << handle->map->height << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(handle->map->height); i++)
		ofs << handle->map->getMapRow(i) << std::endl;
	ofs << level->getLevel() << " " << score << " ";
	ofs << handle->bomberman->getRange() << " " << handle->bomberman->getLife();
	ofs << " " << handle->bombs->size() << std::endl;
}

void	Game::load(char *file)
{
	t_position	pos;
	load_handle->load(file);

	changeLevel(load_handle->level);
	handle->map->map = load_handle->map;
	level->num_of_enemies = handle->map->countType(ENEMY);
	score = load_handle->score;
	pos = handle->map->getPosition(BOMBER);
	handle->bomberman->init(pos.x, pos.y);
	handle->bomberman->setRange(load_handle->range);
	handle->bomberman->setLife(load_handle->life);
	handle->initEnemy();
	for (size_t i = 1; i < static_cast<size_t>(load_handle->bomb_size); i++)
		handle->createBomb();
}