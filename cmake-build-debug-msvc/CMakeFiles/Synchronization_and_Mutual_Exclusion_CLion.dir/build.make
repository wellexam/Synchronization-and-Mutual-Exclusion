# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc

# Include any dependencies generated for this target.
include CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\flags.make

CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.obj: CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\flags.make
CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.obj: ..\reader_writer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Synchronization_and_Mutual_Exclusion_CLion.dir/reader_writer.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.obj /FdCMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\ /FS -c C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\reader_writer.cpp
<<

CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Synchronization_and_Mutual_Exclusion_CLion.dir/reader_writer.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\reader_writer.cpp
<<

CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Synchronization_and_Mutual_Exclusion_CLion.dir/reader_writer.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.s /c C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\reader_writer.cpp
<<

# Object files for target Synchronization_and_Mutual_Exclusion_CLion
Synchronization_and_Mutual_Exclusion_CLion_OBJECTS = \
"CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.obj"

# External object files for target Synchronization_and_Mutual_Exclusion_CLion
Synchronization_and_Mutual_Exclusion_CLion_EXTERNAL_OBJECTS =

Synchronization_and_Mutual_Exclusion_CLion.exe: CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\reader_writer.cpp.obj
Synchronization_and_Mutual_Exclusion_CLion.exe: CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\build.make
Synchronization_and_Mutual_Exclusion_CLion.exe: CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Synchronization_and_Mutual_Exclusion_CLion.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\objects1.rsp @<<
 /out:Synchronization_and_Mutual_Exclusion_CLion.exe /implib:Synchronization_and_Mutual_Exclusion_CLion.lib /pdb:C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc\Synchronization_and_Mutual_Exclusion_CLion.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\build: Synchronization_and_Mutual_Exclusion_CLion.exe

.PHONY : CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\build

CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\clean

CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc C:\VS-CODE\CPP\Synchronization-and-Mutual-Exclusion\cmake-build-debug-msvc\CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Synchronization_and_Mutual_Exclusion_CLion.dir\depend
