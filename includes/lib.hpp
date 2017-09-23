#ifndef LIB_H
# define LIB_H

#include <iostream>
#include <cmath>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "../SOIL2/SOIL2.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "camera.hpp"
#include "shader.hpp"





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
		int			getKey();//
		bool		createWindow(int, int);
		void		draw(int, int, int, int, char);
		void		buildShaders();



		GLFWwindow *window;
		int screenWidth, screenHeight;
    	//GLfloat *vertices;
		glm::mat4 projection;
		//GLuint VBO, containerVAO;

		static void Timer(int value);

		static void	display();
		static void	reshape(GLsizei width, GLsizei height);
		//static void	specialKeys(int key, int x, int y);
		//static void	keyboard(unsigned char key, int x, int y);
		void		initGL();

		void destroy_window();
		static void	drawBorders();
		
};


#endif