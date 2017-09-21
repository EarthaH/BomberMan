FILE = src/bomber.cpp src/man.cpp src/bomb.cpp src/game.cpp src/main.cpp \
 src/object.cpp src/overflow.cpp src/map.cpp src/enemy.cpp src/handle.cpp \
 src/level.cpp src/load.cpp
NAME = bomberman
CC = g++
CFLAGS = -Wall -Werror -Wextra

all:
	@make -C Lib/lib1/ re
	@echo "Compiling code!"
	@$(CC) $(CFLAGS) -o $(NAME) $(FILE)
	@echo "Bang! Bang!! Time to blow things up!"

clean:
	@rm -rf $(NAME)
	@make -C Lib/lib1/ clean

fclean: clean
	@make -C Lib/lib1/ fclean

re: fclean all