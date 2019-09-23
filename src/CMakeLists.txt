set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(ENTRY "main.cpp")

add_executable(main ${ENTRY} main.cpp)

include_directories(${EXTRA_INCLUDES})
target_link_libraries(main ${EXTRA_LIBS})
