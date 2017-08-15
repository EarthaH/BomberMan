NAME = lib1.so

CFLAGS =	-std=c++11 -Wno-deprecated-declarations -O3

CFLAGS2 = 	-framework OpenGL -framework GLUT -O3 -ltermcap \
			-Wno-deprecated-declarations

CFLAGS3 = -shared -fPIC

SRCS = lib.cpp

CC = g++

LIBRARY = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(CFLAGS2) $(CFLAGS3) -o ../../$(NAME) $(SRCS) $(LIBRARY)
#	@g++ -shared -fPIC -o lib1.so lib.cpp -lncurses

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f ../../$(NAME)

re: fclean all

#texture:
#	@if [ ! -d textures ]; then \
#		git submodule add https://github.com/abintcli/textures.git textures; \
#	fi

.PHONY: clean fclean re

#for glut to work install `brew cask install xquartz` then `brew install freeeglut`

#`brew install homebrew/x11/freeglut`

