#include "../includes/game.hpp"

Game::Game() : speed(1000), enemy_movement(0), complete(false)
{
	init();
}

Game::Game(Game const &copy)
{
	*this = copy;
}

Game const &Game::operator=(Game const &copy)
{
	this->enemy_movement = copy.enemy_movement;
	this->complete = copy.complete;
	this->speed = copy.speed;
	this->handle = copy.handle;
	this->level = copy.level;
	this->library = copy.library;
	this->menu = copy.menu;

	return (*this);
}

Game::~Game()
{
	delete handle;
	delete level;
	delete load_handle;
	delete library;
	delete menu;
}

void Game::init()
{
	std::cout << "0.0" << std::endl;
	this->level = new Level();
	this->handle = new Handle(level);
	this->library = new Lib();
	this->load_handle = new Load();
	this->menu = new Menu(library->window);

	/* Calls Menu Loop. To test - uncomment line
		& move lines(303 - 308) to buildShaders() in lib.cpp */
	//menu->menuHandler();

	std::cout << "Your mother!\n";
	library->buildShaders();
}

/* *** *** *** Main Loop *** *** *** */

void Game::start()
{
	int change;
	std::cout << "1.0.0" << std::endl;

	library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));

	while (!glfwWindowShouldClose(this->library->window))
	{
		//std::cout << "1.0.1" << std::endl;
		if ((change = loop()) == 100) //
		{
			//while ((change = loop()) != 0) //0 means game over - this is for gameplay
			//while (!glfwWindowShouldClose(this->library->window))
			//{
			//change = loop();

			//loop();
			//save();
			//load(file);
			//}
			//std::cout << "1.0" << std::endl;
			draw();
		}
		else if (change == LEVEL_UP)
		{
			std::cout << "1.1 - LevelUp" << std::endl;
			levelUp();
			library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));
		}
		else if (change == LEVEL_DOWN)
		{

			std::cout << "1.2" << std::endl;
			levelDown();
			library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));
		}
		else
		{
			std::cout << "1.3" << std::endl;
		}
		//std::cout << "1.4" << std::endl;
	}

	//std::cout << "1.5" << std::endl;
	end();
}

int Game::loop()
{
	if (library->getMovementTime() == 0)
	{
		int key;
		int change_level = 0;

		//for (;;)
		//while (!glfwWindowShouldClose(this->library->window))//why doe si tnot reconize a global??
		//{
		if ((key = this->library->getKey()) != ERR)
		{
			change_level = handle->checkKey(key);
		}
		//if (enemy_movement == 1) //can delete enemy movemnt
		//{
		handle->moveEnemy();
		//enemy_movement = 0
		//}
		handle->checkBombs();
		//if (library->getMovementTime() == 0)
		//{
		///	enemy_movement++;
		//	std::cout << "enemy can move" << std::endl;
		//}
		//	draw(); // this not at the bottom

		if (handle->bomberman->getLife() == 0)
			return (0);
		else if (handle->enemies->size() == 0 && !complete)
			complete = endLevel();
		if (change_level != 0)
			return (change_level);
		//}
		//std::cout << "testing" << std::endl;
	}
	return 100;
}

bool Game::endLevel()
{
	if (level->getLevel() < 4)
		handle->map->update(handle->randomPosition(), LEVEL_UP);
	if (level->getLevel() > 1)
		handle->map->update(handle->randomPosition(), LEVEL_DOWN);

	return (true);
}

void Game::levelUp()
{
	int current_level = level->getLevel();

	delete level;
	delete handle;

	level = new Level(current_level + 1);
	handle = new Handle(level);

	complete = false;
}

void Game::levelDown()
{
	int current_level = level->getLevel();

	delete level;
	delete handle;

	level = new Level(current_level - 1);
	handle = new Handle(level);

	complete = false;
}

void Game::changeLevel(int l)
{
	delete level;
	delete handle;

	level = new Level(l);
	level->num_of_enemies = 0;
	handle = new Handle(level);
}

/* Draw game */

void Game::draw()
{
	library->preDraw();
	//library->clearWindow();
	for (int i = 0; i < level->getHeight(); ++i)
	{
		for (int j = 0; j < level->getWidth(); ++j)
		{
			//std::cout << handle->map->map[j][i] << " ";
			library->draw(level->getHeight(), level->getWidth(), i, j, handle->map->map[j][i]);
		}
		//std::cout << std::endl;
	}
	//std::cout << std::endl;
	//std::cout << std::endl;
	//library->draw(0, 0, 0, 0, 0);
	//this->library->refresh();
	library->postDraw();
}

/* End game */

void Game::end()
{
	gameOver.initialize("../res/sound/gameover.wav");
	gameOver.play(false);
	std::cout << "Game over! Score: " << handle->score << std::endl;

	exit(0);
}

/* Saving and Loading */

void Game::save()
{
	std::ofstream ofs;
	time_t _tm = time(NULL);
	struct tm *curtime = localtime(&_tm);
	std::string file = strcat(asctime(curtime), ".txt");

	ofs.open(file, std::ofstream::out | std::ofstream::app);
	ofs << handle->map->height << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(handle->map->height); i++)
		ofs << handle->map->getMapRow(i) << std::endl;
	ofs << level->getLevel() << " " << handle->score << " ";
	ofs << handle->bomberman->getRange() << " " << handle->bomberman->getLife();
	ofs << " " << handle->bombs->size() << std::endl;
}

void Game::load(char *file)
{
	t_position pos;
	load_handle->load(file);

	changeLevel(load_handle->level);
	handle->map->map = load_handle->map;
	level->num_of_enemies = handle->map->countType(ENEMY);
	handle->score = load_handle->score;
	pos = handle->map->getPosition(BOMBER);
	handle->bomberman->init(pos.x, pos.y);
	handle->bomberman->setRange(load_handle->range);
	handle->bomberman->setLife(load_handle->life);
	handle->initEnemy();
	for (size_t i = 1; i < static_cast<size_t>(load_handle->bomb_size); i++)
		handle->createBomb();
}