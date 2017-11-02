#ifndef HANDLE_H
# define HANDLE_H

#include "header.hpp"
#include <thread>

class   Bomber;
class   Map;
class   Enemy;
class   Bomb;
class   Level;

class   Handle 
{
	private:

	Sound explosion;
    Sound powerUp;
    Sound killedEnemySound;

	public:
		Handle();
		Handle(Level *);
		Handle(Handle const &);
		Handle const & operator=(Handle const &);
		~Handle();

		int						score;
		Map					 	*map;
		Bomber				  	*bomberman;
		std::vector<Enemy *>	*enemies;
		std::vector<Bomb *>	 	*bombs;

		int		 	moveEnemy();
		int		 	checkKey(int);
		int			moveBomber(int);
		int			checkUpgrades();
		void		initMap(Level *);
		void		checkBombs();
		void		createBomb();
		void		initEnemy();
		
		void		dropBomb(int, int);
		void		activeBomb(Bomb *);
		void		createEnemy(int);
		void		createEnemy(int, t_position);
		void		killEnemy(int, int);
		void		placeWalls(int);
		void		placeUpgrades(int);
		void		findBomb(int, int);
		bool		updateBomb(Bomb *);
		bool		checkMapFire(int, int);
		t_position  randomPosition();
		t_position	enemyOldPosition(int, int);
		size_t		getBomb();
};

#endif