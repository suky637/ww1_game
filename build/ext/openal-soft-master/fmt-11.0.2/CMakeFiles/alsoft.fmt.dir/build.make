# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/suky/dev/ww1_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suky/dev/ww1_game/build

# Include any dependencies generated for this target.
include ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/compiler_depend.make

# Include the progress variables for this target.
include ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/progress.make

# Include the compile flags for this target's objects.
include ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/flags.make

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/flags.make
ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o: ../ext/openal-soft-master/fmt-11.0.2/src/format.cc
ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suky/dev/ww1_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o -MF CMakeFiles/alsoft.fmt.dir/src/format.cc.o.d -o CMakeFiles/alsoft.fmt.dir/src/format.cc.o -c /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/format.cc

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alsoft.fmt.dir/src/format.cc.i"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/format.cc > CMakeFiles/alsoft.fmt.dir/src/format.cc.i

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alsoft.fmt.dir/src/format.cc.s"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/format.cc -o CMakeFiles/alsoft.fmt.dir/src/format.cc.s

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/flags.make
ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o: ../ext/openal-soft-master/fmt-11.0.2/src/os.cc
ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suky/dev/ww1_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o -MF CMakeFiles/alsoft.fmt.dir/src/os.cc.o.d -o CMakeFiles/alsoft.fmt.dir/src/os.cc.o -c /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/os.cc

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alsoft.fmt.dir/src/os.cc.i"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/os.cc > CMakeFiles/alsoft.fmt.dir/src/os.cc.i

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alsoft.fmt.dir/src/os.cc.s"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2/src/os.cc -o CMakeFiles/alsoft.fmt.dir/src/os.cc.s

# Object files for target alsoft.fmt
alsoft_fmt_OBJECTS = \
"CMakeFiles/alsoft.fmt.dir/src/format.cc.o" \
"CMakeFiles/alsoft.fmt.dir/src/os.cc.o"

# External object files for target alsoft.fmt
alsoft_fmt_EXTERNAL_OBJECTS =

ext/openal-soft-master/fmt-11.0.2/libalsoft.fmtd.a: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/format.cc.o
ext/openal-soft-master/fmt-11.0.2/libalsoft.fmtd.a: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/src/os.cc.o
ext/openal-soft-master/fmt-11.0.2/libalsoft.fmtd.a: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/build.make
ext/openal-soft-master/fmt-11.0.2/libalsoft.fmtd.a: ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suky/dev/ww1_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libalsoft.fmtd.a"
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && $(CMAKE_COMMAND) -P CMakeFiles/alsoft.fmt.dir/cmake_clean_target.cmake
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alsoft.fmt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/build: ext/openal-soft-master/fmt-11.0.2/libalsoft.fmtd.a
.PHONY : ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/build

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/clean:
	cd /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 && $(CMAKE_COMMAND) -P CMakeFiles/alsoft.fmt.dir/cmake_clean.cmake
.PHONY : ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/clean

ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/depend:
	cd /home/suky/dev/ww1_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suky/dev/ww1_game /home/suky/dev/ww1_game/ext/openal-soft-master/fmt-11.0.2 /home/suky/dev/ww1_game/build /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2 /home/suky/dev/ww1_game/build/ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/openal-soft-master/fmt-11.0.2/CMakeFiles/alsoft.fmt.dir/depend

