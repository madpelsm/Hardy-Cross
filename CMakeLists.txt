cmake_minimum_required(VERSION 2.6)
project(HardyCross)
cmake_policy(SET CMP0054 NEW)


if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-variable")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()


if (WIN32)
    # Please don't define min() and max() macros, Windows
    add_definitions(-DNOMINMAX)
endif()


file(GLOB PIPES_SRC_FILES "./src/*.cpp")
file(GLOB PIPES_HDR_FILES "./src/*.hpp")


add_executable(HardyCross ${PIPES_SRC_FILES} ${PIPES_HDR_FILES})

