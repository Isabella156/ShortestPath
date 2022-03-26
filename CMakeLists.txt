cmake_minimum_required(VERSION 2.8.12)
project(project2)

# change this to Release to activate optimization and compile without debug symbols
set(CMAKE_BUILD_TYPE Debug)

# bring the headers
include_directories(include)

include_directories(unityTest/unity/include)



# the file (GOLB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

#4.source directory，源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(project2 ${SOURCES})
add_executable(unitTest unitTest/unit_tests.c src/adjList.c src/interface.c unitTest/unity.c)