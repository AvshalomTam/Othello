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
include CMakeFiles/Server_Re6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server_Re6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server_Re6.dir/flags.make

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o: ../src/server/main_s.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o -c /home/steve/Desktop/Othello/src/server/main_s.cpp

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/main_s.cpp > CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.i

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/main_s.cpp -o CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.s

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o: ../src/server/src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o -c /home/steve/Desktop/Othello/src/server/src/Server.cpp

CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/Server.cpp > CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/Server.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o: ../src/server/src/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o -c /home/steve/Desktop/Othello/src/server/src/Command.cpp

CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/Command.cpp > CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/Command.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o: ../src/server/src/CommandsManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o -c /home/steve/Desktop/Othello/src/server/src/CommandsManager.cpp

CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/CommandsManager.cpp > CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/CommandsManager.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o: ../src/server/src/StartCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o -c /home/steve/Desktop/Othello/src/server/src/StartCommand.cpp

CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/StartCommand.cpp > CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/StartCommand.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o: ../src/server/src/ListCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o -c /home/steve/Desktop/Othello/src/server/src/ListCommand.cpp

CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/ListCommand.cpp > CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/ListCommand.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o: ../src/server/src/JoinCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o -c /home/steve/Desktop/Othello/src/server/src/JoinCommand.cpp

CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/JoinCommand.cpp > CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/JoinCommand.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o: ../src/server/src/ClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o -c /home/steve/Desktop/Othello/src/server/src/ClientHandler.cpp

CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/ClientHandler.cpp > CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/ClientHandler.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o: ../src/server/src/GameRoom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o -c /home/steve/Desktop/Othello/src/server/src/GameRoom.cpp

CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/GameRoom.cpp > CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/GameRoom.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o: ../src/server/src/GameManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o -c /home/steve/Desktop/Othello/src/server/src/GameManager.cpp

CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/GameManager.cpp > CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/GameManager.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o


CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o: CMakeFiles/Server_Re6.dir/flags.make
CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o: ../src/server/src/ThreadManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o -c /home/steve/Desktop/Othello/src/server/src/ThreadManager.cpp

CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/steve/Desktop/Othello/src/server/src/ThreadManager.cpp > CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.i

CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/steve/Desktop/Othello/src/server/src/ThreadManager.cpp -o CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.s

CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.requires:

.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.requires

CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.provides: CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server_Re6.dir/build.make CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.provides.build
.PHONY : CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.provides

CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.provides.build: CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o


# Object files for target Server_Re6
Server_Re6_OBJECTS = \
"CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o" \
"CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o"

# External object files for target Server_Re6
Server_Re6_EXTERNAL_OBJECTS =

Server_Re6: CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o
Server_Re6: CMakeFiles/Server_Re6.dir/build.make
Server_Re6: CMakeFiles/Server_Re6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Server_Re6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server_Re6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server_Re6.dir/build: Server_Re6

.PHONY : CMakeFiles/Server_Re6.dir/build

CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/main_s.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/Server.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/Command.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/CommandsManager.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/StartCommand.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/ListCommand.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/JoinCommand.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/ClientHandler.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/GameRoom.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/GameManager.cpp.o.requires
CMakeFiles/Server_Re6.dir/requires: CMakeFiles/Server_Re6.dir/src/server/src/ThreadManager.cpp.o.requires

.PHONY : CMakeFiles/Server_Re6.dir/requires

CMakeFiles/Server_Re6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server_Re6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server_Re6.dir/clean

CMakeFiles/Server_Re6.dir/depend:
	cd /home/steve/Desktop/Othello/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steve/Desktop/Othello /home/steve/Desktop/Othello /home/steve/Desktop/Othello/cmake-build-debug /home/steve/Desktop/Othello/cmake-build-debug /home/steve/Desktop/Othello/cmake-build-debug/CMakeFiles/Server_Re6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server_Re6.dir/depend

