cmake_minimum_required(VERSION 2.8)

project(bomberman)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wno-deprecated-declarations -O3")

find_package(OpenGL REQUIRED)
find_package(OpenAL REQUIRED)
find_package(PkgConfig REQUIRED)

# Run install script
set(BASH_CMD "bash")
set(BASH_ARG "../INSTALL.sh")
set(GIT_CMD "git submodule")
set(GIT_ARG "update")
set(GIT_FLAG "--init --recursive")
execute_process(COMMAND ${BASH_CMD} ${BASH_ARG})
execute_process(COMMAND	${GIT_CMD} ${GIT_ARG} ${GIT_FLAG})

set(NANOGUI_DIR "external/nanogui")
set(SOIL_DIR "external/soil")

# Adding dependencies
pkg_search_module(GLEW REQUIRED glew)
#pkg_search_module(GLFW3 REQUIRED glfw3)
pkg_search_module(GLM REQUIRED glm)
pkg_search_module(FREETYPE REQUIRED freetype2)
pkg_search_module(SDL REQUIRED sdl)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(LIBPNG REQUIRED libpng)

add_subdirectory(${NANOGUI_DIR})
include_directories(${NANOGUI_DIR}/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

add_subdirectory(${SOIL_DIR})
#include_directories(${SOIL_DIR}/src)
include_directories(${SOIL_EXTRA_INCS})
add_definitions(${SOIL_EXTRA_DEFS})


# These directories get symlinked into the build directory after compilation
set(RESOURCE_DIRS
)

set(SOURCE_FILES
    src/bomber.cpp
    src/man.cpp
    src/bomb.cpp
    src/game.cpp
    src/main.cpp
    src/object.cpp
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
    includes/object.hpp
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
        include
		~/.brew/include
		~/.brew/include/freetype2
		~/.brew/include/eigen3
		${OPENAL_INCLUDE_DIR}
		~/.brew/opt/alut/include
        ${SOIL_DIR}/src
)

# Directories to find the libraries
link_directories(
		~/.brew/lib
		~/.brew/opt/alut/lib
        ${PROJECT_SOURCE_DIR}
        ${GLEW_LIBRARY_DIRS}
        ${GLM_LIBRARY_DIRS}
        #${GLFW_LIBRARY_DIRS}
)

add_executable(bomberman ${SOURCE_FILES})

add_library(soil STATIC IMPORTED)
set_target_properties(soil PROPERTIES IMPORTED_LOCATION ../external/soil/build/libsoil2.a)
target_link_libraries(${PROJECT_NAME} soil)

# Link executable with libraries
target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        ${OPENAL_LIBRARY}
        ${GLEW_LIBRARIES}
        ${GLM_LIBRARIES}
        #${GLFW_LIBRARIES}
        ${FT_LIBRARIES}
        alut
		freetype
		png
        #glfw
		GLEW
        nanogui
        ${NANOGUI_EXTRA_LIBS}
)

set(LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo -framework Carbon")

if (APPLE)
    target_link_libraries(${PROJECT_NAME}
		${LINKER_FLAGS})
endif()