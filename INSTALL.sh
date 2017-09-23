#!/bin/bash

HOMEBREW="$HOME/.brew"

LIB_CMAKE="$HOME/.brew/Cellar/cmake"
LIB_PCKCONF="$HOME/.brew/Cellar/pkg-config"
LIB_PNG="$HOME/.brew/Cellar/libpng"
LIB_FREETYPE="$HOME/.brew/Cellar/freetype"
LIB_SDL="$HOME/.brew/Cellar/sdl"
LIB_SDL2="$HOME/.brew/Cellar/sdl2"
# LIB_GLFW="$HOME/.brew/Cellar/glfw"
LIB_GLEW="$HOME/.brew/Cellar/glew"
LIB_GLM="$HOME/.brew/Cellar/glm"
LIB_SMFL="$HOME/.brew/Cellar/sfml"
LIB_EIGEN="$HOME/.brew/Cellar/eigen"
LIB_ALUT="$HOME/.brew/Cellar/alut"

LIB_NANOGUI="../external/nanogui"
LIB_SOIL="../SOIL2"

if [ ! -d "$HOMEBREW" ]; then
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
fi

if [ ! -d "$LIB_CMAKE" ]; then
	$HOME/.brew/bin/brew install cmake
fi

if [ ! -d "$LIB_PCKCONF" ]; then
	$HOME/.brew/bin/brew install pkg-config
fi

if [ ! -d "$LIB_PNG" ]; then
	$HOME/.brew/bin/brew install libpng
fi

if [ ! -d "$LIB_FREETYPE" ]; then
	$HOME/.brew/bin/brew install freetype
fi

if [ ! -d "$LIB_SDL" ]; then
	$HOME/.brew/bin/brew install sdl
fi

if [ ! -d "$LIB_SDL2" ]; then
	$HOME/.brew/bin/brew install sdl2
fi

# if [ ! -d "$LIB_GLFW" ]; then
# 	$HOME/.brew/bin/brew install glfw
# fi

if [ ! -d "$LIB_GLEW" ]; then
	$HOME/.brew/bin/brew install glew
fi

if [ ! -d "$LIB_GLM" ]; then
	$HOME/.brew/bin/brew install glm
fi


if [ ! -d "$LIB_SFML" ]; then
	$HOME/.brew/bin/brew install sfml
fi

if [ ! -d "$LIB_EIGEN" ]; then
	$HOME/.brew/bin/brew install eigen
fi

if [ ! -d "$LIB_ALUT" ]; then
	$HOME/.brew/bin/brew install alut
fi

if [ ! -d "$LIB_NANOGUI" ]; then
	git submodule add https://github.com/wjakob/nanogui.git ../external/nanogui
	git submodule update --init --recursive
fi

if [ ! -d "$LIB_SOIL" ]; then
	hg clone https://bitbucket.org/SpartanJ/soil2 ../SOIL2

	cd ../SOIL2
	premake4 gmake

fi
