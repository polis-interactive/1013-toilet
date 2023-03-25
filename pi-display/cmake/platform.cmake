
if (NOT DEFINED TOILET_PLATFORM)
    message(FATAL_ERROR "TOILET_PLATFORM unset" )
elseif (
    NOT TOILET_PLATFORM STREQUAL RPI
    AND NOT TOILET_PLATFORM STREQUAL BROOSE_LINUX_LAPTOP
)
    message(FATAL_ERROR "Unhandled TOILET_PLATFORM: ${TOILET_PLATFORM}" )
else()
    if (
        TOILET_PLATFORM STREQUAL RPI
    )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_RPI")
        set(BOOST_ROOT "/home/pi/build/boost_1_81_0")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_BROOSE")
        set(BOOST_ROOT "/usr/local/lib/boost_1_81_0")
    endif()

    set(BOOST_INCLUDEDIR  "${BOOST_ROOT}")
    set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")
    set(Boost_Version 1.81.0)
    set(Boost_NO_WARN_NEW_VERSIONS 1)
    set(BOOST_LINK_LIBRARIES Boost::system Boost::regex)
    find_package(Boost ${Boost_Version} REQUIRED COMPONENTS system regex)
    message(STATUS "boost library found:")
    message(STATUS "    version: ${Boost_Version}")
    message(STATUS "    libraries: ${BOOST_LINK_LIBRARIES}")
    message(STATUS "    include path: ${BOOST_INCLUDEDIR}")
    include_directories(${BOOST_INCLUDEDIR})

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBCAMERA REQUIRED libcamera)
    message(STATUS "libcamera library found:")
    message(STATUS "    version: ${LIBCAMERA_VERSION}")
    message(STATUS "    libraries: ${LIBCAMERA_LINK_LIBRARIES}")
    message(STATUS "    include path: ${LIBCAMERA_INCLUDE_DIRS}")
    include_directories(${LIBCAMERA_INCLUDE_DIRS})

    set(GLFW3_VERSION 3.3)
    set(GLFW3_LINK_LIBRARIES glfw3 EGL GL dl)
    find_package(glfw3 ${GLFW3_VERSION} CONFIG REQUIRED)
    message(STATUS "glfw3 library found:")
    message(STATUS "    version: ${GLFW3_VERSION}")
    message(STATUS "    libraries: ${GLFW3_LINK_LIBRARIES}")
    # no include dirs; is added by target glfw3

endif()
