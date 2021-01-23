cmake_minimum_required(VERSION 3.0.0)
project(snake)

find_package(OpenGL REQUIRED)

# Pliki naglowkowe
include_directories (

    ./include
    ./include/GL
    ${OPENGL_INCLUDE_DIRS}
)

# Kompilacja w systemie Windows
# (tryb konsoli zamiast trybu okienkowego)
set (

    CMAKE_CXX_STANDARD_LIBRARIES
    "-static-libgcc -static-libstdc++"
)

set (    CMAKE_EXE_LINKER_FLAGS
    "-Wl,--subsystem,console"
)

# Pliki zrodlowe
add_executable (

    snake
    WIN32

    ./src/main.cpp
    ./src/snake_draw.cpp
    ./src/snake_build.cpp
    ./src/snake_move.cpp
    ./src/snake_funk.cpp
    ./src/snake_score
)


set_target_properties(

    snake PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY ../bin

    COMPILE_FLAGS "-m64"
    LINK_FLAGS "-m64"
)

# Biblioteki dynamiczne
target_link_libraries (

    snake

    ${CMAKE_CURRENT_SOURCE_DIR}/libs/x64/libfreeglut.a
    ${OPENGL_LIBRARIES}
)
