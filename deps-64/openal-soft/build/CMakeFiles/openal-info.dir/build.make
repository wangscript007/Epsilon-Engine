# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build

# Include any dependencies generated for this target.
include CMakeFiles/openal-info.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openal-info.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openal-info.dir/flags.make

CMakeFiles/openal-info.dir/utils/openal-info.c.obj: CMakeFiles/openal-info.dir/flags.make
CMakeFiles/openal-info.dir/utils/openal-info.c.obj: CMakeFiles/openal-info.dir/includes_C.rsp
CMakeFiles/openal-info.dir/utils/openal-info.c.obj: ../utils/openal-info.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/openal-info.dir/utils/openal-info.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\openal-info.dir\utils\openal-info.c.obj   -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\utils\openal-info.c

CMakeFiles/openal-info.dir/utils/openal-info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/openal-info.dir/utils/openal-info.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\utils\openal-info.c > CMakeFiles\openal-info.dir\utils\openal-info.c.i

CMakeFiles/openal-info.dir/utils/openal-info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/openal-info.dir/utils/openal-info.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\utils\openal-info.c -o CMakeFiles\openal-info.dir\utils\openal-info.c.s

CMakeFiles/openal-info.dir/utils/openal-info.c.obj.requires:

.PHONY : CMakeFiles/openal-info.dir/utils/openal-info.c.obj.requires

CMakeFiles/openal-info.dir/utils/openal-info.c.obj.provides: CMakeFiles/openal-info.dir/utils/openal-info.c.obj.requires
	$(MAKE) -f CMakeFiles\openal-info.dir\build.make CMakeFiles/openal-info.dir/utils/openal-info.c.obj.provides.build
.PHONY : CMakeFiles/openal-info.dir/utils/openal-info.c.obj.provides

CMakeFiles/openal-info.dir/utils/openal-info.c.obj.provides.build: CMakeFiles/openal-info.dir/utils/openal-info.c.obj


# Object files for target openal-info
openal__info_OBJECTS = \
"CMakeFiles/openal-info.dir/utils/openal-info.c.obj"

# External object files for target openal-info
openal__info_EXTERNAL_OBJECTS =

openal-info.exe: CMakeFiles/openal-info.dir/utils/openal-info.c.obj
openal-info.exe: CMakeFiles/openal-info.dir/build.make
openal-info.exe: libOpenAL32.dll.a
openal-info.exe: CMakeFiles/openal-info.dir/linklibs.rsp
openal-info.exe: CMakeFiles/openal-info.dir/objects1.rsp
openal-info.exe: CMakeFiles/openal-info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable openal-info.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\openal-info.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openal-info.dir/build: openal-info.exe

.PHONY : CMakeFiles/openal-info.dir/build

CMakeFiles/openal-info.dir/requires: CMakeFiles/openal-info.dir/utils/openal-info.c.obj.requires

.PHONY : CMakeFiles/openal-info.dir/requires

CMakeFiles/openal-info.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\openal-info.dir\cmake_clean.cmake
.PHONY : CMakeFiles/openal-info.dir/clean

CMakeFiles/openal-info.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles\openal-info.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openal-info.dir/depend

