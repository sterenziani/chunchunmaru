# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/santi/repos/chunchunmaru/Libraries/openal-soft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/santi/repos/chunchunmaru/Libraries/openal-soft/build

# Include any dependencies generated for this target.
include CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/common.dir/flags.make

CMakeFiles/common.dir/common/alcomplex.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alcomplex.cpp.o: ../common/alcomplex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/common.dir/common/alcomplex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/alcomplex.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alcomplex.cpp

CMakeFiles/common.dir/common/alcomplex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alcomplex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alcomplex.cpp > CMakeFiles/common.dir/common/alcomplex.cpp.i

CMakeFiles/common.dir/common/alcomplex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alcomplex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alcomplex.cpp -o CMakeFiles/common.dir/common/alcomplex.cpp.s

CMakeFiles/common.dir/common/alcomplex.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/alcomplex.cpp.o.requires

CMakeFiles/common.dir/common/alcomplex.cpp.o.provides: CMakeFiles/common.dir/common/alcomplex.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/alcomplex.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/alcomplex.cpp.o.provides

CMakeFiles/common.dir/common/alcomplex.cpp.o.provides.build: CMakeFiles/common.dir/common/alcomplex.cpp.o


CMakeFiles/common.dir/common/alexcpt.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alexcpt.cpp.o: ../common/alexcpt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/common.dir/common/alexcpt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/alexcpt.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alexcpt.cpp

CMakeFiles/common.dir/common/alexcpt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alexcpt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alexcpt.cpp > CMakeFiles/common.dir/common/alexcpt.cpp.i

CMakeFiles/common.dir/common/alexcpt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alexcpt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alexcpt.cpp -o CMakeFiles/common.dir/common/alexcpt.cpp.s

CMakeFiles/common.dir/common/alexcpt.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/alexcpt.cpp.o.requires

CMakeFiles/common.dir/common/alexcpt.cpp.o.provides: CMakeFiles/common.dir/common/alexcpt.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/alexcpt.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/alexcpt.cpp.o.provides

CMakeFiles/common.dir/common/alexcpt.cpp.o.provides.build: CMakeFiles/common.dir/common/alexcpt.cpp.o


CMakeFiles/common.dir/common/alfstream.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alfstream.cpp.o: ../common/alfstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/common.dir/common/alfstream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/alfstream.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alfstream.cpp

CMakeFiles/common.dir/common/alfstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alfstream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alfstream.cpp > CMakeFiles/common.dir/common/alfstream.cpp.i

CMakeFiles/common.dir/common/alfstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alfstream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alfstream.cpp -o CMakeFiles/common.dir/common/alfstream.cpp.s

CMakeFiles/common.dir/common/alfstream.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/alfstream.cpp.o.requires

CMakeFiles/common.dir/common/alfstream.cpp.o.provides: CMakeFiles/common.dir/common/alfstream.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/alfstream.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/alfstream.cpp.o.provides

CMakeFiles/common.dir/common/alfstream.cpp.o.provides.build: CMakeFiles/common.dir/common/alfstream.cpp.o


CMakeFiles/common.dir/common/almalloc.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/almalloc.cpp.o: ../common/almalloc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/common.dir/common/almalloc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/almalloc.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/almalloc.cpp

CMakeFiles/common.dir/common/almalloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/almalloc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/almalloc.cpp > CMakeFiles/common.dir/common/almalloc.cpp.i

CMakeFiles/common.dir/common/almalloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/almalloc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/almalloc.cpp -o CMakeFiles/common.dir/common/almalloc.cpp.s

CMakeFiles/common.dir/common/almalloc.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/almalloc.cpp.o.requires

CMakeFiles/common.dir/common/almalloc.cpp.o.provides: CMakeFiles/common.dir/common/almalloc.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/almalloc.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/almalloc.cpp.o.provides

CMakeFiles/common.dir/common/almalloc.cpp.o.provides.build: CMakeFiles/common.dir/common/almalloc.cpp.o


CMakeFiles/common.dir/common/alstring.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/alstring.cpp.o: ../common/alstring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/common.dir/common/alstring.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/alstring.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alstring.cpp

CMakeFiles/common.dir/common/alstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/alstring.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alstring.cpp > CMakeFiles/common.dir/common/alstring.cpp.i

CMakeFiles/common.dir/common/alstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/alstring.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/alstring.cpp -o CMakeFiles/common.dir/common/alstring.cpp.s

CMakeFiles/common.dir/common/alstring.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/alstring.cpp.o.requires

CMakeFiles/common.dir/common/alstring.cpp.o.provides: CMakeFiles/common.dir/common/alstring.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/alstring.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/alstring.cpp.o.provides

CMakeFiles/common.dir/common/alstring.cpp.o.provides.build: CMakeFiles/common.dir/common/alstring.cpp.o


CMakeFiles/common.dir/common/dynload.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/dynload.cpp.o: ../common/dynload.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/common.dir/common/dynload.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/dynload.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/dynload.cpp

CMakeFiles/common.dir/common/dynload.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/dynload.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/dynload.cpp > CMakeFiles/common.dir/common/dynload.cpp.i

CMakeFiles/common.dir/common/dynload.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/dynload.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/dynload.cpp -o CMakeFiles/common.dir/common/dynload.cpp.s

CMakeFiles/common.dir/common/dynload.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/dynload.cpp.o.requires

CMakeFiles/common.dir/common/dynload.cpp.o.provides: CMakeFiles/common.dir/common/dynload.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/dynload.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/dynload.cpp.o.provides

CMakeFiles/common.dir/common/dynload.cpp.o.provides.build: CMakeFiles/common.dir/common/dynload.cpp.o


CMakeFiles/common.dir/common/strutils.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/strutils.cpp.o: ../common/strutils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/common.dir/common/strutils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/strutils.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/strutils.cpp

CMakeFiles/common.dir/common/strutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/strutils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/strutils.cpp > CMakeFiles/common.dir/common/strutils.cpp.i

CMakeFiles/common.dir/common/strutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/strutils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/strutils.cpp -o CMakeFiles/common.dir/common/strutils.cpp.s

CMakeFiles/common.dir/common/strutils.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/strutils.cpp.o.requires

CMakeFiles/common.dir/common/strutils.cpp.o.provides: CMakeFiles/common.dir/common/strutils.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/strutils.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/strutils.cpp.o.provides

CMakeFiles/common.dir/common/strutils.cpp.o.provides.build: CMakeFiles/common.dir/common/strutils.cpp.o


CMakeFiles/common.dir/common/threads.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/common/threads.cpp.o: ../common/threads.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/common.dir/common/threads.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common/threads.cpp.o -c /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/threads.cpp

CMakeFiles/common.dir/common/threads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common/threads.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/threads.cpp > CMakeFiles/common.dir/common/threads.cpp.i

CMakeFiles/common.dir/common/threads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common/threads.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/santi/repos/chunchunmaru/Libraries/openal-soft/common/threads.cpp -o CMakeFiles/common.dir/common/threads.cpp.s

CMakeFiles/common.dir/common/threads.cpp.o.requires:

.PHONY : CMakeFiles/common.dir/common/threads.cpp.o.requires

CMakeFiles/common.dir/common/threads.cpp.o.provides: CMakeFiles/common.dir/common/threads.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/common/threads.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/common/threads.cpp.o.provides

CMakeFiles/common.dir/common/threads.cpp.o.provides.build: CMakeFiles/common.dir/common/threads.cpp.o


# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/common/alcomplex.cpp.o" \
"CMakeFiles/common.dir/common/alexcpt.cpp.o" \
"CMakeFiles/common.dir/common/alfstream.cpp.o" \
"CMakeFiles/common.dir/common/almalloc.cpp.o" \
"CMakeFiles/common.dir/common/alstring.cpp.o" \
"CMakeFiles/common.dir/common/dynload.cpp.o" \
"CMakeFiles/common.dir/common/strutils.cpp.o" \
"CMakeFiles/common.dir/common/threads.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

libcommon.a: CMakeFiles/common.dir/common/alcomplex.cpp.o
libcommon.a: CMakeFiles/common.dir/common/alexcpt.cpp.o
libcommon.a: CMakeFiles/common.dir/common/alfstream.cpp.o
libcommon.a: CMakeFiles/common.dir/common/almalloc.cpp.o
libcommon.a: CMakeFiles/common.dir/common/alstring.cpp.o
libcommon.a: CMakeFiles/common.dir/common/dynload.cpp.o
libcommon.a: CMakeFiles/common.dir/common/strutils.cpp.o
libcommon.a: CMakeFiles/common.dir/common/threads.cpp.o
libcommon.a: CMakeFiles/common.dir/build.make
libcommon.a: CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libcommon.a"
	$(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/common.dir/build: libcommon.a

.PHONY : CMakeFiles/common.dir/build

CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alcomplex.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alexcpt.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alfstream.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/almalloc.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/alstring.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/dynload.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/strutils.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/common/threads.cpp.o.requires

.PHONY : CMakeFiles/common.dir/requires

CMakeFiles/common.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : CMakeFiles/common.dir/clean

CMakeFiles/common.dir/depend:
	cd /home/santi/repos/chunchunmaru/Libraries/openal-soft/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/santi/repos/chunchunmaru/Libraries/openal-soft /home/santi/repos/chunchunmaru/Libraries/openal-soft /home/santi/repos/chunchunmaru/Libraries/openal-soft/build /home/santi/repos/chunchunmaru/Libraries/openal-soft/build /home/santi/repos/chunchunmaru/Libraries/openal-soft/build/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/common.dir/depend

