#include "../includes/game.hpp"

//int		Game::gameState = 0;
int			Handle::_left = 0;
int			Handle::_right = 0;
int			Handle::_up = 0;
int			Handle::_down = 0;
int			Handle::_drop_bomb = 0;
int			Handle::_pause = 0;

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

	return (*this);
}

Game::~Game()
{
	delete handle;
	delete level;
	delete load_handle;
	delete library;
}

void Game::init()
{
	//std::cout << "0.0" << std::endl;
	this->level = new Level();
	this->handle = new Handle(level);
	this->library = new Lib();
	this->load_handle = new Load();

	//std::cout << "this is where i will do my keybindings" << std::endl;
//	std::cout << this->library->getUpKey() << std::endl;
//	std::cout << this->library->getDownKey() << std::endl;
//	std::cout << this->library->getLeftKey() << std::endl;
//	std::cout << this->library->getRightKey() << std::endl;
//	std::cout << this->library->getPauseKey() << std::endl;
//	std::cout << this->library->getBombKey() << std::endl;
//
//	this->library->setUpKey();
//	this->library->setDownKey();
//	this->library->setLeftKey();
//	this->library->setRightKey();
//	this->library->setPauseKey();
//	this->library->setBombKey();
//	CURRENT_KEY_UP << std::endl;
//
//
	Handle::_down = this->library->getDownKey();
	Handle::_up = this->library->getUpKey();
	Handle::_left = this->library->getLeftKey();
	Handle::_right = this->library->getRightKey();
	Handle::_pause = this->library->getPauseKey();
	Handle::_drop_bomb = this->library->getBombKey();

//	std::cout << std::endl << this->library->getUpKey() << std::endl;
//	std::cout << this->library->getDownKey() << std::endl;
//	std::cout << this->library->getLeftKey() << std::endl;
//	std::cout << this->library->getRightKey() << std::endl;
//	std::cout << this->library->getPauseKey() << std::endl;
//	std::cout << this->library->getBombKey() << std::endl;
}

int logicKey = -1;
/* *** *** *** Main Loop *** *** *** */

int	Game::start()
{
	int change;

	library->buildShaders();
	std::cout << "unpause" << std::endl;
	library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));
	gameState = 1;
	library->resetKeys();

	while (!glfwWindowShouldClose(this->library->window))
	{
		if (gameState != 1)
			return (gameState);
		if (logicKey == -1)
			logicKey = this->library->getKey();
		if ((change = loop()) == 100)
			draw();
		else if (change == LEVEL_UP)
		{//!!!!!!!!!!!!!!!!
			library->resetKeys();
			levelUp();
			library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));
		}
		else if (change == LEVEL_DOWN)
		{//!!!!!!!!!!!!!!!!
			library->resetKeys();
			levelDown();
			library->bombermanLevelBeginLib(glm::vec3(((level->getHeight() - 1) / 2), level->getWidth(), ((level->getWidth() - 1) / 2)));
		}
		else if (gameState == 2)
		{
			return (gameState);
		}
		else
		{
			end();
			return (gameState);
		}
	}

	end();
	return (gameState);
}

int Game::loop()
{
	int key;
	int change_level = 0;

	if (library->getMovementTime() == 0)
	{	
		if ((key = logicKey) != -1)
		{
			change_level = handle->checkKey(key);
			logicKey = -1;
		}
		handle->moveEnemy();
		handle->checkBombs();
	}
	if (handle->bomberman->getLife() == 0)
		return (0);
	else if (handle->enemies->size() == 0 && !complete)
		complete = endLevel();
	if (change_level != 0)
		return (change_level);
	return 100;
}

bool Game::endLevel()
{
	if (level->getLevel() == 4)
		gameState = 0;
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

	for (int i = 0; i < level->getHeight(); ++i)
	{
		for (int j = 0; j < level->getWidth(); ++j)
		{
			if (handle->map->map[j][i] == ENEMY)
			{
				t_position	pos = handle->enemyOldPosition(i, j);
				library->changeEnemyPos(pos.oldX, pos.oldY, pos.x, pos.y);
			}
			int libDir = 0;
			if (handle->map->map[j][i] == 1)
			{
				libDir = handle->bomberman->getDirection();
			}
			else if ( handle->map->map[j][i] == 3)
			{
				libDir = handle->findEnemy(i, j);
			}
			library->draw(level->getHeight(), level->getWidth(), i, j, handle->map->map[j][i], libDir);
		}
	}
	library->postDraw();
}

/* End game */

void Game::end()
{
	handle->map->update(handle->bomberman->getX(), handle->bomberman->getY(), FIRE);
	for (size_t i = 0; i < handle->bombs->size(); i++)
		handle->map->update(handle->bombs->at(i)->getX(), handle->bombs->at(i)->getY(), FIRE);
	draw();
	sleep(2);
	gameOver.initialize("res/sound/gameover.wav");
	gameOver.play(false);
	//std::cout << "Game over! Score: " << handle->score << std::endl;
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

void Game::save(std::string file)
{
	std::ofstream ofs;

	ofs.open(file);
	ofs << handle->map->height << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(handle->map->height); i++)
		ofs << handle->map->getMapRow(i) << std::endl;
	ofs << level->getLevel() << " " << handle->score << " ";
	ofs << handle->bomberman->getRange() << " " << handle->bomberman->getLife();
	ofs << " " << handle->bombs->size() << std::endl;
}

void Game::load(std::string file)
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

void Game::setGameState(int state)
{
	gameState = state;
}

void Game::setUp()
{
	Handle::_up = library->getUpKey();
}

void Game::setDown()
{
	Handle::_down = library->getDownKey();
}

void Game::setLeft()
{
	Handle::_left = library->getLeftKey();
}

void Game::setRight()
{
	Handle::_right = library->getRightKey();
}

void Game::setDropBomb()
{
	Handle::_drop_bomb = library->getBombKey();
}

void Game::setPause()
{
	Handle::_pause = library->getPauseKey();
}