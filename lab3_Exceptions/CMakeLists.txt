cmake_minimum_required(VERSION 3.0.0)
project(lab3_exceptions)

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

    lab3_exceptions

    ./src/main.cpp
)
