cmake_minimum_required(VERSION 3.18)

set(SOURCES websocket.cpp)
set(TARGET_LIBS pthread)

add_library(toilet_websocket STATIC ${SOURCES})
target_link_libraries(toilet_websocket PRIVATE ${TARGET_LIBS} ${BOOST_LINK_LIBRARIES})