OBJS = src/bomber.cpp src/man.cpp src/bomb.cpp src/game.cpp src/main.cpp \
 src/object.cpp src/overflow.cpp src/map.cpp src/enemy.cpp src/handle.cpp \
 src/level.cpp src/load.cpp src/lib.cpp src/camera.cpp src/shader.cpp
 
OBJ_NAME = game

CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++11

COMPILER_FLAGS = -Wall -Werror -Wextra -Wno-unused-parameter -std=c++11

#CFLAGS1 =	-std=c++11 -Wno-deprecated-declarations -O3

#CFLAGS2 = 	-framework OpenGL -framework GLUT -O3 -ltermcap \
			-Wno-deprecated-declarations

LIBRARY = -framework OpenGL -framework AppKit

INCLUDE_PATHS = -I ~/.brew/Cellar/glfw/3.2.1/include \
				-I ~/.brew/Cellar/glew/2.1.0/include \
				-I ~/.brew/Cellar/glm/0.9.8.5/include \
				-I ~/.brew/Cellar/sdl/1.2.15/include \
				-I ~/.brew/Cellar/sdl2/2.0.5/include \
				-I external/nanogui/ext/eigen \
				-I external/nanogui/ext/coro \
				-I external/nanogui/ext/glad \
				-I external/nanogui/ext/nanovg \
				-I external/nanogui/ext/nanovg/src \
				-I external/nanogui/ext/pybind \
				-I external/nanogui/include \
				external/SOIL2/lib/macosx/libsoil2.a

LIBRARY_PATHS = -L ~/.brew/Cellar/glfw/3.2.1/lib \
				-L ~/.brew/Cellar/glew/2.1.0/lib \
				-L ~/.brew/Cellar/glm/0.9.8.5/lib \
				-L ~/.brew/Cellar/sdl/1.2.15/lib \
				-L ~/.brew/Cellar/sdl2/2.0.5/lib \
				-L external/nanogui/build
				

LINKER_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo -framework Carbon -lglfw -lGLEW


all:
	@echo "Compiling code!"
	bash INSTALL.sh
	@$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	@clear
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#   created game    #"
	@echo "#    succesfully    #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

installBrew : 
	@./brewInstall.sh
	@clear
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#   Brew Install    #"
	@echo "#    succesfully    #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

# Steps to install SOIL2
#$ hg clone https://bitbucket.org/SpartanJ/soil2 soil2
#$ cd soil2
#$ premake4 gmake
#$ cd make/*YOUR_PLATFORM_HERE*/
#$ make config=release         (there will be some errors, just ignore)
#$ cd ../../lib/*YOUR_PLATFORM_HERE*/
#$ cp libsoil2.a ~/opengl/lib/
#$ cd ../../src/SOIL2
#$ cp SOIL2.h ~/opengl/include/
#$ cd ../../..
#
#https://github.com/LimJing7/cs196-4dgame/blob/master/OPENGL_INSTALL_INSTRUCTIONS
#https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html

installOpengl :
	@brew install glew
	@brew install glfw3
	@brew install glm
	@clear
	@echo "remember to install soil.a or just inclue the static library"
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#  OpenGL Install   #"
	@echo "#    succesfully    #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

clean:
	@rm -rf $(NAME)
	@clear
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#       clean       #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

fclean: clean
	@clear
	@echo "\n# # # # # # # # # # # rmember to remove library files.. see comented out bit about installing soil"
	@echo "#                   #"
	@echo "#      fclean       #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

re: fclean all
	@clear
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#        re         #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"