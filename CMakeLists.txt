cmake_minimum_required(VERSION 3.7)
add_subdirectory(boost-cmake)

project(Mudbase)

set(Mudbase_VERSION_MAJOR 0)
set(Mudbase_VERSION_MINOR 1)

set(PROJECT_SOURCE_DIR src)
set(CMAKE_CXX_VERSION 11)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(SML_INCLUDE_DIR sml/include)

include(${PROJECT_SOURCE_DIR}/CMakeLists.txt)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/Config.h.in"
        "${PROJECT_BINARY_DIR}/Config.h"
)

# add the binary tree to the search path for include files
# so that we will find Config.h
include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}"
                    "${SML_INCLUDE_DIR}")

add_executable(Mudbase ${Mudbase_SOURCES})
target_link_libraries(Mudbase Boost::system)
target_link_libraries(Mudbase Boost::boost)
target_link_libraries(Mudbase Boost::fiber)
