cmake_minimum_required(VERSION 3.18)

set(GLAD_DIR ${third_party_dir}/glad)

set(SOURCES graphics.cpp ${GLAD_DIR}/src/glad.c ${GLAD_DIR}/src/glad_egl.c)
set(TARGET_LIBS pthread ${GLFW3_LINK_LIBRARIES})

add_library(toilet_graphics STATIC ${SOURCES})
target_link_libraries(toilet_graphics PRIVATE ${TARGET_LIBS})

