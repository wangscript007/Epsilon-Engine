# CMAKE generated file: DO NOT EDIT!
<<<<<<< HEAD
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18
=======
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


<<<<<<< HEAD
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

=======
# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

.SUFFIXES: .hpux_make_needs_suffix_list


<<<<<<< HEAD
# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$$(VERBOSE).SILENT:
=======
# Suppress display of executed commands.
$(VERBOSE).SILENT:
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
<<<<<<< HEAD
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f
=======
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build"
=======
CMAKE_SOURCE_DIR = C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

# Include any dependencies generated for this target.
include CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/common.dir/flags.make

CMakeFiles/common.dir/common/alcomplex.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alcomplex.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/alcomplex.cpp.obj: ../common/alcomplex.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/common.dir/common/alcomplex.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alcomplex.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alcomplex.cpp"

CMakeFiles/common.dir/common/alcomplex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alcomplex.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alcomplex.cpp" > CMakeFiles\common.dir\common\alcomplex.cpp.i

CMakeFiles/common.dir/common/alcomplex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alcomplex.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alcomplex.cpp" -o CMakeFiles\common.dir\common\alcomplex.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/common.dir/common/alcomplex.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alcomplex.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alcomplex.cpp

CMakeFiles/common.dir/common/alcomplex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alcomplex.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alcomplex.cpp > CMakeFiles\common.dir\common\alcomplex.cpp.i

CMakeFiles/common.dir/common/alcomplex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alcomplex.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alcomplex.cpp -o CMakeFiles\common.dir\common\alcomplex.cpp.s

CMakeFiles/common.dir/common/alcomplex.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/alcomplex.cpp.obj.requires

CMakeFiles/common.dir/common/alcomplex.cpp.obj.provides: CMakeFiles/common.dir/common/alcomplex.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/alcomplex.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/alcomplex.cpp.obj.provides

CMakeFiles/common.dir/common/alcomplex.cpp.obj.provides.build: CMakeFiles/common.dir/common/alcomplex.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/alexcpt.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alexcpt.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/alexcpt.cpp.obj: ../common/alexcpt.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/common.dir/common/alexcpt.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alexcpt.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alexcpt.cpp"

CMakeFiles/common.dir/common/alexcpt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alexcpt.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alexcpt.cpp" > CMakeFiles\common.dir\common\alexcpt.cpp.i

CMakeFiles/common.dir/common/alexcpt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alexcpt.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alexcpt.cpp" -o CMakeFiles\common.dir\common\alexcpt.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/common.dir/common/alexcpt.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alexcpt.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alexcpt.cpp

CMakeFiles/common.dir/common/alexcpt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alexcpt.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alexcpt.cpp > CMakeFiles\common.dir\common\alexcpt.cpp.i

CMakeFiles/common.dir/common/alexcpt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alexcpt.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alexcpt.cpp -o CMakeFiles\common.dir\common\alexcpt.cpp.s

CMakeFiles/common.dir/common/alexcpt.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/alexcpt.cpp.obj.requires

CMakeFiles/common.dir/common/alexcpt.cpp.obj.provides: CMakeFiles/common.dir/common/alexcpt.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/alexcpt.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/alexcpt.cpp.obj.provides

CMakeFiles/common.dir/common/alexcpt.cpp.obj.provides.build: CMakeFiles/common.dir/common/alexcpt.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/alfstream.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alfstream.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/alfstream.cpp.obj: ../common/alfstream.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/common.dir/common/alfstream.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alfstream.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alfstream.cpp"

CMakeFiles/common.dir/common/alfstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alfstream.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alfstream.cpp" > CMakeFiles\common.dir\common\alfstream.cpp.i

CMakeFiles/common.dir/common/alfstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alfstream.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alfstream.cpp" -o CMakeFiles\common.dir\common\alfstream.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/common.dir/common/alfstream.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alfstream.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alfstream.cpp

CMakeFiles/common.dir/common/alfstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alfstream.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alfstream.cpp > CMakeFiles\common.dir\common\alfstream.cpp.i

CMakeFiles/common.dir/common/alfstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alfstream.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alfstream.cpp -o CMakeFiles\common.dir\common\alfstream.cpp.s

CMakeFiles/common.dir/common/alfstream.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/alfstream.cpp.obj.requires

CMakeFiles/common.dir/common/alfstream.cpp.obj.provides: CMakeFiles/common.dir/common/alfstream.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/alfstream.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/alfstream.cpp.obj.provides

CMakeFiles/common.dir/common/alfstream.cpp.obj.provides.build: CMakeFiles/common.dir/common/alfstream.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/almalloc.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/almalloc.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/almalloc.cpp.obj: ../common/almalloc.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/common.dir/common/almalloc.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\almalloc.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\almalloc.cpp"

CMakeFiles/common.dir/common/almalloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/almalloc.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\almalloc.cpp" > CMakeFiles\common.dir\common\almalloc.cpp.i

CMakeFiles/common.dir/common/almalloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/almalloc.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\almalloc.cpp" -o CMakeFiles\common.dir\common\almalloc.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/common.dir/common/almalloc.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\almalloc.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\almalloc.cpp

CMakeFiles/common.dir/common/almalloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/almalloc.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\almalloc.cpp > CMakeFiles\common.dir\common\almalloc.cpp.i

CMakeFiles/common.dir/common/almalloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/almalloc.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\almalloc.cpp -o CMakeFiles\common.dir\common\almalloc.cpp.s

CMakeFiles/common.dir/common/almalloc.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/almalloc.cpp.obj.requires

CMakeFiles/common.dir/common/almalloc.cpp.obj.provides: CMakeFiles/common.dir/common/almalloc.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/almalloc.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/almalloc.cpp.obj.provides

CMakeFiles/common.dir/common/almalloc.cpp.obj.provides.build: CMakeFiles/common.dir/common/almalloc.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/alstring.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alstring.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/alstring.cpp.obj: ../common/alstring.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/common.dir/common/alstring.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alstring.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alstring.cpp"

CMakeFiles/common.dir/common/alstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alstring.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alstring.cpp" > CMakeFiles\common.dir\common\alstring.cpp.i

CMakeFiles/common.dir/common/alstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alstring.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\alstring.cpp" -o CMakeFiles\common.dir\common\alstring.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/common.dir/common/alstring.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\alstring.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alstring.cpp

CMakeFiles/common.dir/common/alstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alstring.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alstring.cpp > CMakeFiles\common.dir\common\alstring.cpp.i

CMakeFiles/common.dir/common/alstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alstring.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\alstring.cpp -o CMakeFiles\common.dir\common\alstring.cpp.s

CMakeFiles/common.dir/common/alstring.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/alstring.cpp.obj.requires

CMakeFiles/common.dir/common/alstring.cpp.obj.provides: CMakeFiles/common.dir/common/alstring.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/alstring.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/alstring.cpp.obj.provides

CMakeFiles/common.dir/common/alstring.cpp.obj.provides.build: CMakeFiles/common.dir/common/alstring.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/dynload.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/dynload.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/dynload.cpp.obj: ../common/dynload.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/common.dir/common/dynload.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\dynload.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\dynload.cpp"

CMakeFiles/common.dir/common/dynload.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/dynload.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\dynload.cpp" > CMakeFiles\common.dir\common\dynload.cpp.i

CMakeFiles/common.dir/common/dynload.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/dynload.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\dynload.cpp" -o CMakeFiles\common.dir\common\dynload.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/common.dir/common/dynload.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\dynload.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\dynload.cpp

CMakeFiles/common.dir/common/dynload.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/dynload.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\dynload.cpp > CMakeFiles\common.dir\common\dynload.cpp.i

CMakeFiles/common.dir/common/dynload.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/dynload.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\dynload.cpp -o CMakeFiles\common.dir\common\dynload.cpp.s

CMakeFiles/common.dir/common/dynload.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/dynload.cpp.obj.requires

CMakeFiles/common.dir/common/dynload.cpp.obj.provides: CMakeFiles/common.dir/common/dynload.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/dynload.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/dynload.cpp.obj.provides

CMakeFiles/common.dir/common/dynload.cpp.obj.provides.build: CMakeFiles/common.dir/common/dynload.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj: ../common/polyphase_resampler.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\polyphase_resampler.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\polyphase_resampler.cpp"

CMakeFiles/common.dir/common/polyphase_resampler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/polyphase_resampler.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\polyphase_resampler.cpp" > CMakeFiles\common.dir\common\polyphase_resampler.cpp.i

CMakeFiles/common.dir/common/polyphase_resampler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/polyphase_resampler.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\polyphase_resampler.cpp" -o CMakeFiles\common.dir\common\polyphase_resampler.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\polyphase_resampler.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\polyphase_resampler.cpp

CMakeFiles/common.dir/common/polyphase_resampler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/polyphase_resampler.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\polyphase_resampler.cpp > CMakeFiles\common.dir\common\polyphase_resampler.cpp.i

CMakeFiles/common.dir/common/polyphase_resampler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/polyphase_resampler.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\polyphase_resampler.cpp -o CMakeFiles\common.dir\common\polyphase_resampler.cpp.s

CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.requires

CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.provides: CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.provides

CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.provides.build: CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/strutils.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/strutils.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/strutils.cpp.obj: ../common/strutils.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/common.dir/common/strutils.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\strutils.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\strutils.cpp"

CMakeFiles/common.dir/common/strutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/strutils.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\strutils.cpp" > CMakeFiles\common.dir\common\strutils.cpp.i

CMakeFiles/common.dir/common/strutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/strutils.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\strutils.cpp" -o CMakeFiles\common.dir\common\strutils.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/common.dir/common/strutils.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\strutils.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\strutils.cpp

CMakeFiles/common.dir/common/strutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/strutils.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\strutils.cpp > CMakeFiles\common.dir\common\strutils.cpp.i

CMakeFiles/common.dir/common/strutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/strutils.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\strutils.cpp -o CMakeFiles\common.dir\common\strutils.cpp.s

CMakeFiles/common.dir/common/strutils.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/strutils.cpp.obj.requires

CMakeFiles/common.dir/common/strutils.cpp.obj.provides: CMakeFiles/common.dir/common/strutils.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/strutils.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/strutils.cpp.obj.provides

CMakeFiles/common.dir/common/strutils.cpp.obj.provides.build: CMakeFiles/common.dir/common/strutils.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

CMakeFiles/common.dir/common/threads.cpp.obj: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/threads.cpp.obj: CMakeFiles/common.dir/includes_CXX.rsp
CMakeFiles/common.dir/common/threads.cpp.obj: ../common/threads.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/common.dir/common/threads.cpp.obj"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\threads.cpp.obj -c "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\threads.cpp"

CMakeFiles/common.dir/common/threads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/threads.cpp.i"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\threads.cpp" > CMakeFiles\common.dir\common\threads.cpp.i

CMakeFiles/common.dir/common/threads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/threads.cpp.s"
	H:\msys2\msys64\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\common\threads.cpp" -o CMakeFiles\common.dir\common\threads.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/common.dir/common/threads.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\common.dir\common\threads.cpp.obj -c C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\threads.cpp

CMakeFiles/common.dir/common/threads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/threads.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\threads.cpp > CMakeFiles\common.dir\common\threads.cpp.i

CMakeFiles/common.dir/common/threads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/threads.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\common\threads.cpp -o CMakeFiles\common.dir\common\threads.cpp.s

CMakeFiles/common.dir/common/threads.cpp.obj.requires:

.PHONY : CMakeFiles/common.dir/common/threads.cpp.obj.requires

CMakeFiles/common.dir/common/threads.cpp.obj.provides: CMakeFiles/common.dir/common/threads.cpp.obj.requires
	$(MAKE) -f CMakeFiles\common.dir\build.make CMakeFiles/common.dir/common/threads.cpp.obj.provides.build
.PHONY : CMakeFiles/common.dir/common/threads.cpp.obj.provides

CMakeFiles/common.dir/common/threads.cpp.obj.provides.build: CMakeFiles/common.dir/common/threads.cpp.obj

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/common/alcomplex.cpp.obj" \
"CMakeFiles/common.dir/common/alexcpt.cpp.obj" \
"CMakeFiles/common.dir/common/alfstream.cpp.obj" \
"CMakeFiles/common.dir/common/almalloc.cpp.obj" \
"CMakeFiles/common.dir/common/alstring.cpp.obj" \
"CMakeFiles/common.dir/common/dynload.cpp.obj" \
"CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj" \
"CMakeFiles/common.dir/common/strutils.cpp.obj" \
"CMakeFiles/common.dir/common/threads.cpp.obj"

# External object files for target common
common_EXTERNAL_OBJECTS =

libcommon.a: CMakeFiles/common.dir/common/alcomplex.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/alexcpt.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/alfstream.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/almalloc.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/alstring.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/dynload.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/strutils.cpp.obj
libcommon.a: CMakeFiles/common.dir/common/threads.cpp.obj
libcommon.a: CMakeFiles/common.dir/build.make
libcommon.a: CMakeFiles/common.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libcommon.a"
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libcommon.a"
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed
	$(CMAKE_COMMAND) -P CMakeFiles\common.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\common.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/common.dir/build: libcommon.a

.PHONY : CMakeFiles/common.dir/build

<<<<<<< HEAD
=======
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alcomplex.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alexcpt.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alfstream.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/almalloc.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alstring.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/dynload.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/polyphase_resampler.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/strutils.cpp.obj.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/threads.cpp.obj.requires

.PHONY : CMakeFiles/common.dir/requires

>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed
CMakeFiles/common.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\common.dir\cmake_clean.cmake
.PHONY : CMakeFiles/common.dir/clean

CMakeFiles/common.dir/depend:
<<<<<<< HEAD
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft" "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft" "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build" "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build" "H:\Epsilon\Epsilon Engine\thirdparty\openal-soft\build\CMakeFiles\common.dir\DependInfo.cmake" --color=$(COLOR)
=======
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build C:\Users\Imanol\Documents\Code\C++\Epsilon\deps-64\openal-soft\build\CMakeFiles\common.dir\DependInfo.cmake --color=$(COLOR)
>>>>>>> f87825e45cd4ab71b09c8c50f30bd763892779ed
.PHONY : CMakeFiles/common.dir/depend

