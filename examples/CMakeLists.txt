file(GLOB_RECURSE examples  *.cpp)

foreach(file_path ${examples})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" file_name ${file_path})
    add_executable(${file_name} ${file_path})
    set_target_properties(${file_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/example)
    include_directories(../src)
    target_link_libraries(${file_name} reactive)

endforeach(file_path)
