# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/steve/Downloads/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/steve/Downloads/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/steve/Desktop/Othello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/steve/Desktop/Othello/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Othello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Othello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Othello.dir/flags.make

CMakeFiles/Othello.dir/src/AIplayer.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/AIplayer.cpp.o: ../src/AIplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Othello.dir/src/AIplayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/AIplayer.cpp.o -c /home/steve/Desktop/Othello/src/AIplayer.cpp

CMakeFiles/Othello.dir/src/AIplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/AIplayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/AIplayer.cpp > CMakeFiles/Othello.dir/src/AIplayer.cpp.i

CMakeFiles/Othello.dir/src/AIplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/AIplayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/AIplayer.cpp -o CMakeFiles/Othello.dir/src/AIplayer.cpp.s

CMakeFiles/Othello.dir/src/AIplayer.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/AIplayer.cpp.o.requires

CMakeFiles/Othello.dir/src/AIplayer.cpp.o.provides: CMakeFiles/Othello.dir/src/AIplayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/AIplayer.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/AIplayer.cpp.o.provides

CMakeFiles/Othello.dir/src/AIplayer.cpp.o.provides.build: CMakeFiles/Othello.dir/src/AIplayer.cpp.o


CMakeFiles/Othello.dir/src/BasicRules.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/BasicRules.cpp.o: ../src/BasicRules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Othello.dir/src/BasicRules.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/BasicRules.cpp.o -c /home/steve/Desktop/Othello/src/BasicRules.cpp

CMakeFiles/Othello.dir/src/BasicRules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/BasicRules.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/BasicRules.cpp > CMakeFiles/Othello.dir/src/BasicRules.cpp.i

CMakeFiles/Othello.dir/src/BasicRules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/BasicRules.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/BasicRules.cpp -o CMakeFiles/Othello.dir/src/BasicRules.cpp.s

CMakeFiles/Othello.dir/src/BasicRules.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/BasicRules.cpp.o.requires

CMakeFiles/Othello.dir/src/BasicRules.cpp.o.provides: CMakeFiles/Othello.dir/src/BasicRules.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/BasicRules.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/BasicRules.cpp.o.provides

CMakeFiles/Othello.dir/src/BasicRules.cpp.o.provides.build: CMakeFiles/Othello.dir/src/BasicRules.cpp.o


CMakeFiles/Othello.dir/src/Board.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Othello.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/Board.cpp.o -c /home/steve/Desktop/Othello/src/Board.cpp

CMakeFiles/Othello.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/Board.cpp > CMakeFiles/Othello.dir/src/Board.cpp.i

CMakeFiles/Othello.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/Board.cpp -o CMakeFiles/Othello.dir/src/Board.cpp.s

CMakeFiles/Othello.dir/src/Board.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/Board.cpp.o.requires

CMakeFiles/Othello.dir/src/Board.cpp.o.provides: CMakeFiles/Othello.dir/src/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/Board.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/Board.cpp.o.provides

CMakeFiles/Othello.dir/src/Board.cpp.o.provides.build: CMakeFiles/Othello.dir/src/Board.cpp.o


CMakeFiles/Othello.dir/src/CharBoard.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/CharBoard.cpp.o: ../src/CharBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Othello.dir/src/CharBoard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/CharBoard.cpp.o -c /home/steve/Desktop/Othello/src/CharBoard.cpp

CMakeFiles/Othello.dir/src/CharBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/CharBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/CharBoard.cpp > CMakeFiles/Othello.dir/src/CharBoard.cpp.i

CMakeFiles/Othello.dir/src/CharBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/CharBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/CharBoard.cpp -o CMakeFiles/Othello.dir/src/CharBoard.cpp.s

CMakeFiles/Othello.dir/src/CharBoard.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/CharBoard.cpp.o.requires

CMakeFiles/Othello.dir/src/CharBoard.cpp.o.provides: CMakeFiles/Othello.dir/src/CharBoard.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/CharBoard.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/CharBoard.cpp.o.provides

CMakeFiles/Othello.dir/src/CharBoard.cpp.o.provides.build: CMakeFiles/Othello.dir/src/CharBoard.cpp.o


CMakeFiles/Othello.dir/src/Coordinates.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/Coordinates.cpp.o: ../src/Coordinates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Othello.dir/src/Coordinates.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/Coordinates.cpp.o -c /home/steve/Desktop/Othello/src/Coordinates.cpp

CMakeFiles/Othello.dir/src/Coordinates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/Coordinates.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/Coordinates.cpp > CMakeFiles/Othello.dir/src/Coordinates.cpp.i

CMakeFiles/Othello.dir/src/Coordinates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/Coordinates.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/Coordinates.cpp -o CMakeFiles/Othello.dir/src/Coordinates.cpp.s

CMakeFiles/Othello.dir/src/Coordinates.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/Coordinates.cpp.o.requires

CMakeFiles/Othello.dir/src/Coordinates.cpp.o.provides: CMakeFiles/Othello.dir/src/Coordinates.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/Coordinates.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/Coordinates.cpp.o.provides

CMakeFiles/Othello.dir/src/Coordinates.cpp.o.provides.build: CMakeFiles/Othello.dir/src/Coordinates.cpp.o


CMakeFiles/Othello.dir/src/Game.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Othello.dir/src/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/Game.cpp.o -c /home/steve/Desktop/Othello/src/Game.cpp

CMakeFiles/Othello.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/Game.cpp > CMakeFiles/Othello.dir/src/Game.cpp.i

CMakeFiles/Othello.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/Game.cpp -o CMakeFiles/Othello.dir/src/Game.cpp.s

CMakeFiles/Othello.dir/src/Game.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/Game.cpp.o.requires

CMakeFiles/Othello.dir/src/Game.cpp.o.provides: CMakeFiles/Othello.dir/src/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/Game.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/Game.cpp.o.provides

CMakeFiles/Othello.dir/src/Game.cpp.o.provides.build: CMakeFiles/Othello.dir/src/Game.cpp.o


CMakeFiles/Othello.dir/src/GameLogic.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/GameLogic.cpp.o: ../src/GameLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Othello.dir/src/GameLogic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/GameLogic.cpp.o -c /home/steve/Desktop/Othello/src/GameLogic.cpp

CMakeFiles/Othello.dir/src/GameLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/GameLogic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/GameLogic.cpp > CMakeFiles/Othello.dir/src/GameLogic.cpp.i

CMakeFiles/Othello.dir/src/GameLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/GameLogic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/GameLogic.cpp -o CMakeFiles/Othello.dir/src/GameLogic.cpp.s

CMakeFiles/Othello.dir/src/GameLogic.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/GameLogic.cpp.o.requires

CMakeFiles/Othello.dir/src/GameLogic.cpp.o.provides: CMakeFiles/Othello.dir/src/GameLogic.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/GameLogic.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/GameLogic.cpp.o.provides

CMakeFiles/Othello.dir/src/GameLogic.cpp.o.provides.build: CMakeFiles/Othello.dir/src/GameLogic.cpp.o


CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o: ../src/HumanPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o -c /home/steve/Desktop/Othello/src/HumanPlayer.cpp

CMakeFiles/Othello.dir/src/HumanPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/HumanPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/HumanPlayer.cpp > CMakeFiles/Othello.dir/src/HumanPlayer.cpp.i

CMakeFiles/Othello.dir/src/HumanPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/HumanPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/HumanPlayer.cpp -o CMakeFiles/Othello.dir/src/HumanPlayer.cpp.s

CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.requires

CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.provides: CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.provides

CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.provides.build: CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o


CMakeFiles/Othello.dir/src/main.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Othello.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/main.cpp.o -c /home/steve/Desktop/Othello/src/main.cpp

CMakeFiles/Othello.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/main.cpp > CMakeFiles/Othello.dir/src/main.cpp.i

CMakeFiles/Othello.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/main.cpp -o CMakeFiles/Othello.dir/src/main.cpp.s

CMakeFiles/Othello.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/main.cpp.o.requires

CMakeFiles/Othello.dir/src/main.cpp.o.provides: CMakeFiles/Othello.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/main.cpp.o.provides

CMakeFiles/Othello.dir/src/main.cpp.o.provides.build: CMakeFiles/Othello.dir/src/main.cpp.o


CMakeFiles/Othello.dir/src/Player.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Othello.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/src/Player.cpp.o -c /home/steve/Desktop/Othello/src/Player.cpp

CMakeFiles/Othello.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/Player.cpp > CMakeFiles/Othello.dir/src/Player.cpp.i

CMakeFiles/Othello.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/Player.cpp -o CMakeFiles/Othello.dir/src/Player.cpp.s

CMakeFiles/Othello.dir/src/Player.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/src/Player.cpp.o.requires

CMakeFiles/Othello.dir/src/Player.cpp.o.provides: CMakeFiles/Othello.dir/src/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/src/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/src/Player.cpp.o.provides

CMakeFiles/Othello.dir/src/Player.cpp.o.provides.build: CMakeFiles/Othello.dir/src/Player.cpp.o


# Object files for target Othello
Othello_OBJECTS = \
"CMakeFiles/Othello.dir/src/AIplayer.cpp.o" \
"CMakeFiles/Othello.dir/src/BasicRules.cpp.o" \
"CMakeFiles/Othello.dir/src/Board.cpp.o" \
"CMakeFiles/Othello.dir/src/CharBoard.cpp.o" \
"CMakeFiles/Othello.dir/src/Coordinates.cpp.o" \
"CMakeFiles/Othello.dir/src/Game.cpp.o" \
"CMakeFiles/Othello.dir/src/GameLogic.cpp.o" \
"CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o" \
"CMakeFiles/Othello.dir/src/main.cpp.o" \
"CMakeFiles/Othello.dir/src/Player.cpp.o"

# External object files for target Othello
Othello_EXTERNAL_OBJECTS =

Othello: CMakeFiles/Othello.dir/src/AIplayer.cpp.o
Othello: CMakeFiles/Othello.dir/src/BasicRules.cpp.o
Othello: CMakeFiles/Othello.dir/src/Board.cpp.o
Othello: CMakeFiles/Othello.dir/src/CharBoard.cpp.o
Othello: CMakeFiles/Othello.dir/src/Coordinates.cpp.o
Othello: CMakeFiles/Othello.dir/src/Game.cpp.o
Othello: CMakeFiles/Othello.dir/src/GameLogic.cpp.o
Othello: CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o
Othello: CMakeFiles/Othello.dir/src/main.cpp.o
Othello: CMakeFiles/Othello.dir/src/Player.cpp.o
Othello: CMakeFiles/Othello.dir/build.make
Othello: CMakeFiles/Othello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Othello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Othello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Othello.dir/build: Othello

.PHONY : CMakeFiles/Othello.dir/build

CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/AIplayer.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/BasicRules.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/Board.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/CharBoard.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/Coordinates.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/Game.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/GameLogic.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/HumanPlayer.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/main.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/src/Player.cpp.o.requires

.PHONY : CMakeFiles/Othello.dir/requires

CMakeFiles/Othello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Othello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Othello.dir/clean

CMakeFiles/Othello.dir/depend:
	cd /home/steve/Desktop/Othello/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steve/Desktop/Othello /home/steve/Desktop/Othello /home/steve/Desktop/Othello/cmake-build-debug /home/steve/Desktop/Othello/cmake-build-debug /home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles/Othello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Othello.dir/depend
