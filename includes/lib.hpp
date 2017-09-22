#ifndef LIB_H
# define LIB_H

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <iostream>
#include <Math.h>
#include <stdlib.h>
#include <vector>

#define PI 3.14159265f
#define SPACE 32



class   Lib
{
	private:
		int			 _number;
		
	public:
		Lib();
		Lib(Lib const &);
		Lib const & operator=(Lib const &);
		~Lib();
		int			getNumber();
		int			getKey();
		bool		createWindow(int, int);
		void		refresh();
		void		draw(int, int, int, int, char);
		void		clearWindow();

		static void Timer(int value);

		static void	display();
		static void	reshape(GLsizei width, GLsizei height);
		static void	specialKeys(int key, int x, int y);
		static void	keyboard(unsigned char key, int x, int y);
		void		initGL();
		static void	drawBorders();
		
};

void destroy_window();

#endif