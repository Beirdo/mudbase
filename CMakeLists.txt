cmake_minimum_required(VERSION 3.8)
set(Boost_INCLUDE_DIR d:/mingw/include/)
set(Boost_LIBRARY_DIR d:/mingw/lib/)
include_directories(${Boost_INCLUDE_DIR})
find_package(Boost COMPONENTS system filesystem REQUIRED)

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