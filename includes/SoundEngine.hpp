#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <pthread.h>
#include <al.h>
#include <alc.h>

class Sound
{
	public:
		Sound();
		Sound(float);
		Sound(const char *);
		Sound(Sound const &);
		~Sound();

		Sound const &operator=(Sound const &);

		void	initialize(const char*);
		char*	loadWAV(const char*, int&, int&, int&, int&);
		void	play(bool);
		void	stop();
		void	start();
		void	setVolume(float);

	private:
		unsigned int	_buffer;
		unsigned int	_source;
		bool			_loop = true;
		pthread_t		_thread[5];

		int				_rc;
		void			*_status;
		float			_volume;
};