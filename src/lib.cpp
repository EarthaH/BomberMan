#include "../includes/lib.hpp"

int window_valid = 1;

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
int refreshMillis = 1;

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
	try
	{
		char *myargv[1];
		int myargc = 1;
		myargv[0] = strdup("./lib1");

		mapWidth = width;
		mapHeight = height;

		glutInit(&myargc, myargv);
		glutInitDisplayMode(GLUT_DOUBLE);
		glutInitWindowSize(windowWidth, windowHeight);
		glutInitWindowPosition(windowPosX, windowPosY);
		glutCreateWindow("Bomberman");
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);

		glutSpecialFunc(specialKeys);
		glutKeyboardFunc(keyboard);
		glutTimerFunc(refreshMillis, Timer, 0);
		initGL();
	}
	catch (...)
	{
		return (false);
	}
	return (true);
}

void Lib::Timer(int value) {
	(void)value;
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);
}

void Lib::refresh()
{
	glutCheckLoop();
	display();
}

void Lib::draw(int nheight, int nwidth, int x, int y, char ch)
{
	s_objectsToDraw	 tempObject;
	tempObject.x = x;
	tempObject.y = y;
	tempObject.c = ch;
	objectsToDraw.push_back(tempObject);
	mapWidth = nwidth;
	mapHeight = nheight;
}

void Lib::clearWindow()
{
	objectsToDraw.clear();
}

void destroy_window() { 
 window_valid = -1;
}

void Lib::display()
{
	 
	if(window_valid == -1)
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int i = 0; i < static_cast<int>(objectsToDraw.size()); i++)
	{
		float	 v0x, v1x, v2x, v3x;
		float	 v0y, v1y, v2y, v3y;

		v0x = -(1 - (1 / (((float)mapWidth + 1) / 2) * (float)(objectsToDraw.at(i).x + 0)));
		v0y = 1 - (1 / (((float)mapHeight + 1) / 2) * (float)(objectsToDraw.at(i).y + 1));

		v1x = -(1 - (1 / (((float)mapWidth + 1) / 2) * (float)(objectsToDraw.at(i).x + 1)));
		v1y = v0y;

		v2x = v1x;
		v2y = 1 - (1 / (((float)mapHeight + 1) / 2) * (float)(objectsToDraw.at(i).y + 0));

		v3x = v0x;
		v3y = v2y;

		if (objectsToDraw.at(i).c == 0)
		{
			glBegin(GL_QUADS);
			glColor3f(0.0f, 0.2f, 0.0f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 1)
		{
			glBegin(GL_QUADS);
			glColor3f(0.4f, 0.4f, 0.4f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 2)
		{
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();	
		}
		if (objectsToDraw.at(i).c == 3)
		{
			glBegin(GL_QUADS);
			glColor3f(0.2f, 0.2f, 0.2f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 4)
		{
			glBegin(GL_QUADS);
			glColor3f(0.0f, 0.9f, 0.0f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 5)
		{
			glBegin(GL_QUADS);
			glColor3f(0.2f, 0.6f, 0.2f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 6)
		{
			glBegin(GL_QUADS);
			glColor3f(0.6f, 0, 0);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 7)
		{
			glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 8)
		{
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 9)
		{
			glBegin(GL_QUADS);
			glColor3f(0, 0.6f, 0.6f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 10)
		{
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0.3f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c == 11)
		{
			glBegin(GL_QUADS);
			glColor3f(0.2, 0, 0.7f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
		if (objectsToDraw.at(i).c > 11)
		{
			glBegin(GL_QUADS);
			glColor3f(0.2f, 0.6f, 0.2f);
			glVertex2f(v0x, v0y);
			glVertex2f(v1x, v1y);
			glVertex2f(v2x, v2y);
			glVertex2f(v3x, v3y);
			glEnd();
		}
	}
	glutSwapBuffers();
}

void Lib::drawBorders()
{
	float	 v0x, v1x, v2x, v3x;
	float	 v0y, v1y, v2y, v3y;

	v0x = -1.0;
	v0y = 1 - (1 / (((float)mapHeight + 2) / 2));

	v1x = 1.0;
	v1y = 1 - (1 / (((float)mapHeight + 2) / 2));

	v2x = 1.0;
	v2y = 1.0;

	v3x = -1.0;
	v3y = 1.0;


	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(v0x, v0y);
		glVertex2f(v1x, v1y);
		glVertex2f(v2x, v2y);
		glVertex2f(v3x, v3y);
	glEnd();

	v0x = 1 - (1 / (((float)mapWidth + 2) / 2));
	v0y = -1.0;

	v1x = 1.0;
	v1y = -1.0;

	v2x = 1.0;
	v2y = 1.0;

	v3x = 1 - (1 / (((float)mapWidth + 2) / 2));
	v3y = 1.0;

	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(v0x, v0y);
		glVertex2f(v1x, v1y);
		glVertex2f(v2x, v2y);
		glVertex2f(v3x, v3y);
	glEnd();

	v0x = -1.0;
	v0y = -1.0;

	v1x = 1.0;
	v1y = -1.0;

	v2x = 1.0;
	v2y = -(1 - (1 / (((float)mapHeight + 2) / 2)));

	v3x = -1.0;
	v3y = -(1 - (1 / (((float)mapHeight + 2) / 2)));


	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(v0x, v0y);
		glVertex2f(v1x, v1y);
		glVertex2f(v2x, v2y);
		glVertex2f(v3x, v3y);
	glEnd();

	v0x = -1.0;
	v0y = -1.0;

	v1x = -(1 - (1 / (((float)mapWidth + 2) / 2)));
	v1y = -1.0;

	v2x = -(1 - (1 / (((float)mapWidth + 2) / 2)));
	v2y = 1.0;

	v3x = -1.0;
	v3y = 1.0;


	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(v0x, v0y);
		glVertex2f(v1x, v1y);
		glVertex2f(v2x, v2y); 
		glVertex2f(v3x, v3y);
	glEnd();
}

void Lib::reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
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
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

void Lib::specialKeys(int key, int x, int y)
{
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
}

void Lib::keyboard(unsigned char key, int x, int y)
{
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
}

void Lib::initGL()
{
	
}