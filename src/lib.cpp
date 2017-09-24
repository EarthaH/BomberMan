#include "../includes/lib.hpp"

GLfloat verticesBigCubes[] =
	{
		// Positions            // Normals              // Texture Coords
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

GLfloat verticesTallCubes[] =
	{
		// Positions            // Normals              // Texture Coords
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.5f, 0.7f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.5f, 0.7f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-0.5f, 0.7f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.7f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.7f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.7f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.7f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.7f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.7f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		0.5f, 0.7f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.7f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-0.5f, 0.7f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.7f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.7f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.7f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.7f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.7f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

GLfloat verticesSmallCubes[] =
	{
		// Positions            // Normals              // Texture Coords
		-0.111f, -0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.111f, -0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.111f, 0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.111f, 0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-0.111f, 0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
		-0.111f, -0.111f, -0.111f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		-0.111f, -0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.111f, -0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.111f, 0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.111f, 0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.111f, 0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.111f, -0.111f, 0.111f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		-0.111f, 0.111f, 0.111f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.111f, 0.111f, -0.111f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.111f, -0.111f, -0.111f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.111f, -0.111f, -0.111f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.111f, -0.111f, 0.111f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.111f, 0.111f, 0.111f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		0.111f, 0.111f, 0.111f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.111f, 0.111f, -0.111f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.111f, -0.111f, -0.111f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.111f, -0.111f, -0.111f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.111f, -0.111f, 0.111f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.111f, 0.111f, 0.111f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.111f, -0.111f, -0.111f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.111f, -0.111f, -0.111f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.111f, -0.111f, 0.111f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.111f, -0.111f, 0.111f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-0.111f, -0.111f, 0.111f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-0.111f, -0.111f, -0.111f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-0.111f, 0.111f, -0.111f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.111f, 0.111f, -0.111f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.111f, 0.111f, 0.111f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.111f, 0.111f, 0.111f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.111f, 0.111f, 0.111f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.111f, 0.111f, -0.111f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

//!!!!!!!!!!!!!!!!many cubes
glm::vec3 cubePositions[] = //array of vectors that are the cube positions becuase we have more than one cube
	{
		glm::vec3(1.0f, 0.0f, 1.0f), //!!!!!!!after running guse which of these cubes applies for which
		glm::vec3(3.0f, 0.0f, 1.0f),
		glm::vec3(5.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 3.0f),
		glm::vec3(3.0f, 0.0f, 3.0f),
		glm::vec3(5.0f, 0.0f, 3.0f),
		glm::vec3(1.0f, 0.0f, 5.0f),
		glm::vec3(3.0f, 0.0f, 5.0f),
		glm::vec3(5.0f, 0.0f, 5.0f),
		glm::vec3(7.0f, 0.0f, 7.0f)};
// Function prototypes
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow *window, double xPos, double yPos);
void DoMovement();
void DrawBlock(glm::mat4 model, glm::vec3 cubePositions, GLint modelLoc);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera camera(glm::vec3(3.0f, 3.0f, 3.0f));//where the camera inits at !!!@@@
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;

// Light attributes
glm::vec3 lightPos(10.0f, 10.0f, 10.0f);

// Deltatime
GLfloat deltaTime = 0.0f; // Time between current frame and last frame
GLfloat lastFrame = 0.0f; // Time of last frame
GLfloat movementTime = 0.0f;
//void DrawBlock(glm::mat4 model, glm::vec3 cubePositions, GLint modelLoc, int i );

//int window_valid = 1;

//const GLint WIDTH = 800, HEIGHT = 600;

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
	lightingShader = new Shader("res/graphics/shaders/lighting.vs", "res/graphics/shaders/lighting.frag"); //ask eartah if this is ok
	lampShader = new Shader("res/graphics/shaders/lamp.vs", "res/graphics/shaders/lamp.frag");

	std::cout << "Library created." << std::endl;
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
	delete lightingShader;
	delete lampShader;
	std::cout << "deleting library..." << std::endl;
}


void Lib::bombermanLevelBeginLib(glm::vec3 coordintates)
{
	camera.bombermanLevelBegin(coordintates);
}

int Lib::getNumber()
{
	return (this->_number);
}

int Lib::getKey()
{
	if (keys[GLFW_KEY_UP])
	{
		return (GLFW_KEY_UP);
	}

	if (keys[GLFW_KEY_DOWN])
	{
		return (GLFW_KEY_DOWN);
	}

	if (keys[GLFW_KEY_LEFT])
	{
		return (GLFW_KEY_LEFT);
	}

	if (keys[GLFW_KEY_RIGHT])
	{
		return (GLFW_KEY_RIGHT);
	}

	if (keys[32])
	{
		return (32);
	}
	int key = keyPressed;
	keyPressed = -1;
	return (key);
}

bool Lib::createWindow(int height, int width)
{
	(void)height;
	(void)width;
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	this->window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	//int screenWidth, screenHeight;
	glfwGetFramebufferSize(this->window, &this->screenWidth, &this->screenHeight);

	if (nullptr == this->window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(this->window);

	//!!!!!!!!!!!!!!!

	glfwGetFramebufferSize(this->window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

	// Set the required callback functions
	glfwSetKeyCallback(this->window, KeyCallback); //!!!!!@@@@may need to make keycallabck this
	glfwSetCursorPosCallback(this->window, MouseCallback);

	// GLFW Options
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//!!!!!!!!!!!!!!

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);

	std::cout << "created window" << std::endl;
	return 1;
}

void Lib::buildShaders()
{
	// Build and compile our shader program
	//   Shader lightingShader("res/graphics/shaders/lighting.vs", "res/graphics/shaders/lighting.frag");
	//   Shader lampShader("res/graphics/shaders/lamp.vs", "res/graphics/shaders/lamp.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers

	//the fucking arrays

	//!!!!!!!!!!!!!!!!many cubes end
	//std::cout << (sizeof(cubePositions) / sizeof(*cubePositions)) << std::endl;

	// First, set the container's VAO (and containerVBO)
	//GLuint containerVBO, containerVAO;
	glGenVertexArrays(1, &containerVAO); //&
	glGenBuffers(1, &containerVBO);		 //&

	glBindBuffer(GL_ARRAY_BUFFER, containerVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBigCubes), verticesBigCubes, GL_STATIC_DRAW);

	glBindVertexArray(containerVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);



	glGenVertexArrays(1, &containerSmallVAO); //&
	glGenBuffers(1, &containerSmallVBO);	  //&

	glBindBuffer(GL_ARRAY_BUFFER, containerSmallVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesSmallCubes), verticesSmallCubes, GL_STATIC_DRAW);

	glBindVertexArray(containerSmallVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	

	glGenVertexArrays(1, &containerTallVAO); //&
	glGenBuffers(1, &containerTallVBO);	  //&

	glBindBuffer(GL_ARRAY_BUFFER, containerTallVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTallCubes), verticesTallCubes, GL_STATIC_DRAW);

	glBindVertexArray(containerTallVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	// Then, we set the light's VAO (containerVBO stays the same. After all, the verticesBigCubes are the same for the light object (also a 3D cube))
	//GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// We only need to bind to the containerVBO (to link it with glVertexAttribPointer), no need to fill it; the containerVBO's data already contains all we need.
	glBindBuffer(GL_ARRAY_BUFFER, containerVBO);
	// Set the vertex attributes (only position data for the lamp))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0); // Note that we skip over the other data in our buffer object (we don't need the normals/textures, only positions).
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	// Load textures
	//GLuint diffuseMapWooden, specularMapWooden, mapStone;
	glGenTextures(1, &diffuseMapWooden);
	glGenTextures(1, &specularMapWooden);
	glGenTextures(1, &mapStone);
	glGenTextures(1, &mapFire);
	glGenTextures(1, &mapLife);
	glGenTextures(1, &mapBombUp);
	glGenTextures(1, &mapFireUp);
	glGenTextures(1, &mapBlue);
	glGenTextures(1, &mapOrange);
	glGenTextures(1, &mapRed);
	glGenTextures(1, &mapGreen);
	glGenTextures(1, &mapYellow);

	//int textureWidth, textureHeight;
	//unsigned char *image;

	// Diffuse map
	image = SOIL_load_image("res/graphics/images/container2.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, diffuseMapWooden);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	// Specular map
	image = SOIL_load_image("res/graphics/images/container2_specular.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, specularMapWooden);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	// Wooden Map
	image = SOIL_load_image("res/graphics/images/stoneWall.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapStone);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	//fire
	image = SOIL_load_image("res/graphics/images/fire.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapFire);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/life.jpg", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapLife);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/bombUp.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapBombUp);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/fireUp.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapFireUp);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/blue.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapBlue);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/orange.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapOrange);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	image = SOIL_load_image("res/graphics/images/red.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapRed);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	image = SOIL_load_image("res/graphics/images/green.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapGreen);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	image = SOIL_load_image("res/graphics/images/yellow.jpg", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, mapYellow);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Set texture units
	lightingShader->Use();
	glUniform1i(glGetUniformLocation(lightingShader->Program, "material.diffuse"), 0);
	glUniform1i(glGetUniformLocation(lightingShader->Program, "material.specular"), 1);

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
	if (movementTime > 0.25f)//this is essentally n second - maybe add movementTrue attribute 
	{
		std::cout << "teting" << std::endl;
		movementTime = 0.0f;
	}

	std::cout << movementTime << " - "<< currentFrame << " " << deltaTime << " " << lastFrame + deltaTime << " " << std::endl;
//!!@@@
	// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
	glfwPollEvents();
	DoMovement();

	// Clear the colorbuffer
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use cooresponding shader when setting uniforms/drawing objects
	lightingShader->Use();
	lightPosLoc = glGetUniformLocation(lightingShader->Program, "light.position");
	viewPosLoc = glGetUniformLocation(lightingShader->Program, "viewPos");
	glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
    //std::cout <<  camera.GetPosition().x << " " << camera.GetPosition().y << " " << camera.GetPosition().z << std::endl;
//!!!@@@
	// Set lights properties
	glUniform3f(glGetUniformLocation(lightingShader->Program, "light.ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(lightingShader->Program, "light.diffuse"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(lightingShader->Program, "light.specular"), 1.0f, 1.0f, 1.0f);

	// Set material properties
	glUniform1f(glGetUniformLocation(lightingShader->Program, "material.shininess"), 32.0f);

	// Create camera transformations
	//glm::mat4 view;
	view = camera.GetViewMatrix();

	// Get the uniform locations
	//GLint modelLoc = glGetUniformLocation(lightingShader->Program, "model");
	//GLint viewLoc = glGetUniformLocation(lightingShader->Program, "view");
	//GLint projLoc = glGetUniformLocation(lightingShader->Program, "projection");
	modelLoc = glGetUniformLocation(lightingShader->Program, "model");
	viewLoc = glGetUniformLocation(lightingShader->Program, "view");
	projLoc = glGetUniformLocation(lightingShader->Program, "projection");

	// Pass the matrices to the shader
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Draw the container (using container's vertex attributes)
}

void Lib::draw(int nheight, int nwidth, int x, int y, int ch)
{

	(void)nwidth;
	(void)nheight;
	// Calculate deltatime of current frame

	//glm::mat4 model;
	if (ch == 5 || ch > 11)
	{
		glBindVertexArray(containerVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMapWooden);

		// Bind specular map
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularMapWooden);
		float a = x;
		float b = y;
		//std::cout << x << "-" << y << " ";
		//std::cout << ch << " ";
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
	}
	else if (ch == 4)
	{
		glBindVertexArray(containerVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapStone);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 2)
	{
		glBindVertexArray(containerVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapFire);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 9)
	{
		glBindVertexArray(containerSmallVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapLife);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 10)
	{
		glBindVertexArray(containerSmallVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapBombUp);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 1)
	{
		glBindVertexArray(containerTallVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapBlue);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 2)
	{
		glBindVertexArray(containerSmallVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapOrange);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 3)
	{
		glBindVertexArray(containerTallVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapRed);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 7)
	{
		glBindVertexArray(containerVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapGreen);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}
	else if (ch == 8)
	{
		glBindVertexArray(containerVAO);
		// Bind diffuse map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mapYellow);
		float a = x;
		float b = y;
		DrawBlock(model, glm::vec3(a, 0.0f, b), modelLoc);
		//std::cout << ch << " ";

		//std::cout << a << "-" << b << " ";
	}

	/*for (int i = 0; i < (nheight * nwidth); i++) //make this dynamic also make one of these foo all different type of cubes
	{
		if (i % 2 == 0)
		{
			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuseMapWooden);

			// Bind specular map
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, specularMapWooden);
			float a = x;
			float b = y;
			std::cout << x << " " << y << " ";
			DrawBlock(model, glm::vec3(b, 0.0f, a), modelLoc);
		}
		else
		{
			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mapStone);
			float a = x;
			float b = y;
			DrawBlock(model, glm::vec3(b, 0.0f, a), modelLoc);

			std::cout << a << " " << b << " ";
		}
	}
	std::cout << std::endl;*/
}

void Lib::postDraw()
{
	//glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( model ) );
	//glDrawArrays( GL_TRIANGLES, 0, 36 );
	glBindVertexArray(0);

	// Also draw the lamp object, again binding the appropriate shader
	lampShader->Use();
	// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
	modelLoc = glGetUniformLocation(lampShader->Program, "model");
	viewLoc = glGetUniformLocation(lampShader->Program, "view");
	projLoc = glGetUniformLocation(lampShader->Program, "projection");

	// Set matrices
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	model = glm::mat4();
	model = glm::translate(model, lightPos);
	model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	// Draw the light object (using light's vertex attributes)
	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);

	// Swap the screen buffers
	glfwSwapBuffers(window);

	//std::cout << "draw" << std::endl;
	/*s_objectsToDraw	 tempObject;
		tempObject.x = x;
		tempObject.y = y;
		tempObject.c = ch;
		objectsToDraw.push_back(tempObject);
		mapWidth = nwidth;
		mapHeight = nheight;*/
}

void Lib::destroy_window()
{
	//window_valid = -1;
	glDeleteVertexArrays(1, &containerVAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &containerVBO);

	// Terminate GLFW, clearing any resources allocated by GLFW.
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

/*void Lib::specialKeys(int key, int x, int y)
{
	std::cout << "Special keys" << std::endl;
	
	(void)x;
	(void)y;
	switch (key)
	{
		case GLUT_KEY_F1:
			fullScreenMode = !fullScreenMode;
			if (fullScreenMode)
			{
				windowPosX = glutGet(GLUT_WINDOW_X);
				windowPosY = glutGet(GLUT_WINDOW_Y);
				windowWidth = glutGet(GLUT_WINDOW_WIDTH);
				windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
				glutFullScreen();
			}
			else
			{
				glutReshapeWindow(windowWidth, windowHeight);
				glutPositionWindow(windowPosX, windowPosX);
			}
			break;
		case GLUT_KEY_LEFT:
			keyPressed = key;
			break;
		case GLUT_KEY_UP:
			keyPressed = key;
			break;
		case GLUT_KEY_RIGHT:
			keyPressed = key;
			break;
		case GLUT_KEY_DOWN:
			keyPressed = key;
			break;
	}
	glutPostRedisplay();
	
}*/

/*void Lib::keyboard(unsigned char key, int x, int y)
{
	std::cout << "keyboard" << std::endl;
	
	(void)x;
	(void)y;
	switch (key)
	{
		case 27:
			exit(0);
			break;
		case 32:
			keyPressed = key;
			break;
	}
}*/

void Lib::initGL()
{
	std::cout << "initGl" << std::endl;
}

void MouseCallback(GLFWwindow *window, double xPos, double yPos)
{
	(void)window; //cannot remove from top cuase it is needed
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos; // Reversed since y-coordinates go from bottom to left

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
	(void)scancode;
	(void)mode;
	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			//std::cout << key << std::endl;
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			//std::cout << keys[key] << std::endl;
			keys[key] = false;
		}
	}
}

// Moves/alters the camera positions based on user input
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

void DrawBlock(glm::mat4 model, glm::vec3 cubePositions, GLint modelLoc)
{
	model = glm::mat4();
	model = glm::translate(model, cubePositions);
	//GLfloat angle = 20.0f * i;
	//model = glm::rotate( model, angle, glm::vec3( 1.0f, 0.3f, 0.5f ) );
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLES, 0, 36);
}