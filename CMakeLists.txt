cmake_minimum_required(VERSION 3.8)

project(bomberman)

IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "")

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

link_directories(${CMAKE_SOURCE_DIR}/lib)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated-declarations -O3")

find_package(OpenGL REQUIRED)
find_package(OpenAL REQUIRED)
find_package(PkgConfig REQUIRED)

# Run install script
set(BASH_CMD "bash")
set(BASH_ARG "../INSTALL.sh")
execute_process(COMMAND ${BASH_CMD} ${BASH_ARG})

set(NANOGUI_DIR "external/nanogui")
set(SOIL_DIR "external/SOIL2")

# Adding dependencies
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(GLM REQUIRED glm)
pkg_search_module(FREETYPE REQUIRED freetype2)
pkg_search_module(SDL REQUIRED sdl)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(LIBPNG REQUIRED libpng)

if(APPLE)
	INCLUDE_DIRECTORIES(/System/Library/Frameworks)
	FIND_LIBRARY(COCOA_LIBRARY Cocoa)
	FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
	FIND_LIBRARY(IOKit_LIBRARY IOKit)
	FIND_LIBRARY(CoreVideo_LIBRARY CoreVideo)
	MARK_AS_ADVANCED(COCOA_LIBRARY OpenGL_LIBRARY)
	SET(APPLE_LIBS ${COCOA_LIBRARY} ${IOKit_LIBRARY} ${OpenGL_LIBRARY} ${CoreVideo_LIBRARY})
	SET(APPLE_LIBS ${APPLE_LIBS} ${GLFW3_LIBRARY})
	set(LIBS ${LIBS} ${APPLE_LIBS})
endif(APPLE)

add_subdirectory(${NANOGUI_DIR})
include_directories(${NANOGUI_DIR}/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

#add_subdirectory(${SOIL_DIR})
include_directories(${SOIL_DIR}/src/SOIL2)

# These directories get symlinked into the build directory after compilation
set(RESOURCE_DIRS
		res/graphics/images/container2_specular.png
		res/graphics/images/container2.png
		res/graphics/images/image1.jpg
		res/graphics/images/image2.png
		res/graphics/images/image3.png
		res/graphics/images/stoneWall.png
		res/graphics/shaders/lamp.frag
		res/graphics/shaders/lamp.vs
		res/graphics/shaders/lighting.frag
		res/graphics/shaders/lighting.vs
		)

set(SOURCE_FILES
		src/camera.cpp
		src/shader.cpp
		src/bomber.cpp
		src/man.cpp
		src/bomb.cpp
		src/game.cpp
		src/main.cpp
		src/base.cpp
		src/overflow.cpp
		src/map.cpp
		src/enemy.cpp
		src/handle.cpp
		src/level.cpp
		src/load.cpp
		src/lib.cpp

		includes/bomb.hpp
		includes/camera.hpp
		includes/game.hpp
		includes/header.hpp
		includes/lib.hpp
		includes/man.hpp
		includes/base.hpp
		includes/bomber.hpp
		includes/enemy.hpp
		includes/handle.hpp
		includes/level.hpp
		includes/load.hpp
		includes/map.hpp
		includes/shader.hpp
		)

# Directories to find the header files
include_directories(
		includes
		~/.brew/include
		~/.brew/include/freetype2
		~/.brew/include/eigen3
		${OPENAL_INCLUDE_DIR}
)

# Directories to find the libraries
link_directories(
		~/.brew/lib
		~/.brew/opt/alut/lib
		${PROJECT_SOURCE_DIR}
		${GLEW_LIBRARY_DIRS}
		${GLM_LIBRARY_DIRS}
		${PROJECT_SOURCE_DIR}/external/SOIL2/lib/macosx/
		#${GLFW_LIBRARY_DIRS}
)

add_executable(bomberman ${SOURCE_FILES})

# Link executable with libraries
target_link_libraries(${PROJECT_NAME}
		${LIBS}
		${OPENGL_LIBRARIES}
		${OPENAL_LIBRARY}
		${GLEW_LIBRARIES}
		${GLM_LIBRARIES}
		#${GLFW_LIBRARIES}
		freetype
		png
		sdl
		#glfw
		GLEW
		soil2
		nanogui
		${NANOGUI_EXTRA_LIBS}
		)

set(LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo -framework Carbon")

if (APPLE)
	target_link_libraries(${PROJECT_NAME}
			${LINKER_FLAGS})
endif()