cmake_minimum_required(VERSION 3.0.0)
project(rx)

# set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2")

file(GLOB_RECURSE all_files  src/*.cpp)
add_library(reactive SHARED ${all_files})

add_subdirectory(examples)
