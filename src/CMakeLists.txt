add_library(reactive SHARED)

target_compile_features(reactive PRIVATE cxx_std_17)

set_target_properties(reactive
PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

target_include_directories(reactive
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_sources(reactive
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/async_subject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/async_subject.h

    ${CMAKE_CURRENT_SOURCE_DIR}/behavior_subject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/behavior_subject.h

    ${CMAKE_CURRENT_SOURCE_DIR}/functor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functor.h

    ${CMAKE_CURRENT_SOURCE_DIR}/observable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/observable.h

    ${CMAKE_CURRENT_SOURCE_DIR}/replay_subject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/replay_subject.h

    ${CMAKE_CURRENT_SOURCE_DIR}/rx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rx.h

    ${CMAKE_CURRENT_SOURCE_DIR}/subject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/subject.h

    ${CMAKE_CURRENT_SOURCE_DIR}/subscriber.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/subscriber.h
)
