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
CMAKE_SOURCE_DIR = C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.cpp
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.obj -MF CMakeFiles\main.dir\main.cpp.obj.d -o CMakeFiles\main.dir\main.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\main.cpp > CMakeFiles\main.dir\main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\main.cpp -o CMakeFiles\main.dir\main.cpp.s

CMakeFiles/main.dir/src/Window.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Window.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/Window.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/Window.cpp
CMakeFiles/main.dir/src/Window.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/Window.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Window.cpp.obj -MF CMakeFiles\main.dir\src\Window.cpp.obj.d -o CMakeFiles\main.dir\src\Window.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Window.cpp

CMakeFiles/main.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Window.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Window.cpp > CMakeFiles\main.dir\src\Window.cpp.i

CMakeFiles/main.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Window.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Window.cpp -o CMakeFiles\main.dir\src\Window.cpp.s

CMakeFiles/main.dir/src/Element.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Element.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/Element.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/Element.cpp
CMakeFiles/main.dir/src/Element.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/Element.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Element.cpp.obj -MF CMakeFiles\main.dir\src\Element.cpp.obj.d -o CMakeFiles\main.dir\src\Element.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Element.cpp

CMakeFiles/main.dir/src/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Element.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Element.cpp > CMakeFiles\main.dir\src\Element.cpp.i

CMakeFiles/main.dir/src/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Element.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Element.cpp -o CMakeFiles\main.dir\src\Element.cpp.s

CMakeFiles/main.dir/src/GameGraphic.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameGraphic.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/GameGraphic.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/GameGraphic.cpp
CMakeFiles/main.dir/src/GameGraphic.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/GameGraphic.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameGraphic.cpp.obj -MF CMakeFiles\main.dir\src\GameGraphic.cpp.obj.d -o CMakeFiles\main.dir\src\GameGraphic.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameGraphic.cpp

CMakeFiles/main.dir/src/GameGraphic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameGraphic.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameGraphic.cpp > CMakeFiles\main.dir\src\GameGraphic.cpp.i

CMakeFiles/main.dir/src/GameGraphic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameGraphic.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameGraphic.cpp -o CMakeFiles\main.dir\src\GameGraphic.cpp.s

CMakeFiles/main.dir/src/Tile.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Tile.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/Tile.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/Tile.cpp
CMakeFiles/main.dir/src/Tile.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/Tile.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Tile.cpp.obj -MF CMakeFiles\main.dir\src\Tile.cpp.obj.d -o CMakeFiles\main.dir\src\Tile.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Tile.cpp

CMakeFiles/main.dir/src/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Tile.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Tile.cpp > CMakeFiles\main.dir\src\Tile.cpp.i

CMakeFiles/main.dir/src/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Tile.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\Tile.cpp -o CMakeFiles\main.dir\src\Tile.cpp.s

CMakeFiles/main.dir/src/GameBoard.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameBoard.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/GameBoard.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/GameBoard.cpp
CMakeFiles/main.dir/src/GameBoard.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/GameBoard.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameBoard.cpp.obj -MF CMakeFiles\main.dir\src\GameBoard.cpp.obj.d -o CMakeFiles\main.dir\src\GameBoard.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameBoard.cpp

CMakeFiles/main.dir/src/GameBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameBoard.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameBoard.cpp > CMakeFiles\main.dir\src\GameBoard.cpp.i

CMakeFiles/main.dir/src/GameBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameBoard.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameBoard.cpp -o CMakeFiles\main.dir\src\GameBoard.cpp.s

CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/IntroScreenGraphic.cpp
CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj -MF CMakeFiles\main.dir\src\IntroScreenGraphic.cpp.obj.d -o CMakeFiles\main.dir\src\IntroScreenGraphic.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\IntroScreenGraphic.cpp

CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\IntroScreenGraphic.cpp > CMakeFiles\main.dir\src\IntroScreenGraphic.cpp.i

CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\IntroScreenGraphic.cpp -o CMakeFiles\main.dir\src\IntroScreenGraphic.cpp.s

CMakeFiles/main.dir/src/GameOptions.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameOptions.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/GameOptions.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/GameOptions.cpp
CMakeFiles/main.dir/src/GameOptions.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/GameOptions.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameOptions.cpp.obj -MF CMakeFiles\main.dir\src\GameOptions.cpp.obj.d -o CMakeFiles\main.dir\src\GameOptions.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameOptions.cpp

CMakeFiles/main.dir/src/GameOptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameOptions.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameOptions.cpp > CMakeFiles\main.dir\src\GameOptions.cpp.i

CMakeFiles/main.dir/src/GameOptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameOptions.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\GameOptions.cpp -o CMakeFiles\main.dir\src\GameOptions.cpp.s

CMakeFiles/main.dir/src/InputBox.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/InputBox.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/InputBox.cpp.obj: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/src/InputBox.cpp
CMakeFiles/main.dir/src/InputBox.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/src/InputBox.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/InputBox.cpp.obj -MF CMakeFiles\main.dir\src\InputBox.cpp.obj.d -o CMakeFiles\main.dir\src\InputBox.cpp.obj -c C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\InputBox.cpp

CMakeFiles/main.dir/src/InputBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/InputBox.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\InputBox.cpp > CMakeFiles\main.dir\src\InputBox.cpp.i

CMakeFiles/main.dir/src/InputBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/InputBox.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\src\InputBox.cpp -o CMakeFiles\main.dir\src\InputBox.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj" \
"CMakeFiles/main.dir/src/Window.cpp.obj" \
"CMakeFiles/main.dir/src/Element.cpp.obj" \
"CMakeFiles/main.dir/src/GameGraphic.cpp.obj" \
"CMakeFiles/main.dir/src/Tile.cpp.obj" \
"CMakeFiles/main.dir/src/GameBoard.cpp.obj" \
"CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj" \
"CMakeFiles/main.dir/src/GameOptions.cpp.obj" \
"CMakeFiles/main.dir/src/InputBox.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/main.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/Window.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/Element.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/GameGraphic.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/Tile.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/GameBoard.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/IntroScreenGraphic.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/GameOptions.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/src/InputBox.cpp.obj
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/build.make
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: _deps/sfml-build/lib/libsfml-graphics-s-d.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: _deps/sfml-build/lib/libsfml-window-s-d.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: _deps/sfml-build/lib/libsfml-system-s-d.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: _deps/sfml-src/extlibs/libs-mingw/x64/libfreetype.a
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/linkLibs.rsp
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/objects1.rsp
C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\main.exe"
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copy OpenAL DLL"
	"C:\Program Files\CMake\bin\cmake.exe" -E copy C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/build/_deps/sfml-src/extlibs/bin/x64/openal32.dll C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: C:/Users/lucas/Desktop/B2Project2024/CPPSDL/SFML/main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build C:\Users\lucas\Desktop\B2Project2024\CPPSDL\SFML\build\CMakeFiles\main.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend
