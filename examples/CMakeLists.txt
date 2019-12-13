file(GLOB examples  *.cpp)

foreach(file_path ${examples})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" example_target ${file_path})

    add_executable(${example_target} ${file_path})

    target_compile_features(${example_target} PRIVATE cxx_std_17)

    target_link_libraries(${example_target}
    PRIVATE
        reactive
    )

    set_target_properties(${example_target}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/examples
    )

endforeach(file_path)
