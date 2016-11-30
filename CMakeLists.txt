cmake_minimum_required(VERSION 3.6)
project(220TermProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Movie.cpp Stock.cpp)
add_executable(220TermProject ${SOURCE_FILES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})