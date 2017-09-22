FILE = src/bomber.cpp src/man.cpp src/bomb.cpp src/game.cpp src/main.cpp \
 src/object.cpp src/overflow.cpp src/map.cpp src/enemy.cpp src/handle.cpp \
 src/level.cpp src/load.cpp src/lib.cpp
 
NAME = bomberman

CC = g++

CFLAGS = -Wall -Werror -Wextra

CFLAGS1 =	-std=c++11 -Wno-deprecated-declarations -O3

CFLAGS2 = 	-framework OpenGL -framework GLUT -O3 -ltermcap \
			-Wno-deprecated-declarations

LIBRARY = -framework OpenGL -framework AppKit

all:
	@echo "Compiling code!"
	@$(CC) $(CFLAGS) $(CFLAGS1) $(CFLAGS2) -o $(NAME) $(FILE) $(LIBRARY)
	@echo "Bang! Bang!! Time to blow things up!"

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all