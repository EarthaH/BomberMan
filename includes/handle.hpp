#ifndef HANDLE_H
# define HANDLE_H

#include "header.hpp"
//#include "IEntity.hpp"
#include <thread>

class   Bomber;
class   Map;
class   Enemy;
class   Bomb;
class   Level;

class   Handle 
{
	private:

	public:
		Handle();
		Handle(Level *);
		Handle(Handle const &);
		Handle const & operator=(Handle const &);
		~Handle();

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
		
		void		dropBomb(int, int);
		void		activeBomb(Bomb *);
		void		createEnemy(int);
		void		killEnemy(int, int);
		void		placeWalls(int);
		void		placeUpgrades(int);
		void		findBomb(int, int);
		bool		updateBomb(Bomb *);
		bool		checkMapFire(int, int);
		t_position  randomPosition();
		size_t		getBomb();
};

#endif