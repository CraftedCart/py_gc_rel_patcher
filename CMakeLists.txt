cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(py_gc_rel_patcher)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/relFileModule.cpp src/PyRelFile.hpp)

include_directories(external/GC_REL_Patcher/SMB_Rel_Parser/)

################ External Dependencies Includes ################
# This binding requires Python 3 headers and boost-python

# Find Python 3
if(APPLE)
    # Python 3's headers and libs are in an odd place on macOS (At least when installing it with Homebrew)
    # Run special commands for Mac

    find_program(PYTHON3_CONFIG python3-config)
    if(NOT PYTHON3_CONFIG)
        message(FATAL_ERROR "Command python3-config not found - on macOS, this can be installed with homebrew using \"brew install python3\"")
    endif(NOT PYTHON3_CONFIG)

    # Fetch the include dirs and libraries
    # python3-config --includes fetches the headers. The sed commands removes "-I" switches.
    execute_process(COMMAND ${PYTHON3_CONFIG} --includes COMMAND sed s/-I//g OUTPUT_VARIABLE PYTHON_INCLUDE_DIRS)

    # Strip the trailing newline
    string(REGEX REPLACE "\n$" "" PYTHON_INCLUDE_DIRS ${PYTHON_INCLUDE_DIRS})
    string(REGEX REPLACE " " ";" PYTHON_INCLUDE_DIRS ${PYTHON_INCLUDE_DIRS})

    # python3-config --ldflags fetches the libraries and dirs of the libraries to link against. The sed commands remove the -l and -framework flags, and "-L".
    execute_process(COMMAND ${PYTHON3_CONFIG} --ldflags COMMAND sed s/-l[^[:space:]]*//g COMMAND sed s/-framework\ [^[:space:]]*//g COMMAND sed s/-L//g OUTPUT_VARIABLE PYTHON_LINK_DIRS)

    string(REGEX REPLACE "\n$" "" PYTHON_LINK_DIRS ${PYTHON_LINK_DIRS})
    string(REGEX REPLACE " " ";" PYTHON_LINK_DIRS ${PYTHON_LINK_DIRS})

    link_directories(${PYTHON_LINK_DIRS})

    find_library(COREFOUNDATION_LIBRARY CoreFoundation)
else(APPLE)
    # Sanity, I hope
    find_package(PythonLibs 3 REQUIRED)
endif(APPLE)
include_directories(${PYTHON_INCLUDE_DIRS})
# End finding Python 3

# Binding uses boost-python
if(APPLE)
    # Warning about installing boost-python with Homebrew on macOS
    message("NOTE: If you need install boost-python using homebrew, make sure you use brew install \"boost-python --with-python3\"")
endif(APPLE)

find_package(Boost COMPONENTS python3 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
################ End External Dependencies Includes ################

# Define the library
# It's convention in Python to use lowercase (And sometimes snake_case) for module names
add_library(py_gc_rel_patcher MODULE ${SOURCE_FILES})
set_target_properties(py_gc_rel_patcher PROPERTIES PREFIX "") # Remove the lib prefix

################ External Dependencies Linking ################
if(APPLE)
    target_link_libraries(py_gc_rel_patcher ${COREFOUNDATION_LIBRARY})

    # python3-config --libs fetches the libraries to link against. The sed commands removes "-l" and the "-framework" flag.
    execute_process(COMMAND ${PYTHON3_CONFIG} --libs COMMAND sed s/-l//g COMMAND sed s/-framework\ [^[:space:]]*//g COMMAND sed s/\\s*\$//g OUTPUT_VARIABLE PYTHON_LIBRARIES)

    string(REGEX REPLACE "\n$" "" PYTHON_LIBRARIES ${PYTHON_LIBRARIES})
    string(REGEX REPLACE " " ";" PYTHON_LIBRARIES ${PYTHON_LIBRARIES})
endif(APPLE)

target_link_libraries(py_gc_rel_patcher ${PYTHON_LIBRARIES})
target_link_libraries(py_gc_rel_patcher ${Boost_LIBRARIES})
################ End External Dependencies Linking ################

# Copy sample.py
file(COPY "sample.py" DESTINATION "${CMAKE_BINARY_DIR}")
