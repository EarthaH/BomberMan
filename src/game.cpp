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
	this->_library = copy._library;
	this->_lib = copy._lib;
	this->score = copy.score;
	this->speed = copy.speed;
	this->dl_handle = copy.dl_handle;
	this->handle = copy.handle;
	this->level = copy.level;

	return (*this);
}

Game::~Game()
{
	delete  handle;
	delete  level;
	delete	load_handle;
	dlclose(this->dl_handle);
}

void	Game::init()
{
	this->_lib = LIB1;
	this->level = new Level();
	this->handle = new Handle(level);
	this->load_handle = new Load();

	setLib();

	score = 0;
}

/* *** *** *** Main Loop *** *** *** */

void	Game::start()
{
	int		change;
	//char	file[] = "Test.txt";

	while ((change = loop()) != 0) 
	{
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
		if ((key = this->_library->getKey()) != ERR)
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

/* Library handling */

void	Game::setLib()
{
	IEntity *(*lib_ptr)();

	this->dl_handle = dlopen(this->_lib, RTLD_LAZY | RTLD_LOCAL);
	if (!this->dl_handle)
		dlerror_wrapper();
	lib_ptr = (IEntity * (*)()) dlsym(dl_handle, "createLibrary");
	if (!lib_ptr)
		dlerror_wrapper();
		
	this->_library = lib_ptr();
	if (!this->_library->createWindow(level->getHeight(), level->getWidth()))
		std::cout << "Window not created." << std::endl;
}

void	Game::deleteLibrary()
{
	void	   (*lib_del)(IEntity *);

	lib_del = (void	(*)(IEntity*)) dlsym(dl_handle, "deleteLibrary");

	if (!lib_del)
		dlerror_wrapper();

	lib_del(this->_library);
	dlclose(dl_handle);
}

void	Game::dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}
/* Draw game */

void	Game::draw()
{
	_library->clearWindow();
	for (int i = 0; i < level->getHeight(); ++i)
		for (int j = 0; j < level->getWidth(); ++j)
			_library->draw(level->getHeight(), level->getWidth(), i, j, handle->map->map[j][i]);///!!!!!
		
	this->_library->refresh();
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

	ofs.open ("Test.txt", std::ofstream::out | std::ofstream::app);
	ofs << handle->map->height << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(handle->map->height); i++)
		ofs << handle->map->getMapRow(i) << std::endl;
	ofs << level->getLevel() << " " << score << " ";
	ofs << handle->bomberman->getRange() << " " << handle->bomberman->getLife();
	ofs << " " << handle->bombs->size() << std::endl;
}

void	Game::load(char *file)
{
	load_handle->load(file);

	handle->map->map = load_handle->map;
	level->setLevel(load_handle->level);
	score = load_handle->score;
	handle->bomberman->setRange(load_handle->range);
	handle->bomberman->setLife(load_handle->life);
	for (size_t i = 1; i < static_cast<size_t>(load_handle->bomb_size); i++)
		handle->createBomb();
}