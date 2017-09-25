#include "Menu.hpp"
#include "GameState.hpp"
#include "KeyInput.hpp"

using namespace nanogui;

nanogui::Color colval(0.5f, 0.5f, 0.7f, 1.f);
nanogui::Screen *screen = nullptr;

KeyInput *input = nullptr;;

Menu::Menu( void ) {};

Menu::Menu( GLFWwindow *window, int width, int height ) {

    screen = new nanogui::Screen();
    screen->initialize(window, true);

    // Create nanogui gui
    // bool enabled = true;
    nanogui::FormHelper *gui = new nanogui::FormHelper(screen);

    State state = State::START;

    switch(state) {
        case State::START : {
            GameState start;
            start.startMenu(gui);
            break;
        }
        case State::END : {
            GameState end;
            end.endMenu(gui);
            break;
        }
        case State::PAUSE : {
            GameState pause;
            pause.pauseMenu(gui);
            break;
        }
        case State::SETTINGS : {
            GameState settings;
            settings.settingsMenu(gui);
            break;
        }
        case State::SAVE : {
            GameState save;
            save.saveMenu(gui);
            break;
        }
        case State::LOAD : {
            GameState load;
            load.loadMenu(gui);
            break;
        }
        case State::LEVEL : {
            GameState level;
            level.levelMenu(gui);
            break;
        }
        default :
            break;
    }

    screen->setVisible(true);
    screen->performLayout();
    // nanoguiWindow->center();

    glfwSetCursorPosCallback(window,
        [](GLFWwindow *, double x, double y) {
            screen->cursorPosCallbackEvent(x, y);
        }
    );

    glfwSetMouseButtonCallback(window,
        [](GLFWwindow *, int button, int action, int modifiers) {
            screen->mouseButtonCallbackEvent(button, action, modifiers);
        }
    );

    glfwSetKeyCallback(window,
        [](GLFWwindow *, int key, int scancode, int action, int mods) {
            keyCallbackEvent(key, scancode, action, mods);
        }
    );

    glfwSetCharCallback(window,
        [](GLFWwindow *, unsigned int codepoint) {
            screen->charCallbackEvent(codepoint);
        }
    );

    glfwSetDropCallback(window,
        [](GLFWwindow *, int count, const char **filenames) {
            screen->dropCallbackEvent(count, filenames);
        }
    );

    glfwSetScrollCallback(window,
        [](GLFWwindow *, double x, double y) {
            screen->scrollCallbackEvent(x, y);
        }
    );

    glfwSetFramebufferSizeCallback(window,
        [](GLFWwindow *, int width, int height) {
            screen->resizeCallbackEvent(width, height);
        }
    );

    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        glClearColor(0.2f, 0.25f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nanogui
        screen->drawContents();
        screen->drawWidgets();

        glfwSwapBuffers(window);
    }

};

Menu::~Menu( void ) {
	glfwTerminate();
};

Menu::Menu(Menu const &copy) {
	*this = copy;
};

Menu&		Menu::operator=(Menu const &copy) {
    if (this != &copy) {
        *this = copy;
    }
	return *this;
};

void        Menu::setWinPosition(nanogui::Window *window, Eigen::Vector2i vec) {
    window->setPosition(vec);
};

void        Menu::setWinLayout(nanogui::Window *window) {
    window->setLayout(new GroupLayout());
};

void keyCallbackEvent(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        input->esc = true;
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        input->space = true;
 
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
        input->esc = false;
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
        input->space = false;
    
}