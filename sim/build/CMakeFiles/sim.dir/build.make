# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/sim.cc.o: /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/sim.cc
CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/sim.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/sim.cc.o -MF CMakeFiles/sim.dir/sim.cc.o.d -o CMakeFiles/sim.dir/sim.cc.o -c /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/sim.cc

CMakeFiles/sim.dir/sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/sim.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/sim.cc > CMakeFiles/sim.dir/sim.cc.i

CMakeFiles/sim.dir/sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/sim.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/sim.cc -o CMakeFiles/sim.dir/sim.cc.s

CMakeFiles/sim.dir/action.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/action.cc.o: /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/action.cc
CMakeFiles/sim.dir/action.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/action.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/action.cc.o -MF CMakeFiles/sim.dir/action.cc.o.d -o CMakeFiles/sim.dir/action.cc.o -c /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/action.cc

CMakeFiles/sim.dir/action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/action.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/action.cc > CMakeFiles/sim.dir/action.cc.i

CMakeFiles/sim.dir/action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/action.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/action.cc -o CMakeFiles/sim.dir/action.cc.s

CMakeFiles/sim.dir/construction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/construction.cc.o: /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/construction.cc
CMakeFiles/sim.dir/construction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/construction.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/construction.cc.o -MF CMakeFiles/sim.dir/construction.cc.o.d -o CMakeFiles/sim.dir/construction.cc.o -c /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/construction.cc

CMakeFiles/sim.dir/construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/construction.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/construction.cc > CMakeFiles/sim.dir/construction.cc.i

CMakeFiles/sim.dir/construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/construction.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/construction.cc -o CMakeFiles/sim.dir/construction.cc.s

CMakeFiles/sim.dir/generator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/generator.cc.o: /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/generator.cc
CMakeFiles/sim.dir/generator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/generator.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/generator.cc.o -MF CMakeFiles/sim.dir/generator.cc.o.d -o CMakeFiles/sim.dir/generator.cc.o -c /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/generator.cc

CMakeFiles/sim.dir/generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/generator.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/generator.cc > CMakeFiles/sim.dir/generator.cc.i

CMakeFiles/sim.dir/generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/generator.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/generator.cc -o CMakeFiles/sim.dir/generator.cc.s

CMakeFiles/sim.dir/physics.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/physics.cc.o: /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/physics.cc
CMakeFiles/sim.dir/physics.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/physics.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/physics.cc.o -MF CMakeFiles/sim.dir/physics.cc.o.d -o CMakeFiles/sim.dir/physics.cc.o -c /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/physics.cc

CMakeFiles/sim.dir/physics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/physics.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/physics.cc > CMakeFiles/sim.dir/physics.cc.i

CMakeFiles/sim.dir/physics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/physics.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/physics.cc -o CMakeFiles/sim.dir/physics.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/sim.cc.o" \
"CMakeFiles/sim.dir/action.cc.o" \
"CMakeFiles/sim.dir/construction.cc.o" \
"CMakeFiles/sim.dir/generator.cc.o" \
"CMakeFiles/sim.dir/physics.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/sim.cc.o
sim: CMakeFiles/sim.dir/action.cc.o
sim: CMakeFiles/sim.dir/construction.cc.o
sim: CMakeFiles/sim.dir/generator.cc.o
sim: CMakeFiles/sim.dir/physics.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4Tree.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4FR.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4GMocren.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4visHepRep.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4RayTracer.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4VRML.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4ToolsSG.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4OpenGL.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4vis_management.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4modeling.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4interfaces.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4mctruth.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4geomtext.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4error_propagation.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4readout.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4physicslists.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4run.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4event.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4tracking.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4parmodels.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4processes.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4digits_hits.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4track.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4particles.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4geometry.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4materials.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4graphics_reps.dylib
sim: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/System/Library/Frameworks/OpenGL.framework
sim: /opt/homebrew/Cellar/qt@5/5.15.15/lib/QtOpenGL.framework/QtOpenGL
sim: /opt/homebrew/Cellar/qt@5/5.15.15/lib/QtWidgets.framework/QtWidgets
sim: /opt/homebrew/Cellar/qt@5/5.15.15/lib/QtGui.framework/QtGui
sim: /opt/homebrew/Cellar/qt@5/5.15.15/lib/QtCore.framework/QtCore
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4analysis.dylib
sim: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libexpat.tbd
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4zlib.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4intercoms.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4global.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4clhep.dylib
sim: /Users/Alberto/Desktop/Geant4/geant4-v11.2.2-install/lib/libG4ptl.2.3.3.dylib
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim
.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build /Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/build/CMakeFiles/sim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sim.dir/depend

