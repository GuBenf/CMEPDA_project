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
CMAKE_SOURCE_DIR = /home/guglibenfri/CMEPDA_project/sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guglibenfri/CMEPDA_project/sim/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/sim.cc.o: ../sim.cc
CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/sim.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/sim.cc.o -MF CMakeFiles/sim.dir/sim.cc.o.d -o CMakeFiles/sim.dir/sim.cc.o -c /home/guglibenfri/CMEPDA_project/sim/sim.cc

CMakeFiles/sim.dir/sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/sim.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/sim.cc > CMakeFiles/sim.dir/sim.cc.i

CMakeFiles/sim.dir/sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/sim.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/sim.cc -o CMakeFiles/sim.dir/sim.cc.s

CMakeFiles/sim.dir/action.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/action.cc.o: ../action.cc
CMakeFiles/sim.dir/action.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/action.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/action.cc.o -MF CMakeFiles/sim.dir/action.cc.o.d -o CMakeFiles/sim.dir/action.cc.o -c /home/guglibenfri/CMEPDA_project/sim/action.cc

CMakeFiles/sim.dir/action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/action.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/action.cc > CMakeFiles/sim.dir/action.cc.i

CMakeFiles/sim.dir/action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/action.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/action.cc -o CMakeFiles/sim.dir/action.cc.s

CMakeFiles/sim.dir/construction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/construction.cc.o: ../construction.cc
CMakeFiles/sim.dir/construction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/construction.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/construction.cc.o -MF CMakeFiles/sim.dir/construction.cc.o.d -o CMakeFiles/sim.dir/construction.cc.o -c /home/guglibenfri/CMEPDA_project/sim/construction.cc

CMakeFiles/sim.dir/construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/construction.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/construction.cc > CMakeFiles/sim.dir/construction.cc.i

CMakeFiles/sim.dir/construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/construction.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/construction.cc -o CMakeFiles/sim.dir/construction.cc.s

CMakeFiles/sim.dir/detector.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/detector.cc.o: ../detector.cc
CMakeFiles/sim.dir/detector.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/detector.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/detector.cc.o -MF CMakeFiles/sim.dir/detector.cc.o.d -o CMakeFiles/sim.dir/detector.cc.o -c /home/guglibenfri/CMEPDA_project/sim/detector.cc

CMakeFiles/sim.dir/detector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/detector.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/detector.cc > CMakeFiles/sim.dir/detector.cc.i

CMakeFiles/sim.dir/detector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/detector.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/detector.cc -o CMakeFiles/sim.dir/detector.cc.s

CMakeFiles/sim.dir/generator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/generator.cc.o: ../generator.cc
CMakeFiles/sim.dir/generator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/generator.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/generator.cc.o -MF CMakeFiles/sim.dir/generator.cc.o.d -o CMakeFiles/sim.dir/generator.cc.o -c /home/guglibenfri/CMEPDA_project/sim/generator.cc

CMakeFiles/sim.dir/generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/generator.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/generator.cc > CMakeFiles/sim.dir/generator.cc.i

CMakeFiles/sim.dir/generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/generator.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/generator.cc -o CMakeFiles/sim.dir/generator.cc.s

CMakeFiles/sim.dir/physics.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/physics.cc.o: ../physics.cc
CMakeFiles/sim.dir/physics.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sim.dir/physics.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/physics.cc.o -MF CMakeFiles/sim.dir/physics.cc.o.d -o CMakeFiles/sim.dir/physics.cc.o -c /home/guglibenfri/CMEPDA_project/sim/physics.cc

CMakeFiles/sim.dir/physics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/physics.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guglibenfri/CMEPDA_project/sim/physics.cc > CMakeFiles/sim.dir/physics.cc.i

CMakeFiles/sim.dir/physics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/physics.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guglibenfri/CMEPDA_project/sim/physics.cc -o CMakeFiles/sim.dir/physics.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/sim.cc.o" \
"CMakeFiles/sim.dir/action.cc.o" \
"CMakeFiles/sim.dir/construction.cc.o" \
"CMakeFiles/sim.dir/detector.cc.o" \
"CMakeFiles/sim.dir/generator.cc.o" \
"CMakeFiles/sim.dir/physics.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/sim.cc.o
sim: CMakeFiles/sim.dir/action.cc.o
sim: CMakeFiles/sim.dir/construction.cc.o
sim: CMakeFiles/sim.dir/detector.cc.o
sim: CMakeFiles/sim.dir/generator.cc.o
sim: CMakeFiles/sim.dir/physics.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4Tree.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4FR.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4GMocren.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4visHepRep.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4RayTracer.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4VRML.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4ToolsSG.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4OpenGL.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4vis_management.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4modeling.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4interfaces.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4mctruth.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4geomtext.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4error_propagation.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4readout.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4physicslists.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4run.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4event.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4tracking.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4parmodels.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4processes.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4digits_hits.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4track.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4particles.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4geometry.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4materials.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4graphics_reps.so
sim: /usr/lib/x86_64-linux-gnu/libGL.so
sim: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
sim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
sim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
sim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4analysis.so
sim: /usr/lib/x86_64-linux-gnu/libexpat.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4zlib.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4intercoms.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4global.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4clhep.so
sim: /home/guglibenfri/pippo/geant4-v11.2.2.install/lib/libG4ptl.so.2.3.3
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim
.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/guglibenfri/CMEPDA_project/sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guglibenfri/CMEPDA_project/sim /home/guglibenfri/CMEPDA_project/sim /home/guglibenfri/CMEPDA_project/sim/build /home/guglibenfri/CMEPDA_project/sim/build /home/guglibenfri/CMEPDA_project/sim/build/CMakeFiles/sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sim.dir/depend

