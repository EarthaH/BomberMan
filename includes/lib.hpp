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
#include "../external/soil2/src/SOIL2/SOIL2.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "camera.hpp"
#include "shader.hpp"
#include "Model.hpp"

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
	void draw(int, int, int, int, int, int);
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
	glm::mat4 bomberModel;
	Shader *lightingShader; //ask eartah if this is ok
	Shader *lampShader;
	Shader *shader;
	Model *zombieModelwalk[51];
	Model *bombermanModelWalk[18];
	
	//Model *bombermanModelWalkEG[15];
	Model *bomb;
	Model *indestructableWall;
	Model *destructableWall;
	Model *explosionModel;
	Model *levelUpModel;
	Model *levelDownModel;
	Model *lifeUpgradeModel;
	Model *bombUpgradeModel;
	Model *fireUpgradeModel;
	Model *groundModel;
	Model *groundGrassModel;
	Model *groundEnemyModel;
	Model *groundBomberModel;

	Shader *bomberShaderRun1;
	Model *bomberModelRun1;
	int countModel;
	//float direction;
	//void changeDirection();
	void bombermanLevelBeginLib(glm::vec3 coordintates);
	void bombermanLevelBeginLibOnCamera(glm::vec3 coordintates);
	void calculateNewFrame(float prevEnemyX, float currentEnemyX, float prevEnemyY, float currentEnemyY, float i, glm::mat4 model, Model **modelToDraw, bool cam);
	void changeEnemyPos(int prevEnemyX, int prevEnemyY, int currentEnemyX, int currentEnemyY);
	void DrawBlock(glm::mat4 model, glm::vec3 cubePositions, Model *modelToDraw, int dir);
	void resetKeys();

	float getMovementTime();

	void destroy_window();
	static void drawBorders();

	void	resetCallback();
	void	resetKeyCallback();
	
	int		getUpKey();
	int		getDownKey();
	int		getLeftKey();
	int		getRightKey();
	int		getPauseKey();
	int		getBombKey();
	int		getMapKey();
	int		getMenuKeyPressed();	

	void		setUpKey(int k);
	void		setDownKey(int k);
	void		setLeftKey(int k);
	void		setRightKey(int k);
	void		setPauseKey(int k);
	void		setBombKey(int k);
	void		setMapKey(int k);
	void		resetMenuKey();

	void		setScreen480x270();
	void		setScreen1024x576();
	void		setScreen1152x648();
	void		setScreen1280x720();
	void		setScreen1366x768();
	void		setScreen1600x900();
	void		setScreen1920x1080();
	void		setScreen2560x1440();
	void		setFullscreenMode();
	void		setWindowedMode();

	bool		isKeySet(int);
	bool		isFullSceenMode();
};

#endif


//480 x 270 , 1024x576, 1152x648, 1280x720, 1366x768, 1600x900, 1920x1080, 2560x1440 and 3840x2160.