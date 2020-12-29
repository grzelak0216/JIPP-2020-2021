cmake_minimum_required(VERSION 3.0.0)
project(lab5)

# Pliki naglowkowe
include_directories (

    ./include
)

# Kompilacja w systemie Windows
# (tryb konsoli zamiast trybu okienkowego)
set (

    CMAKE_EXE_LINKER_FLAGS
    "-Wl,--subsystem,console"
)


# Pliki zrodlowe
add_executable (

    lab5
    ./src/main.cpp
)