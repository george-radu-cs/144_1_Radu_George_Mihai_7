# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/george/Downloads/sem2/poo/projects/1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/george/Downloads/sem2/poo/projects/1

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/nod.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/nod.cpp.o: nod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/Downloads/sem2/poo/projects/1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/nod.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/nod.cpp.o -c /home/george/Downloads/sem2/poo/projects/1/nod.cpp

CMakeFiles/project1.dir/nod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/nod.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/Downloads/sem2/poo/projects/1/nod.cpp > CMakeFiles/project1.dir/nod.cpp.i

CMakeFiles/project1.dir/nod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/nod.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/Downloads/sem2/poo/projects/1/nod.cpp -o CMakeFiles/project1.dir/nod.cpp.s

CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o: lista_dublu_inltantuita.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/Downloads/sem2/poo/projects/1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o -c /home/george/Downloads/sem2/poo/projects/1/lista_dublu_inltantuita.cpp

CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/Downloads/sem2/poo/projects/1/lista_dublu_inltantuita.cpp > CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.i

CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/Downloads/sem2/poo/projects/1/lista_dublu_inltantuita.cpp -o CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.s

CMakeFiles/project1.dir/main.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/Downloads/sem2/poo/projects/1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/main.cpp.o -c /home/george/Downloads/sem2/poo/projects/1/main.cpp

CMakeFiles/project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/Downloads/sem2/poo/projects/1/main.cpp > CMakeFiles/project1.dir/main.cpp.i

CMakeFiles/project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/Downloads/sem2/poo/projects/1/main.cpp -o CMakeFiles/project1.dir/main.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/nod.cpp.o" \
"CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o" \
"CMakeFiles/project1.dir/main.cpp.o"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1: CMakeFiles/project1.dir/nod.cpp.o
project1: CMakeFiles/project1.dir/lista_dublu_inltantuita.cpp.o
project1: CMakeFiles/project1.dir/main.cpp.o
project1: CMakeFiles/project1.dir/build.make
project1: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/george/Downloads/sem2/poo/projects/1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1

.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	cd /home/george/Downloads/sem2/poo/projects/1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/george/Downloads/sem2/poo/projects/1 /home/george/Downloads/sem2/poo/projects/1 /home/george/Downloads/sem2/poo/projects/1 /home/george/Downloads/sem2/poo/projects/1 /home/george/Downloads/sem2/poo/projects/1/CMakeFiles/project1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

