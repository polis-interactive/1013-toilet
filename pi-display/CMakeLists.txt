cmake_minimum_required(VERSION 3.18)

set(CMAKE_VERBOSE_MAKEFILE ON)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
            FATAL_ERROR
            "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    message("Setting debug flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

SET(TOILET_PLATFORM "BROOSE_LINUX_LAPTOP" CACHE STRING "Sets up the build env")

project (
    TolietPiDisplay
    VERSION 1.0
    LANGUAGES CXX
)

include(cmake/platform.cmake)

set(root_dir ${CMAKE_CURRENT_LIST_DIR})
set(internal_dir ${root_dir}/internal)
set(third_party_dir ${root_dir}/third_party)
set(glad_dir ${third_party_dir}/glad)

include_directories(${internal_dir})
include_directories(${glad_dir}/include)

add_subdirectory(${internal_dir}/infrastructure/camera)
add_subdirectory(${internal_dir}/infrastructure/websocket)
add_subdirectory(${internal_dir}/infrastructure/graphics)

add_executable(
    toilet
        ${root_dir}/main.cpp
)
target_link_libraries(toilet PRIVATE pthread toilet_camera toilet_graphics toilet_websocket)

add_subdirectory(test)