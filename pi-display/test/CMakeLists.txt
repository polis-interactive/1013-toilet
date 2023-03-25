
cmake_minimum_required(VERSION 3.18)

project(Toilet_Test LANGUAGES CXX)

include_directories(${root_dir}/third_party/doctest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(
    tests
        main.cpp
        test_infrastructure/test_websocket.cpp
)

set(tests_link_libraries toilet_websocket)

add_definitions(-DTEST_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(tests ${tests})

target_link_libraries(tests ${tests_link_libraries})