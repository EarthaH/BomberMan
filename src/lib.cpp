#include "../includes/lib.hpp"


// Function prototypes
void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode );
void MouseCallback( GLFWwindow *window, double xPos, double yPos );
void DoMovement( );

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera  camera( glm::vec3( 0.0f, 0.0f, 3.0f ) );
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;

// Light attributes
glm::vec3 lightPos( 10.0f, 10.0f, 10.0f );

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

//void DrawBlock(glm::mat4 model, glm::vec3 cubePositions, GLint modelLoc, int i );


int window_valid = 1;


//const GLint WIDTH = 800, HEIGHT = 600;

typedef struct	s_objectsToDraw
{
	int			x;
	int			y;
	char		c;
}				t_objectsToDraw;

char title[]		= "Bomberman Lib 1";
int windowWidth	 = 500;
int windowHeight	= 500;
int windowPosX	  = 0;
int windowPosY	  = 0;
int keyPressed	  = -1;

int mapWidth;
int mapHeight;

std::vector<s_objectsToDraw> objectsToDraw;
//int refreshMillis = 1;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

bool fullScreenMode = false;

Lib::Lib()
{
	_number = 1;
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
	std::cout << "deleting library..." << std::endl;
}

int Lib::getNumber()
{
	return (this->_number);
}

int Lib::getKey()
{
	int	 key = keyPressed;
	keyPressed = -1;
	return (key);
}

bool Lib::createWindow(int height, int width)
{
	(void)height;
	(void)width;
	 // Init GLFW
	 glfwInit( );
	 
	 // Set all the required options for GLFW
	 glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	 glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	 glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	 glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	 glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
	 
	 // Create a GLFWwindow object that we can use for GLFW's functions
	 this->window = glfwCreateWindow( WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr );
	 
	 int screenWidth, screenHeight;
	 glfwGetFramebufferSize( window, &screenWidth, &screenHeight );
	 
	 if ( nullptr == window )
	 {
		 std::cout << "Failed to create GLFW window" << std::endl;
		 glfwTerminate( );
		 
		 return EXIT_FAILURE;
	 }
	 
	 glfwMakeContextCurrent( window );
	 
	 // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	 glewExperimental = GL_TRUE;
	 // Initialize GLEW to setup the OpenGL Function pointers
	 if ( GLEW_OK != glewInit( ) )
	 {
		 std::cout << "Failed to initialize GLEW" << std::endl;
		 return EXIT_FAILURE;
	 }
	 
	 // Define the viewport dimensions
	 glViewport( 0, 0, screenWidth, screenHeight );
	 

	 std::cout << "created window" << std::endl;
	 return 1;
}

void Lib::Timer(int value) {
	(void)value;
	std::cout << "Timer" << std::endl;
}

void Lib::refresh()
{
	std::cout << "refresh" << std::endl;
}

void Lib::draw(int nheight, int nwidth, int x, int y, char ch)
{
	(void)nheight;
	(void)nwidth;
	(void)x;
	(void)y;
	(void)ch;
	// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
	glfwPollEvents( );
	
	// Render
	// Clear the colorbuffer
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
	
	// Swap the screen buffers
	glfwSwapBuffers( window );
	//std::cout << "draw" << std::endl;
	/*s_objectsToDraw	 tempObject;
	tempObject.x = x;
	tempObject.y = y;
	tempObject.c = ch;
	objectsToDraw.push_back(tempObject);
	mapWidth = nwidth;
	mapHeight = nheight;*/
}

void Lib::clearWindow()
{
	std::cout << "clearWindow" << std::endl;
	//objectsToDraw.clear();
}

void destroy_window() { 
	 //window_valid = -1;
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

void MouseCallback( GLFWwindow *window, double xPos, double yPos )
{
    (void)window;//cannot remove from top cuase it is needed
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

void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode )
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
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
        }
    }
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
    // Camera controls
    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
    {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }

    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
    {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }

    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
    {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }

    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
    {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
}