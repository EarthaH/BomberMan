#include "../includes/lib.hpp"

// Function prototypes
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow *window, double xPos, double yPos);
void DoMovement();
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera camera(glm::vec3(3.0f, 3.0f, 3.0f)); //where the camera inits at !!!@@@
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
int CURRENT_KEY_UP = GLFW_KEY_UP;
int CURRENT_KEY_DOWN = GLFW_KEY_DOWN;
int CURRENT_KEY_LEFT = GLFW_KEY_LEFT;
int CURRENT_KEY_RIGHT = GLFW_KEY_RIGHT;
int CURRENT_KEY_BOMB = 32;
int CURRENT_KEY_P = GLFW_KEY_P;
bool firstMouse = true;

// Light attributes
glm::vec3 lightPos(10.0f, 10.0f, 10.0f);

// Deltatime
GLfloat deltaTime = 0.0f; // Time between current frame and last frame
GLfloat lastFrame = 0.0f; // Time of last frame
GLfloat movementTime = 0.0f;
GLfloat velocity = 0.0f;
GLfloat movementSpeed = 6.0f;

float prevEnemyX = 0.0f;
float prevEnemyY = 0.0f;
float currentEnemyX = 0.0f;
float currentEnemyY = 0.0f;

float prevBomberX = 0.0f;
float prevBomberY = 0.0f;
float currentBomberX = 0.0f;
float currentBomberY = 0.0f;

float framesPerChar = 15;
float gameSpeed = 0.35f;

typedef struct s_objectsToDraw
{
	int x;
	int y;
	char c;
} t_objectsToDraw;

int keyPressed = -1;

std::vector<s_objectsToDraw> objectsToDraw;

bool fullScreenMode = false;

Lib::Lib()
{
	createWindow(0, 0);
	_number = 1;
	shader = new Shader("res/graphics/shaders/modelLoading.vs", "res/graphics/shaders/modelLoading.frag");



	GLchar zombieWalkStr00[] = "res/graphics/models/3enemy/walk/walk00.obj";
	zombieModelwalk00 = new Model(zombieWalkStr00);

	GLchar bombermanWalkStr00[] = "res/graphics/models/1bomberman/walk/walk00.obj";
	bombermanModelWalk00 = new Model(bombermanWalkStr00);

	GLchar bombStr[] = "res/graphics/models/2bomb/Models and Textures/bomb.obj";
	bomb = new Model(bombStr);

	GLchar indestructableWallStr[] = "res/graphics/models/4indestructableWall/cube.obj";
	indestructableWall = new Model(indestructableWallStr);
	
	GLchar destructableWallStr[] = "res/graphics/models/5destructableWall/cube.obj"; 
	destructableWall = new Model(destructableWallStr);
	
	GLchar explosionModelStr[] = "res/graphics/models/6explosion/cube.obj"; 
	explosionModel = new Model(explosionModelStr);
	
	GLchar levelUpModelStr[] = "res/graphics/models/7levelUp/cube.obj"; 
	levelUpModel = new Model(levelUpModelStr);
	
	GLchar levelDownModelStr[] = "res/graphics/models/8levelDown/cube.obj"; 
	levelDownModel = new Model(levelDownModelStr);
	
	GLchar lifeUpgradeModelStr[] = "res/graphics/models/9lifeUpgrade/cube.obj"; 
	lifeUpgradeModel = new Model(lifeUpgradeModelStr);
	
	GLchar bombUpgradeModelStr[] = "res/graphics/models/10bombUpgrade/cube.obj"; 
	bombUpgradeModel = new Model(bombUpgradeModelStr);
	
	GLchar fireUpgradeModelStr[] = "res/graphics/models/11fireUpgrade/cube.obj"; 
	fireUpgradeModel = new Model(fireUpgradeModelStr);
	
	GLchar groundModelStr[] = "res/graphics/models/0open/ground/cube.obj"; 
	groundModel = new Model(groundModelStr);
	
	GLchar groundEnemyModelStr[] = "res/graphics/models/0open/groundEnemy/cube.obj"; 
	groundEnemyModel = new Model(groundEnemyModelStr);

	GLchar groundBomberModelStr[] = "res/graphics/models/0open/groundBomber/cube.obj"; 
	groundBomberModel = new Model(groundBomberModelStr);

	GLchar groundGrassModelStr[] = "res/graphics/models/0open/ground Copy/cube.obj"; 
	groundGrassModel = new Model(groundGrassModelStr);
	//lightingShader = new Shader("res/graphics/shaders/lighting.vs", "res/graphics/shaders/lighting.frag"); //ask eartah if this is ok
	//lampShader = new Shader("res/graphics/shaders/lamp.vs", "res/graphics/shaders/lamp.frag");
}

Lib::Lib(Lib const &copy)
{
	*this = copy;
}

Lib const &Lib::operator=(Lib const &copy)
{
	this->_number = copy._number;
	return (*this);
}

Lib::~Lib()
{
}

void Lib::bombermanLevelBeginLib(glm::vec3 coordintates)
{
	camera.bombermanLevelBegin(coordintates);
}

int Lib::getNumber()
{
	return (this->_number);
}

int Lib::getUpKey()
{
	return CURRENT_KEY_UP;
}

int Lib::getDownKey()
{
	return CURRENT_KEY_DOWN;
}

int Lib::getLeftKey()
{
	return CURRENT_KEY_LEFT;
}

int Lib::getRightKey()
{
	return CURRENT_KEY_RIGHT;
}

int Lib::getPauseKey()
{
	return CURRENT_KEY_P;
}

int Lib::getBombKey()
{
	return CURRENT_KEY_BOMB;
}

void Lib::setUpKey()
{
	CURRENT_KEY_UP = GLFW_KEY_W;
}

void Lib::setDownKey()
{
	CURRENT_KEY_DOWN = GLFW_KEY_S;
}

void Lib::setLeftKey()
{
	CURRENT_KEY_LEFT = GLFW_KEY_A;
}

void Lib::setRightKey()
{
	CURRENT_KEY_RIGHT = GLFW_KEY_D;
}

void Lib::setPauseKey()
{
	CURRENT_KEY_P = GLFW_KEY_ESCAPE;
}

void Lib::setBombKey()
{
	CURRENT_KEY_BOMB = GLFW_KEY_B;
}

int Lib::getKey()
{
	if (keys[CURRENT_KEY_UP])
	{
		//		keys[GLFW_KEY_UP] = false;
		return (CURRENT_KEY_UP);
	}

	if (keys[CURRENT_KEY_DOWN])
	{
		//		keys[GLFW_KEY_DOWN] = false;
		return (CURRENT_KEY_DOWN);
	}

	if (keys[CURRENT_KEY_LEFT])
	{
		//		keys[GLFW_KEY_LEFT] = false;
		return (CURRENT_KEY_LEFT);
	}

	if (keys[CURRENT_KEY_RIGHT])
	{
		//		keys[GLFW_KEY_RIGHT] = false;
		return (CURRENT_KEY_RIGHT);
	}

	if (keys[CURRENT_KEY_BOMB])
	{
		//		keys[32] = false;
		return (CURRENT_KEY_BOMB);
	}

	if (keys[CURRENT_KEY_P])
	{
		return (CURRENT_KEY_P);
	}

	int key = keyPressed;
	keyPressed = -1;
	return (key);
}

bool Lib::createWindow(int height, int width)
{
	(void)height;
	(void)width;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	glfwGetFramebufferSize(this->window, &this->screenWidth, &this->screenHeight); //this might not be neceesary

	if (nullptr == this->window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(this->window);

	glfwGetFramebufferSize(this->window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

	glfwSetKeyCallback(this->window, KeyCallback);
	glfwSetCursorPosCallback(this->window, MouseCallback);

	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glEnable(GL_DEPTH_TEST);

	return 1;
}

void Lib::buildShaders()
{



		
	this->projection = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100.0f);
}

void Lib::Timer(int value)
{
	(void)value;
	std::cout << "Timer" << std::endl;
}

float Lib::getMovementTime()
{
	return movementTime;
}

void Lib::preDraw()
{
	currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	movementTime = movementTime + deltaTime;
	;
	if (movementTime > gameSpeed) //this is essentally n second - maybe add movementTrue attribute
	{
		//std::cout << "teting" << std::endl;
		movementTime = 0.0f;
	}

	velocity = movementSpeed * deltaTime; //this is how fast the camera moves or minions move

	glfwPollEvents();
	glClearColor(0.48627f, 0.98823f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->Use();

	view = camera.GetViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));

	//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	//glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Draw the container (using container's vertex attributes)
}

void Lib::draw(int nheight, int nwidth, int x, int y, int ch)
{
	(void)nwidth;
	(void)nheight;



	if (ch == 0)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}

	if (ch == 5 || ch > 11)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		destructableWall->Draw(*shader);
	}

	else if (ch == 4)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		indestructableWall->Draw(*shader);
		
	}
	else if (ch == 6)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		explosionModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 9)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		lifeUpgradeModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 10)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		bombUpgradeModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 11)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		fireUpgradeModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 1) //bomber
	{
		/*float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		bombermanModelWalk00->Draw(*shader); 


		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundBomberModel->Draw(*shader);*/
		model = glm::mat4();
		float hasBlockBeenDrawn = 0.0f;
		
		float a = x;
		float b = y;
		currentBomberX = x;
		currentBomberY = y;

	
		if (prevBomberX != 0.0f && (prevBomberX != currentBomberX || prevBomberY != currentBomberY))
		{
			for(float index = 0.0f; index != framesPerChar; index = index + 1.0f)
			{
				if ((movementTime <= gameSpeed / framesPerChar * index) && (movementTime > gameSpeed / framesPerChar * (index - 1.0f)))
				{
					
					hasBlockBeenDrawn = 1.0f;
					calculateNewFrame(prevBomberX, currentBomberX, prevBomberY, currentBomberY, index, model, bombermanModelWalk00, true);
					//bomberModelRun1->Draw( *bomberShaderRun1 );
				}
			}
			if (((movementTime ) <= gameSpeed / framesPerChar * framesPerChar) && hasBlockBeenDrawn != 1.0f )
			{
				hasBlockBeenDrawn = 1.0f;
				calculateNewFrame(prevBomberX, currentBomberX, prevBomberY, currentBomberY, framesPerChar, model, bombermanModelWalk00, true);
				//bomberModelRun1->Draw( *bomberShaderRun1 );
				prevBomberX = currentBomberX;
				prevBomberY = currentBomberY;
			}
		}
		if (hasBlockBeenDrawn == 0.0f)
		{
			DrawBlock(model, glm::vec3(a, 0.0f, b), bombermanModelWalk00);

			//bomberShaderRun1->Use( );
			//
			//glm::mat4 view = camera.GetViewMatrix( );
			//glUniformMatrix4fv( glGetUniformLocation( bomberShaderRun1->Program, "projection" ), 1, GL_FALSE, glm::value_ptr( projection ) );
			//glUniformMatrix4fv( glGetUniformLocation( bomberShaderRun1->Program, "view" ), 1, GL_FALSE, glm::value_ptr( view ) );
			//
			//// Draw the loaded model
			////glm::mat4 model;
			//bomberModel = glm::translate( bomberModel, glm::vec3( a, 0.0f, b) ); // Translate it down a bit so it's at the center of the scene
			//bomberModel = glm::scale( bomberModel, glm::vec3( 0.2f, 0.2f, 0.2f ) );	// It's a bit too big for our scene, so scale it down
			//glUniformMatrix4fv( glGetUniformLocation( bomberShaderRun1->Program, "model" ), 1, GL_FALSE, glm::value_ptr( bomberModel ) );
			//bomberModelRun1->Draw( *bomberShaderRun1 );
		}
		if (prevBomberX == 0.0f)
		{
			prevBomberX = currentBomberX;
			prevBomberY = currentBomberY;

		}
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundBomberModel->Draw(*shader);
	}
	else if (ch == 2)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a + 1.335f, 0.0f, b + 0.15f));
 		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		bomb->Draw(*shader);


		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 3) //enemy
	{
		/*float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		zombieModelwalk00->Draw(*shader);
		
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundEnemyModel->Draw(*shader);*/
		

		model = glm::mat4();
		float hasBlockBeenDrawn = 0.0f;
		float a = x;
		float b = y;
		currentEnemyX = x;
		currentEnemyY = y;
		
		if (prevEnemyX != 0.0f && (prevEnemyX != currentEnemyX || prevEnemyY != currentEnemyY))
		{
			for(float index = 0.0f; index != framesPerChar; index = index + 1.0f)
			{
				if ((movementTime < gameSpeed / framesPerChar * index) && (movementTime > gameSpeed / framesPerChar * (index - 1.0f)))
				{
					
					hasBlockBeenDrawn = 1.0f;
					calculateNewFrame(prevEnemyX, currentEnemyX, prevEnemyY, currentEnemyY, index, model, zombieModelwalk00, false);
				}
			}
			if (((movementTime ) <= gameSpeed / framesPerChar * framesPerChar) && hasBlockBeenDrawn != 1.0f )
			{
				
				hasBlockBeenDrawn = 1.0f;
				calculateNewFrame(prevEnemyX, currentEnemyX, prevEnemyY, currentEnemyY, framesPerChar, model, zombieModelwalk00, false);
				prevEnemyX = currentEnemyX;
				prevEnemyY = currentEnemyY;
			}
		}
		if (hasBlockBeenDrawn == 0.0f)
		{
			DrawBlock(model, glm::vec3(a, 0.0f, b), zombieModelwalk00);
			/*model = glm::mat4();
			model = glm::translate(model, glm::vec3(a, 0.0f, b));
			model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
			glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			zombieModelwalk00->Draw(*shader);*/
		}
		if (prevEnemyX == 0.0f)
		{
			prevEnemyX = currentEnemyX;
			prevEnemyY = currentEnemyY;

		}
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundEnemyModel->Draw(*shader);

		/*
		float hasBlockBeenDrawn = 0.0f;
		glBindVertexArray(containerTallVAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapRed);
		float a = x;
		float b = y;
		currentEnemyX = x;
		currentEnemyY = y;
		//std::cout << "needs to be drawn" << std::endl;
		if (prevEnemyX != 0.0f && (prevEnemyX != currentEnemyX || prevEnemyY != currentEnemyY))
		{
			for(float index = 0.0f; index != framesPerChar; index = index + 1.0f)
			{
				if ((movementTime < gameSpeed / framesPerChar * index) && (movementTime > gameSpeed / framesPerChar * (index - 1.0f)))
				{
					//std::cout << "1 drawn" << std::endl;
					hasBlockBeenDrawn = 1.0f;
					calculateNewFrame(prevEnemyX, currentEnemyX, prevEnemyY, currentEnemyY, index, model, modelLoc, false);
				}
			}
			if (((movementTime ) <= gameSpeed / framesPerChar * framesPerChar) && hasBlockBeenDrawn != 1.0f )
			{
				//std::cout << "2 drawn 000000000000000000000000000000000000000" << std::endl;
				hasBlockBeenDrawn = 1.0f;
				calculateNewFrame(prevEnemyX, currentEnemyX, prevEnemyY, currentEnemyY, framesPerChar, model, modelLoc, false);
				prevEnemyX = currentEnemyX;
				prevEnemyY = currentEnemyY;
			}
		}
		if (hasBlockBeenDrawn == 0.0f)
		{
			//std::cout << "0 drawn" << std::endl;
			DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		}
		if (prevEnemyX == 0.0f)
		{
			prevEnemyX = currentEnemyX;
			prevEnemyY = currentEnemyY;

		}*/
	}
	else if (ch == 7)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		levelUpModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
	else if (ch == 8)
	{
		float a = x;
		float b = y;
		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, 0.0f, b));
 		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		levelDownModel->Draw(*shader);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(a, -1.0f, b));
		//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		groundModel->Draw(*shader);
	}
}

void Lib::postDraw()
{
	glfwSwapBuffers(window);
}

void Lib::destroy_window()
{
	glfwTerminate();
	std::cout << "destroy window" << std::endl;
}

void Lib::display() //maybe dlete this
{
	std::cout << "display" << std::endl;
}

void Lib::drawBorders()
{
	std::cout << "drawBorders" << std::endl;
}

void Lib::reshape(GLsizei width, GLsizei height)
{
	(void)width;
	(void)height;
	std::cout << "reshape" << std::endl;
	/*if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else
	{
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);*/
}

void Lib::initGL()
{
	std::cout << "initGl" << std::endl;
}

void MouseCallback(GLFWwindow *window, double xPos, double yPos) //this needs to be set up for the menue instead
{
	(void)window; //cannot remove from top cuase it is needed
	(void)xPos;
	(void)yPos;
}

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
	(void)scancode;
	(void)mode;
	//if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
	//{
	//	glfwSetWindowShouldClose(window, GL_TRUE);
	//}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}
}

void DoMovement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
	{
		camera.ProcessKeyboard(FORWARD, deltaTime);
	}

	if (keys[GLFW_KEY_S])
	{
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	}

	if (keys[GLFW_KEY_A])
	{
		camera.ProcessKeyboard(LEFT, deltaTime);
	}

	if (keys[GLFW_KEY_D])
	{
		camera.ProcessKeyboard(RIGHT, deltaTime);
	}
}

void Lib::DrawBlock(glm::mat4 model, glm::vec3 cubePositions, Model *modelToDraw)
{
	/*model = glm::mat4();
 		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));();
	model = glm::translate(model, cubePositions);
	//GLfloat angle = 20.0f * i;
	//model = glm::rotate( model, angle, glm::vec3( 1.0f, 0.3f, 0.5f ) );
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLES, 0, 36);*/
	//model = glm::mat4();
 	//model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));();
	//model = glm::translate(model, cubePositions);
	//GLfloat angle = 20.0f * i;
	//model = glm::rotate( model, angle, glm::vec3( 1.0f, 0.3f, 0.5f ) );
	


	//model = glm::mat4();
	model = glm::translate(model, cubePositions);
	model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	modelToDraw->Draw(*shader);
	

	//std::cout << "this needs to change " << std::endl;
}

void Lib::changeEnemyPos(int prevEnX, int prevEnY, int currentEnX, int currentEnY)
{
	prevEnemyX = prevEnX;
	prevEnemyY = prevEnY;
}

void Lib::calculateNewFrame(float prevX, float currentX, float prevY, float currentY, float i, glm::mat4 model, Model *modelToDraw, bool cam)
{
	if (prevX < currentX)
	{
		if (cam)
		{
			//bombermanLevelBeginLib(glm::vec3((prevX + (1.0f / framesPerChar * i)), 11.0f, currentY));
		
		}
		model = glm::rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		DrawBlock(model, glm::vec3((prevX + (1.0f / framesPerChar * i)), 0.0f, currentY), modelToDraw);

		//model = glm::rotate(-90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	}
	else if (prevX > currentX)
	{
		if (cam)
		{
			//bombermanLevelBeginLib(glm::vec3((prevX - (1.0f / framesPerChar * i)), 11.0f, currentY));
		}
		DrawBlock(model, glm::vec3((prevX - (1.0f / framesPerChar * i)), 0.0f, currentY), modelToDraw);
	}
	if (prevY < currentY)
	{
		if (cam)
		{
			//bombermanLevelBeginLib(glm::vec3(currentX, 11.0f, (prevY + (1.0f / framesPerChar * i))));
		}
		DrawBlock(model, glm::vec3(currentX, 0.0f, (prevY + (1.0f / framesPerChar * i))), modelToDraw);
	}
	else if (prevY > currentY)
	{
		if (cam)
		{
			//bombermanLevelBeginLib(glm::vec3(currentX, 11.0f, (prevY - (1.0f / framesPerChar * i))));
		}
		DrawBlock(model, glm::vec3(currentX, 0.0f, (prevY - (1.0f / framesPerChar * i))), modelToDraw);
	}
}

void Lib::resetCallback()
{
	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(this->window, KeyCallback);
	glfwSetCursorPosCallback(this->window, MouseCallback);

	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}