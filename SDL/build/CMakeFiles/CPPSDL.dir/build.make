# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build

# Include any dependencies generated for this target.
include CMakeFiles/CPPSDL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPPSDL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPSDL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPSDL.dir/flags.make

CMakeFiles/CPPSDL.dir/main.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/main.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/main.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/main.cpp
CMakeFiles/CPPSDL.dir/main.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPSDL.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/main.cpp.obj -MF CMakeFiles\CPPSDL.dir\main.cpp.obj.d -o CMakeFiles\CPPSDL.dir\main.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\main.cpp

CMakeFiles/CPPSDL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\main.cpp > CMakeFiles\CPPSDL.dir\main.cpp.i

CMakeFiles/CPPSDL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\main.cpp -o CMakeFiles\CPPSDL.dir\main.cpp.s

CMakeFiles/CPPSDL.dir/src/Element.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/Element.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/Element.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/Element.cpp
CMakeFiles/CPPSDL.dir/src/Element.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPPSDL.dir/src/Element.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/Element.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\Element.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\Element.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Element.cpp

CMakeFiles/CPPSDL.dir/src/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/Element.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Element.cpp > CMakeFiles\CPPSDL.dir\src\Element.cpp.i

CMakeFiles/CPPSDL.dir/src/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/Element.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Element.cpp -o CMakeFiles\CPPSDL.dir\src\Element.cpp.s

CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/EventHandler.cpp
CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\EventHandler.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\EventHandler.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\EventHandler.cpp

CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\EventHandler.cpp > CMakeFiles\CPPSDL.dir\src\EventHandler.cpp.i

CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\EventHandler.cpp -o CMakeFiles\CPPSDL.dir\src\EventHandler.cpp.s

CMakeFiles/CPPSDL.dir/src/Game.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/Game.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/Game.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/Game.cpp
CMakeFiles/CPPSDL.dir/src/Game.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPPSDL.dir/src/Game.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/Game.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\Game.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\Game.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Game.cpp

CMakeFiles/CPPSDL.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/Game.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Game.cpp > CMakeFiles\CPPSDL.dir\src\Game.cpp.i

CMakeFiles/CPPSDL.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/Game.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Game.cpp -o CMakeFiles\CPPSDL.dir\src\Game.cpp.s

CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/GameBoard.cpp
CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\GameBoard.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\GameBoard.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameBoard.cpp

CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameBoard.cpp > CMakeFiles\CPPSDL.dir\src\GameBoard.cpp.i

CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameBoard.cpp -o CMakeFiles\CPPSDL.dir\src\GameBoard.cpp.s

CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/GameGraphic.cpp
CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\GameGraphic.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\GameGraphic.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameGraphic.cpp

CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameGraphic.cpp > CMakeFiles\CPPSDL.dir\src\GameGraphic.cpp.i

CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameGraphic.cpp -o CMakeFiles\CPPSDL.dir\src\GameGraphic.cpp.s

CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/GameOptions.cpp
CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\GameOptions.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\GameOptions.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameOptions.cpp

CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameOptions.cpp > CMakeFiles\CPPSDL.dir\src\GameOptions.cpp.i

CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\GameOptions.cpp -o CMakeFiles\CPPSDL.dir\src\GameOptions.cpp.s

CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/IntroScreenGraphic.cpp
CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\IntroScreenGraphic.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\IntroScreenGraphic.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\IntroScreenGraphic.cpp

CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\IntroScreenGraphic.cpp > CMakeFiles\CPPSDL.dir\src\IntroScreenGraphic.cpp.i

CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\IntroScreenGraphic.cpp -o CMakeFiles\CPPSDL.dir\src\IntroScreenGraphic.cpp.s

CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/Tile.cpp
CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\Tile.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\Tile.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Tile.cpp

CMakeFiles/CPPSDL.dir/src/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/Tile.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Tile.cpp > CMakeFiles\CPPSDL.dir\src\Tile.cpp.i

CMakeFiles/CPPSDL.dir/src/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/Tile.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Tile.cpp -o CMakeFiles\CPPSDL.dir\src\Tile.cpp.s

CMakeFiles/CPPSDL.dir/src/Window.cpp.obj: CMakeFiles/CPPSDL.dir/flags.make
CMakeFiles/CPPSDL.dir/src/Window.cpp.obj: CMakeFiles/CPPSDL.dir/includes_CXX.rsp
CMakeFiles/CPPSDL.dir/src/Window.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/Window.cpp
CMakeFiles/CPPSDL.dir/src/Window.cpp.obj: CMakeFiles/CPPSDL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CPPSDL.dir/src/Window.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPSDL.dir/src/Window.cpp.obj -MF CMakeFiles\CPPSDL.dir\src\Window.cpp.obj.d -o CMakeFiles\CPPSDL.dir\src\Window.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Window.cpp

CMakeFiles/CPPSDL.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPSDL.dir/src/Window.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Window.cpp > CMakeFiles\CPPSDL.dir\src\Window.cpp.i

CMakeFiles/CPPSDL.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPSDL.dir/src/Window.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\src\Window.cpp -o CMakeFiles\CPPSDL.dir\src\Window.cpp.s

# Object files for target CPPSDL
CPPSDL_OBJECTS = \
"CMakeFiles/CPPSDL.dir/main.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/Element.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/Game.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj" \
"CMakeFiles/CPPSDL.dir/src/Window.cpp.obj"

# External object files for target CPPSDL
CPPSDL_EXTERNAL_OBJECTS =

C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/main.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/Element.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/EventHandler.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/Game.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/GameBoard.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/GameGraphic.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/GameOptions.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/IntroScreenGraphic.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/Tile.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/src/Window.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/build.make
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/lib/libSDL2.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/lib/libSDL2_image.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/src/lib/libSDL2_ttf.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/linkLibs.rsp
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/objects1.rsp
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe: CMakeFiles/CPPSDL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\CPPSDL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CPPSDL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPSDL.dir/build: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SDL/CPPSDL.exe
.PHONY : CMakeFiles/CPPSDL.dir/build

CMakeFiles/CPPSDL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CPPSDL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CPPSDL.dir/clean

CMakeFiles/CPPSDL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SDL\build\CMakeFiles\CPPSDL.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CPPSDL.dir/depend

