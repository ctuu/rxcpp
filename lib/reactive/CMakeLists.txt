set(EXTRA_LIBS ${EXTRA_LIBS} reactive CACHE STRING INTERNAL FORCE)
set(EXTRA_INCLUDES ${EXTRA_INCLUDES} ${PROJECT_SOURCE_DIR}/lib/reactive/src CACHE STRING INTERNAL FORCE)

include_directories(src)

file(GLOB_RECURSE all_files  src/*.cpp)
add_library(reactive ${all_files})