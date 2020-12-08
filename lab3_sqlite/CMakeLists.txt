cmake_minimum_required(VERSION 3.0.0)
project(lab3_sqlite)

# Pliki naglowkowe
include_directories (

    ./include
    ./libs/sqlite3/include
)

# Kompilacja w systemie Windows
# (tryb konsoli zamiast trybu okienkowego)
set (

    CMAKE_EXE_LINKER_FLAGS
    "-Wl,--subsystem,console"
)


# Pliki zrodlowe
add_executable (

    lab3_sqlite
    WIN32

    ./src/main.cpp
)

# Biblioteki dynamiczne (".lib" -> ".dll")
target_link_libraries (

    lab3_sqlite

    ${CMAKE_CURRENT_SOURCE_DIR}/libs/sqlite3/sqlite3.lib
)