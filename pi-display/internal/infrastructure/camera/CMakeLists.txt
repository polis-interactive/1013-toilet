cmake_minimum_required(VERSION 3.18)

set(SOURCES camera.cpp)
set(TARGET_LIBS pthread ${LIBCAMERA_LINK_LIBRARIES})

add_library(toilet_camera STATIC ${SOURCES})
target_link_libraries(toilet_camera PRIVATE ${TARGET_LIBS})