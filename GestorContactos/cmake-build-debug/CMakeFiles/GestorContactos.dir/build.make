# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "H:\Archivos de programas\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "H:\Archivos de programas\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GestorContactos.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GestorContactos.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GestorContactos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GestorContactos.dir/flags.make

CMakeFiles/GestorContactos.dir/main.cpp.obj: CMakeFiles/GestorContactos.dir/flags.make
CMakeFiles/GestorContactos.dir/main.cpp.obj: C:/Users/branp/CLionProjects/solitario/LabEDD-Practica02/GestorContactos/main.cpp
CMakeFiles/GestorContactos.dir/main.cpp.obj: CMakeFiles/GestorContactos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GestorContactos.dir/main.cpp.obj"
	"H:\Archivos de programas\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GestorContactos.dir/main.cpp.obj -MF CMakeFiles\GestorContactos.dir\main.cpp.obj.d -o CMakeFiles\GestorContactos.dir\main.cpp.obj -c C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\main.cpp

CMakeFiles/GestorContactos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GestorContactos.dir/main.cpp.i"
	"H:\Archivos de programas\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\main.cpp > CMakeFiles\GestorContactos.dir\main.cpp.i

CMakeFiles/GestorContactos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GestorContactos.dir/main.cpp.s"
	"H:\Archivos de programas\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\main.cpp -o CMakeFiles\GestorContactos.dir\main.cpp.s

# Object files for target GestorContactos
GestorContactos_OBJECTS = \
"CMakeFiles/GestorContactos.dir/main.cpp.obj"

# External object files for target GestorContactos
GestorContactos_EXTERNAL_OBJECTS =

GestorContactos.exe: CMakeFiles/GestorContactos.dir/main.cpp.obj
GestorContactos.exe: CMakeFiles/GestorContactos.dir/build.make
GestorContactos.exe: CMakeFiles/GestorContactos.dir/linkLibs.rsp
GestorContactos.exe: CMakeFiles/GestorContactos.dir/objects1.rsp
GestorContactos.exe: CMakeFiles/GestorContactos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GestorContactos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GestorContactos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GestorContactos.dir/build: GestorContactos.exe
.PHONY : CMakeFiles/GestorContactos.dir/build

CMakeFiles/GestorContactos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GestorContactos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GestorContactos.dir/clean

CMakeFiles/GestorContactos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug C:\Users\branp\CLionProjects\solitario\LabEDD-Practica02\GestorContactos\cmake-build-debug\CMakeFiles\GestorContactos.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GestorContactos.dir/depend

