# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\grzel\projects\helloworld\jipp\lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\grzel\projects\helloworld\jipp\lab4\build

# Include any dependencies generated for this target.
include CMakeFiles/lab4.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.cpp.dir/flags.make

CMakeFiles/lab4.cpp.dir/main.cpp.obj: CMakeFiles/lab4.cpp.dir/flags.make
CMakeFiles/lab4.cpp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\grzel\projects\helloworld\jipp\lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4.cpp.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab4.cpp.dir\main.cpp.obj -c C:\Users\grzel\projects\helloworld\jipp\lab4\main.cpp

CMakeFiles/lab4.cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.cpp.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\grzel\projects\helloworld\jipp\lab4\main.cpp > CMakeFiles\lab4.cpp.dir\main.cpp.i

CMakeFiles/lab4.cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.cpp.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\grzel\projects\helloworld\jipp\lab4\main.cpp -o CMakeFiles\lab4.cpp.dir\main.cpp.s

# Object files for target lab4.cpp
lab4_cpp_OBJECTS = \
"CMakeFiles/lab4.cpp.dir/main.cpp.obj"

# External object files for target lab4.cpp
lab4_cpp_EXTERNAL_OBJECTS =

lab4.cpp.exe: CMakeFiles/lab4.cpp.dir/main.cpp.obj
lab4.cpp.exe: CMakeFiles/lab4.cpp.dir/build.make
lab4.cpp.exe: CMakeFiles/lab4.cpp.dir/linklibs.rsp
lab4.cpp.exe: CMakeFiles/lab4.cpp.dir/objects1.rsp
lab4.cpp.exe: CMakeFiles/lab4.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\grzel\projects\helloworld\jipp\lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab4.cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab4.cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.cpp.dir/build: lab4.cpp.exe

.PHONY : CMakeFiles/lab4.cpp.dir/build

CMakeFiles/lab4.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab4.cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab4.cpp.dir/clean

CMakeFiles/lab4.cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\grzel\projects\helloworld\jipp\lab4 C:\Users\grzel\projects\helloworld\jipp\lab4 C:\Users\grzel\projects\helloworld\jipp\lab4\build C:\Users\grzel\projects\helloworld\jipp\lab4\build C:\Users\grzel\projects\helloworld\jipp\lab4\build\CMakeFiles\lab4.cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4.cpp.dir/depend

