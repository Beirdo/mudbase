cmake_minimum_required(VERSION 3.7)
set(BOOST_INCLUDEDIR /usr/include/)
set(BOOST_LIBRARYDIR /usr/lib/x86_64-linux-gnu/)
set(CMAKE_FIND_LIBRARY_PREFIXES lib)
set(CMAKE_FIND_LIBRARY_SUFFIXES so)
include_directories(${Boost_INCLUDE_DIR})
find_package(Boost 1.63 REQUIRED COMPONENTS system filesystem)

project(Mudbase)

set(Mudbase_VERSION_MAJOR 0)
set(Mudbase_VERSION_MINOR 1)

set(PROJECT_SOURCE_DIR src)
include(${PROJECT_SOURCE_DIR}/CMakeLists.txt)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/Config.h.in"
        "${PROJECT_BINARY_DIR}/Config.h"
)

# add the binary tree to the search path for include files
# so that we will find Config.h
include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}")

add_executable(Mudbase ${Mudbase_SOURCES})
