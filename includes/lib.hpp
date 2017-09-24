#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <cmath>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "../external/SOIL2/src/SOIL2/SOIL2.h"
#include <SOIL2.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "camera.hpp"
#include "shader.hpp"

class Lib
{
  private:
	int _number;

  public:
	Lib();
	Lib(Lib const &);
	Lib const &operator=(Lib const &);
	~Lib();
	int getNumber();
	int getKey(); //
	bool createWindow(int, int);
	void draw(int, int, int, int, int);
	void preDraw();
	void postDraw();

	void buildShaders();

	GLFWwindow *window;
	int screenWidth, screenHeight;
	//GLfloat *vertices;
	glm::mat4 projection;
	//GLuint VBO, containerVAO;

	static void Timer(int value);

	static void display();
	static void reshape(GLsizei width, GLsizei height);
	//static void	specialKeys(int key, int x, int y);
	//static void	keyboard(unsigned char key, int x, int y);
	void initGL();

	GLuint containerVBO, containerVAO;
	GLuint containerSmallVBO, containerSmallVAO;
	GLuint containerTallVBO, containerTallVAO;
	GLuint lightVAO;
	GLuint diffuseMapWooden, specularMapWooden, mapStone, mapFire, mapLife, mapBombUp, mapFireUp, mapBlue, mapOrange, mapRed, mapGreen, mapYellow;
	int textureWidth, textureHeight;
	unsigned char *image;
	GLfloat currentFrame;
	GLint lightPosLoc;
	GLint viewPosLoc;
	glm::mat4 view;
	GLint modelLoc;
	GLint viewLoc;
	GLint projLoc;
	glm::mat4 model;
	Shader *lightingShader; //ask eartah if this is ok
	Shader *lampShader;

	void destroy_window();
	static void drawBorders();
};

#endif