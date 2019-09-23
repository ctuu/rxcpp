cmake_minimum_required(VERSION 3.0.0)
project(rx)

set(EXTRA_LIBS "" CACHE STRING INTERNAL FORCE)
set(EXTRA_INCLUDES "" CACHE STRING INTERNAL FORCE)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2")

add_subdirectory (lib)
add_subdirectory (src)